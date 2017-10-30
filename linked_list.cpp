#include <iostream>
#include "List_t.h"

int main()
{
	List_t list = List_t(5);

	list.push_back(10);
	list.push_back(11);
	list.push_back(12);
	list.push_back(13);

	//list.pop_back();

    //list.insert(2,0);

    //list.erase(0);

    //list.pop_back();

    //list.reverse();

	list.print();
    int len = list.size();
	std::cout << "size: " << len << "\n";

	return 0;
}
