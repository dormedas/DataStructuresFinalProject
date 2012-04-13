#include <iostream>
#include "Itemset.h"

Itemset::Itemset(int size)
{
	mArrSize = size;
	mTransactionArray = new int(mArrSize);
	mIndex = 0;
}


Itemset::~Itemset()
{
}

// 

bool Itemset::inItemset(int transaction)
{
	for(int i = 0; i < mArrSize; i++)
	{
		if(mTransactionArray[i] == transaction)
			return true;
	}
	return false;
}

void Itemset::add(int transaction)
{
	if(mIndex <= mArrSize)
	{
		mTransactionArray[mIndex] = transaction;
		mIndex++;
	}
	else
	{
		throw 5; // Just tell us it failed.
	}
}

void Itemset::displayAll()
{
	for(int i = 0; i < mArrSize; i++)
	{
		std::cout << mTransactionArray[i];
		// Display comma except after last item
		if(i < mArrSize - 1)
			std::cout << ", ";
	}
}