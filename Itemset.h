#pragma once

class Itemset
{
public:
	Itemset(int size);
	~Itemset();
	bool inItemset(int transaction);
	void add(int transaction);
	void displayAll();
private:
	int *mTransactionArray;
	int mArrSize;
	int mIndex;
};