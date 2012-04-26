#include <iostream>
#include "Itemset.h"
#include "SetHolder.h"
#include "DataLoader.h"
#include "TimerSystem.h"

#define MINSUP 0.0025

bool checkApriori(Itemset* candidate, SetHolder* frequentItems)
{
	bool isFrequent = false;
	int offset = 0;
	for(int i = 0; i < candidate->size(); i++)
	{
		isFrequent = false;
		Itemset* tempSet = new Itemset(2);
		tempSet->add(candidate->get(0 + offset));
		tempSet->add(candidate->get(i + 1 - offset)); //checks [0,1], [0,2], [1,2]
		if(i >= 1)
			offset = 1;
		for(int j = frequentItems->getSetStart(2); j < frequentItems->size(); j++)
		{
			if(tempSet->get(0) == frequentItems->get(j)->get(0) && tempSet->get(1) == frequentItems->get(j)->get(1))
			{
				isFrequent = true;
				break;
			}
		}
		delete tempSet;
		if(!isFrequent)
		{
			return true;
		}
	}
	return false;
}

bool prune(SetHolder* tranArr, Itemset* kSet, int transactionCount)
{
	int count = 0;
	int number = -1; // DEBUG
	for(int i = 0; i < tranArr->size(); i++)
	{
		Itemset* transaction = tranArr->get(i);
		if(transaction != NULL)
		{
			bool allGood = true;
			for(int j = 0; j < kSet->size(); j++)
			{
				number = kSet->get(j);
				if(!transaction->inItemset(kSet->get(j)))
				{
					allGood = false;
				}
			}
			if(allGood)
			{
				count++;
			}
		}
	}
	double support = (double)count / (double)transactionCount;
	//cout << number << ": " << support << endl;
	if(support >= MINSUP)
	{
		return false;
	}
	return true;
}

int main()
{
	TimerSystem timer;
	int transactionNum = 0;
	ofstream fout("Logger.dat");
	{
		int itemNum;
		ifstream fin("dataset/T5.N0.5K.D2K.ibm.input"); // T5.N0.5K.D2K.ibm
		fin >> itemNum;
		fin >> transactionNum;
		fin.close();
	}
	SetHolder tranArr(transactionNum);
	//Itemset** tranArr = new Itemset*[transactionNum];
	DataLoader dataLoader("dataset/T5.N0.5K.D2K.ibm.dat");
	for(int i = 0; i < transactionNum; i++)
	{
		tranArr.add(dataLoader.readLine());
	}
	//tranArr.displayAll();

	//APRIORI
	SetHolder frequentItems(75);

	SetHolder candidates(50);
	int k = 1;
	timer.startClock();
	do
	{
		if(k == 1)
		{
			std::cout << "Commencing 1-itemsets." << endl;
			for(int i = 0; i < tranArr.size(); i++)
			{
				Itemset* transaction = tranArr.get(i);
				if(transaction == NULL)
				{
					continue;
				}
				for(int j = 0; j < transaction->size(); j++)
				{
					short num = transaction->get(j);
					if(num == -1)
					{
						continue;
					}
					if(!candidates.inSetHolder(num))
					{
						Itemset* newSet = new Itemset(1);
						newSet->add(transaction->get(j));
						candidates.add(newSet);
					}
				}
			}
			std::cout << "Pruning 1-itemsets." << endl;
			for(int i = 0; i < candidates.size(); i++)
			{
				if(prune(&tranArr, candidates.get(i), transactionNum))
				{
					i = candidates.remove(i);
				}
			}
		}
		else if(k == 2)
		{
			std::cout << "Commencing 2-itemsets." << endl;
			for(int i = 0; i < frequentItems.size(); i++)
			{
				for (int j = i + 1; j < frequentItems.size(); j++)
				{
					Itemset* newSet = new Itemset(k);
					newSet->add(frequentItems.get(i)->get(0));
					newSet->add(frequentItems.get(j)->get(0));
					candidates.add(newSet);
				}
			}
			//break;//DEBUG
			std::cout << "Pruning 2-itemsets." << endl;
			for(int i = 0; i < candidates.size(); i++)
			{
				if(prune(&tranArr, candidates.get(i), transactionNum))
				{
					i = candidates.remove(i);
				}
			}
			//break;
		}
		else
		{
			std::cout << "Commencing " << k << "-itemsets." << endl;
			for(int i = frequentItems.getSetStart(k - 1); i <frequentItems.size(); i++)
			{
				if(i == 0) // Check if getSetStart returned nothing. This will never be 0
				{
					break;
				}
				Itemset* tran1 = frequentItems.get(i);
				for(int j = i + 1; j < frequentItems.size(); j++)
				{
					Itemset* tran2 = frequentItems.get(j);
					bool allGood = true;
					for(int kit = 0; kit < tran1->size() - 1; kit++)
					{
						if(tran1->get(kit) != tran2->get(kit))
						{
							allGood = false;
							break;
						}
					}
					if(allGood)
					{
						Itemset* newSet = new Itemset(k);
						for(int it = 0; it < tran1->size() - 1; it++)
						{
							newSet->add(tran1->get(it));
						}
						newSet->add(tran1->get(tran1->size() - 1));
						newSet->add(tran2->get(tran2->size() - 1));
						candidates.add(newSet);
					}
				}
			}
			std::cout << "Pruning " << k << "-itemsets." << endl;
			for(int i = 0; i < candidates.size(); i++)
			{
				if(candidates.isEmpty())
				{
					break;
				}
				if(prune(&tranArr, candidates.get(i), transactionNum))
				{
					i = candidates.remove(i);
				}
			}
			//candidates.displayAll();
			/*
			for(int i = 0; i < candidates.size(); i++)
			{
				if(checkApriori(candidates.get(i), &frequentItems))
				{
					i = candidates.remove(i);
				}
			}
			*/
		}
		//frequentItems.clear();
		for (int i = 0; i < candidates.size(); i++)
		{
			frequentItems.add(candidates.get(i));
		}
		double time = timer.getTime();

		fout << "K = " << k << endl;
		fout << "Total Datasets: " << frequentItems.size() - frequentItems.getSetStart(k) << endl;
		fout << "Time Taken: " << time << endl;
		for(int i = frequentItems.getSetStart(k); i < frequentItems.size(); i++)
		{
			for(int j = 0; j < frequentItems.get(i)->size(); j++)
			{
				fout << frequentItems.get(i)->get(j) << ", ";
			}
			fout << endl;
		}
		fout << endl;
		if(candidates.size() == 0)
		{
			break;
		}

		candidates.clear();
		k++;
		timer.startClock();
	} while (!candidates.isEmpty());
	std::cout << timer.getTime() << endl;
	candidates.displayAll();
	frequentItems.displayAll();
	//frequentItems.deleteData();
	// Pause
	fout.close();
	std::cout << "Done.";
	std::cin.get();
}