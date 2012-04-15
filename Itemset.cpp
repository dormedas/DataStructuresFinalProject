#include <iostream>
#include "Itemset.h"

Itemset::Itemset(int size)
{
	mArrSize = size;
	mItemArray = new int[mArrSize];
	mIndex = 0;
}

Itemset::~Itemset()
{
	delete [] mItemArray;
}

// 

bool Itemset::inItemset(int item)
{
	for(int i = 0; i < mArrSize; i++)
	{
		if(mItemArray[i] == item)
			return true;
	}
	return false;
}

void Itemset::add(int item)
{
	if(mIndex < mArrSize)
	{
		mItemArray[mIndex] = item;
		mIndex++;
	}
	else
	{
		throw 5; // Just tell us it failed.
	}
}

void Itemset::displayAll()
{
	for(int i = 0; i < mIndex; i++)
	{
		std::cout << mItemArray[i];
		// Display comma except after last item
		if(i < mIndex - 1)
			std::cout << ", ";
	}
}