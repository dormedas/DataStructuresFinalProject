#pragma once
#include <iostream>
#include <fstream>
#include "Itemset.h"

using namespace std;

class DataLoader
{
public:
	DataLoader();
	DataLoader(string fileName);
	~DataLoader();

	void openFile(string fileName);
	Itemset* readLine();
private:
	ifstream fin;
};

