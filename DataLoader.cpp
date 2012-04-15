#include "DataLoader.h"

DataLoader::DataLoader()
{
}

DataLoader::DataLoader(string fileName)
{
	fin.open(fileName.c_str());
}

DataLoader::~DataLoader()
{
}

void DataLoader::openFile(string fileName)
{
	if(fin.is_open())
		fin.close();
	fin.open(fileName.c_str());
}

Itemset* DataLoader::readLine()
{
	if(!fin.is_open())
		return NULL;
	//char line[256], num[5];
	//fin.getline(line, 256);
	streampos pos = fin.tellg();
	int commaCount = 0;
	while(fin.peek() != '\n')
	{
		if(fin.get() == ',')
			commaCount++;
	}
	Itemset* tmp = new Itemset(commaCount + 1);
	fin.seekg(pos);
	int x = 0;
	while(fin.peek() != '\n')
	{
		fin >> x;
		//cout << x;
		tmp->add(x);
		if(fin.peek() == ',')
		{
			fin.get();
			fin.get();
		}
	}
	fin.get();
	return tmp; 
}