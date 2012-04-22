#include <iostream>
#include "SetHolder.h"

SetHolder::SetHolder(int size)
{
	mSize = size;
	mArray = new Itemset*[mSize];
	for(int i = 0; i < mSize; i++)
	{
		mArray[i] = NULL;
	}
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
		Itemset** tmpArr = new Itemset*[mSize];
		for(int i = 0; i < mSize; i++)
		{
			tmpArr[i] = NULL;
		}
		for(int i = 0; i < oldSize; i++)
		{
			tmpArr[i] = mArray[i];
		}
		delete [] mArray;
		mArray = tmpArr;
	}
	mArray[mIndex] = itemset;
	mIndex++;
}

void SetHolder::displayAll()
{
	for(short i = 0; i < mIndex; i++)
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

Itemset* SetHolder::get(short index)
{
	if(index < mSize)
	{
		return mArray[index];
	}
	else
	{
		return NULL;
	}
}

bool SetHolder::inSetHolder(int item)
{
	for(int i = 0; i < mSize; i++)
	{
		if(mArray[i] == NULL)
		{
			continue;
		}
		if(mArray[i]->inItemset(item))
		{
			return true;
		}
	}
	return false;
}

short SetHolder::remove(short index)
{
	if(index > mIndex)
	{
		return index;
	}
	delete mArray[index];
	for(int i = index; i < mSize; i++)
	{
		if(i + 1 == mSize)
		{
			continue;
		}
		mArray[i] = mArray[i + 1];
	}
	mIndex--;
	return index - 1;
}

void SetHolder::clear()
{
	delete[] mArray;
	mArray = new Itemset*[30];
	mIndex = 0;
	mSize = 30;
}