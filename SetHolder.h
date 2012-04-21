#pragma once

#include "Itemset.h"

class SetHolder
{
public:
	SetHolder(int size = 30);
	~SetHolder();
	void deleteData();
	void add(Itemset* itemset);
	void displayAll();
	short size() { return mSize; }
	bool isEmpty();
private:
	Itemset** mArray;
	short mSize;
	short mIndex;
};