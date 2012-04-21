#pragma once

class Itemset
{
public:
	Itemset();
	Itemset(int size);
	~Itemset();
	bool inItemset(int item);
	bool isEmpty();
	void add(int item);
	void displayAll();
private:
	short *mItemArray;
	int mArrSize;
	int mIndex;
};