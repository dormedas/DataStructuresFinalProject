#include <iostream>
#include "Itemset.h"
#include "DataLoader.h"

int main()
{
	Itemset* tranArr[10];
	DataLoader dataLoader("dataset/T5.N0.5K.D2K.ibm.dat");
	for(int i = 0; i < 10; i++)
	{
		tranArr[i] = dataLoader.readLine();
	}
	for(int i = 0; i < 10; i++)
	{
		tranArr[i]->displayAll();
		cout << endl;
	}
	/*
	Itemset set(5);
	set.add(4);
	set.add(3);
	set.displayAll();
	*/

	// Pause
	std::cin.get();
}