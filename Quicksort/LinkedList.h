#include "Node.h"

class LinkedList
{
	Node * head;
	Node * tail;
	int size;

public:

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	LinkedList(Node * item)
	{
		head = item;
		tail = item;
		size = 1;
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
		size++;
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

		size++;
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

	int const length() { return size; }

	Node * get(const int index)
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
			return target;
		}
		catch (const out_of_range& message)
		{
			cerr << "Error: " << message.what() << " -- I'll give you the tail instead" << endl;
			return target;
		}
	}

	Node& operator[](const int index)
	{
		return *get(index);
	}

	void sort()
	{
		quickSort(this, 0, size - 1);
	}

private:
	void quickSort(LinkedList * list, int low, int high)
	{
		if (low < high)
		{
			int pi = partition(list, low, high);

			quickSort(list, low, pi - 1);
			quickSort(list, pi + 1, high);

		}
	}

	int partition(LinkedList * list, int low, int high)
	{
		Node * pivot = get(high);
		int i = low - 1;

		for (int j = low; j <= high; j++)
		{
			cout << "Comparing: " << get(j)->val() << " with " << pivot->val() << endl;
			if (get(j) < pivot)
			{
				cout << "They're not right" << endl;
				i++;
				//swap (TODO - swap neighbor data)
				Node holder = *get(j);
				get(j)->setNext(pivot->getNext());
				get(j)->setPrevious(pivot->getPrevious());
				pivot->setNext(holder.getNext());
				pivot->setPrevious(holder.getPrevious());
			}
		}
		//swap
		Node holder = *get(i+1);
		get(i+1)->setNext(get(high)->getNext());
		get(i+1)->setPrevious(get(high)->getPrevious());
		get(high)->setNext(holder.getNext());
		get(high)->setPrevious(holder.getPrevious());

		cout << "Giving back " << i + 1 << endl;
		return (i + 1);
	}
};
