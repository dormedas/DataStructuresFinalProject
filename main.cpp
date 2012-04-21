#include <iostream>
#include "Itemset.h"
#include "SetHolder.h"
#include "DataLoader.h"

int main()
{
	int transactionNum = 0;
	{
		int itemNum;
		ifstream fin("dataset/T5.N0.5K.D2K.ibm.input");
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
	tranArr.displayAll();

	//APRIORI
	SetHolder frequentItems(75);

	SetHolder candidates(50);
	int k = 1;
	do
	{
		if(k == 1)
		{
			for(int i = 0; i < transactionNum; i++)
			{
				//Itemset* transaction = tranArr[i];

			}
		}
		k++;
	} while (!candidates.isEmpty());
	// Pause
	std::cin.get();
}