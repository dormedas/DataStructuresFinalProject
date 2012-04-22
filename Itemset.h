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
	int size() { return mIndex; }
	int get(int index);
private:
	short *mItemArray;
	int mArrSize;
	int mIndex;
};