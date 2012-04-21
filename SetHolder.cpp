#include <iostream>
#include "SetHolder.h"

SetHolder::SetHolder(int size)
{
	mSize = size;
	mArray = new Itemset*[mSize];
	mIndex = 0;
}

SetHolder::~SetHolder()
{
	delete [] mArray;
}

void SetHolder::deleteData()
{
	for(short i = 0; i < mSize; i++)
	{
		delete [] mArray[i];
	}
}

void SetHolder::add(Itemset* itemset)
{
	if(mIndex == mSize)
	{
		short oldSize = mSize;
		mSize = ceil(mSize * 1.5);
		delete [] mArray;
		mArray = new Itemset*[mSize];
	}
	mArray[mIndex] = itemset;
	mIndex++;
}

void SetHolder::displayAll()
{
	for(short i = 0; i < mSize; i++)
	{
		mArray[i]->displayAll();
		std::cout << std::endl;
	}
}

bool SetHolder::isEmpty()
{
	if(mSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}