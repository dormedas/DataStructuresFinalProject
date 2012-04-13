#include <iostream>
#include "Itemset.h"

int main()
{
	Itemset set(5);
	set.add(4);
	set.add(3);
	set.displayAll();

	// Pause
	std::cin.get();
}