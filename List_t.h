##include "Node_t.h"

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
		Node_t* prev_node = first;
		int i = 0;
		if(!(node->next))
            delete node;

		else{
                while(node->next){
                    i++;
                    node = node-> next;
                }
                while(i-1){
                    i--;
                    prev_node = prev_node -> next;
                }
                prev_node->next = 0;
                delete node;
		}
		//TODO: Need to implement: delete last element is the list
	};

	void insert(int pos, int val)
	{
		Node_t* prev_node = first;
		Node_t* next_node = first;

		for(int i = 0; i < pos - 1; i++){
            prev_node = prev_node->next;
            next_node = next_node->next;
		}
		prev_node->next = new Node_t(val);

		next_node = next_node->next;

		prev_node->next->next = next_node;

		//TODO: Need to implement:  insert new element before the element at the specified position
	}

	int size()
	{
	    int size_list = 0;
	    Node_t* node = first;
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
		if(pos == 0){
                first = next_node->next;
                delete del_node;
		}
		else{
            if(pos == 1){
            del_node = del_node->next;

            next_node = next_node -> next;
            next_node = next_node -> next;
            prev_node->next = next_node;

            delete del_node;



		}

		else {
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
		}
    }   //TODO: Need to implement: delete the element at the specified position
	}

	int clear()
	{
        int len = size();
        Node_t* node = first;
        for(int i = 0; i < len ; i++){
            pop_back();
        }

        //TODO: Need to implement: delete all elements from the list
	}

	int sort()
	{
		return 0;//TODO: Need to implement: Sort element in the list by ascending order
		//NOTE: It is really easy to do, if you have implemented push_back(), insert(), size(), and erase()
	}

	int reverse()
	{
		int len = size();
		Node_t* node = first;
		Node_t* last;

		for(int i = len; i > 0; i--){
            insert(i - 1, node->value);
            node = node -> next;
            erase(0);
		}

		//TODO: Need to implement: Reverse links between elements in the list
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
