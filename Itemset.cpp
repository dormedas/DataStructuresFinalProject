#include <iostream>
#include "Itemset.h"

Itemset::Itemset()
{
	mArrSize = 10;
	mItemArray = new short[mArrSize];
	mIndex = 0;
}

Itemset::Itemset(int size)
{
	mArrSize = size;
	mItemArray = new short[mArrSize];
	mIndex = 0;
}

Itemset::~Itemset()
{
	delete [] mItemArray;
}

bool Itemset::inItemset(int item1, int item2)
{
	char count = 0;
	for(int i = 0; i < mIndex; i++)
	{
		if(mItemArray[i] == item1)
		{
			count++;
		}
		if(mItemArray[i] == item2)
		{
			count++;
		}
	}
	if(count == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Itemset::inItemset(int item)
{
	for(int i = 0; i < mIndex; i++)
	{
		if(mItemArray[i] == item)
			return true;
	}
	return false;
}

void Itemset::add(int item)
{
	if(mIndex >= mArrSize)
	{
		int oldSize = mArrSize;
		mArrSize = ceil(mArrSize * 1.05);
		short* tmpArr = new short[mArrSize];
		for(int i = 0; i < oldSize; i++)
		{
			tmpArr[i] = mItemArray[i];
		}
		delete[] mItemArray;
		mItemArray = tmpArr;
	}
	mItemArray[mIndex] = item;
	mIndex++;
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

bool Itemset::isEmpty()
{
	if(mIndex <= 0)
		return true;
	else
		return false;
}

int Itemset::get(int index)
{
	if(index < mArrSize)
	{
		return mItemArray[index];
	}
	else
	{
		return -1;
	}
}