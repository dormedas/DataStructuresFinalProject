#pragma once
class Itemset
{
public:
	Itemset(int size);
	~Itemset();
private:
	int *transactionArray;
};