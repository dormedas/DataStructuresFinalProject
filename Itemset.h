#pragma once

class Itemset
{
public:
	Itemset(int size);
	~Itemset();
	bool inItemset(int item);
	void add(int item);
	void displayAll();
private:
	int *mItemArray;
	int mArrSize;
	int mIndex;
};