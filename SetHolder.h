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
	short size() { return mIndex; }
	bool isEmpty();
	Itemset* get(short index);
	bool inSetHolder(int item);
	short remove(short index);
private:
	Itemset** mArray;
	short mSize;
	short mIndex;
};