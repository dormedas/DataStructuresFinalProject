#include <iostream>
#include "Itemset.h"
#include "SetHolder.h"
#include "DataLoader.h"

#define MINSUP 0.025

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
	int transactionNum = 0;
	{
		int itemNum;
		ifstream fin("dataset/test.input"); // T5.N0.5K.D2K.ibm
		fin >> itemNum;
		fin >> transactionNum;
		fin.close();
	}
	SetHolder tranArr(transactionNum);
	//Itemset** tranArr = new Itemset*[transactionNum];
	DataLoader dataLoader("dataset/test.dat");
	for(int i = 0; i < transactionNum; i++)
	{
		tranArr.add(dataLoader.readLine());
	}
	//tranArr.displayAll();

	//APRIORI
	SetHolder frequentItems(75);

	SetHolder candidates(50);
	int k = 1;
	do
	{
		if(k == 1)
		{
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
			break;//DEBUG
			for(int i = 0; i < candidates.size(); i++)
			{
				if(prune(&tranArr, candidates.get(i), transactionNum))
				{
					i = candidates.remove(i);
				}
			}
		}
		for (int i = 0; i < candidates.size(); i++)
		{
			frequentItems.add(candidates.get(i));
		}
		candidates.clear();
		//break; // DEBUG
		k++;
	} while (!candidates.isEmpty());

	candidates.displayAll();
	// Pause
	std::cin.get();
}