#include "Node.h"

class LinkedList
{
	Node * head;
	Node * tail;

public:

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	LinkedList(Node * item)
	{
		head = item;
		tail = item;
	}

	void push(Node * item)
	{
		if (head == nullptr)
		{
			head = item;
			tail = item;
		}
		else
		{
			tail->setNext(item);
			item->setPrevious(tail);
			tail = item;
		}
	}

	void insert(Node * item, int index)
	{
		Node * target = head;
		for (int i = 0; i < index; i++)
		{
			target = target->getNext();
		}
		target->getPrevious()->setNext(item);
		item->setNext(target);
		target->setPrevious(item);
	}

	void const print()
	{
		Node * target = head;
		int i = 0;
		while (target != nullptr)
		{
			cout << i++ << ": " << target->val() << endl;
			target = target->getNext();
		}
	}

	Node& operator[](const int index)
	{
		Node * target = head;
		try
		{
			for (int i = 0; i < index; i++)
			{
				if (target->getNext() == nullptr)
					throw out_of_range("Index is out of range");
				target = target->getNext();
			}
			return *target;
		}
		catch (const out_of_range& message)
		{
			cerr << "Error: " << message.what() << " -- I'll give you the tail instead" << endl;
			return *target;
		}
	}

	void sort()
	{

	}

	void quickSort(LinkedList list, int low, int high)
	{
		if (low < high)
		{
			//auto pi = partition(list, low, high);

			//quickSort(list, low, pi - 1);
			//quickSort(list, pi + 1, high);

		}
	}

	void partition(LinkedList list, int low, int high)
	{

	}
};
