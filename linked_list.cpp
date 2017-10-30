#include "List_t.h"

int main()
{
	List_t list = List_t(11);

	list.push_back(7);
	list.push_back(5);
	list.push_back(13);
	list.push_back(10);

	//list.pop_back();

    //list.insert(2,0);

    //list.erase(0);

    //list.pop_back();

    //list.reverse();

    list.sort();

	list.print();
    int len = list.size();
	std::cout << "size: " << len << "\n";

	return 0;
}
