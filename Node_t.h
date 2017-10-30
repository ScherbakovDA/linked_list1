#include "Node_t.h"

struct List_t
{
	Node_t* first;

	List_t(int val);
	~List_t();

	void push_back(int val);
	void print();

	void pop_back()
	{
		Node_t* node = first;
		while(node->next){
            node = node-> next;
		}
		delete node;
		//TODO: Need to implement: delete last element is the list
	};

	void insert(int pos, int val)
	{
		Node_t* prev_node = first;
		Node_t* next_node = first;

		for(int i = 0; i < pos; i++){
            prev_node = prev_node->next;
            next_node = next_node->next;
		}
		Node_t* new_node = new Node_t(val);

		prev_node->next = new_node;

		next_node = next_node->next;

		new_node->next = next_node;

		//TODO: Need to implement:  insert new element before the element at the specified position
	}

	int size()
	{
	    int size_list = 0;
	    Node_t* node;
	    while(node){
            size_list++;
            node = node->next;
	    }
	    return size_list;
		//TODO: Need to implement: return list size
	}

	void erase(int pos)
	{
		Node_t* del_node = first;
		Node_t* prev_node = first;
		Node_t* next_node = first;
		if(pos == 1){
            del_node = del_node->next;

            next_node = next_node -> next;
            next_node = next_node -> next;
            prev_node->next = next_node;

            delete del_node;

            return;

		}

		for(int i = 0; i < pos - 1; i++){
            del_node = del_node-> next;
            prev_node = prev_node -> next;
            next_node = next_node -> next;
		}

		del_node = del_node-> next;
		next_node = next_node -> next;
		next_node = next_node -> next;

		prev_node->next = next_node;

		delete del_node;

		//TODO: Need to implement: delete the element at the specified position
	}

	int clear()
	{
		return 0;//TODO: Need to implement: delete all elements from the list
	}

	int sort()
	{
		return 0;//TODO: Need to implement: Sort element in the list by ascending order
		//NOTE: It is really easy to do, if you have implemented push_back(), insert(), size(), and erase()
	}

	int reverse()
	{
		return 0;//TODO: Need to implement: Reverse links between elements in the list
	}
};

List_t::List_t(int val)
{
	first = new Node_t(val);
}

List_t::~List_t()
{
	delete first;
}

void List_t::push_back(int val)
{
	Node_t* node = first;

	while(node -> next)
	{
		node = node -> next;
	}

	node -> next = new Node_t(val);
}

void List_t::print()
{
	Node_t* node = first;

	std::cout << "[";

	while(node)
	{
		std::cout << '\'' << node -> value << '\'';
		node = node -> next;
		if (node)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]\n";
}
