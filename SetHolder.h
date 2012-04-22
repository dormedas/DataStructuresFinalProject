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
	int size() { return mIndex; }
	bool isEmpty();
	Itemset* get(int index);
	bool inSetHolder(int item);
	int remove(int index);
	void clear();
private:
	Itemset** mArray;
	int mSize;
	int mIndex;
};