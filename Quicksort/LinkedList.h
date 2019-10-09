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

	~LinkedList()
	{
		while (tail != head)
		{
			tail = tail->getPrevious();
			delete tail->getNext();
		}
		delete tail;
		delete head;
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
		Node holder;
		int i = low - 1;

		for (int j = low; j <= high; j++)
		{
			cout << "Comparing: " << get(j)->val() << " with " << pivot->val() << endl;
			if (get(j) < pivot)
			{
				cout << "They're not right" << endl;
				i++;
				holder = *get(j);

				//swap
				if (get(i)->getPrevious() != nullptr)
					get(i)->getPrevious()->setNext(get(j));
				if (get(i)->getNext() != nullptr)
					get(i)->getNext()->setPrevious(get(j));
				if (holder.getPrevious() != nullptr)
					get(j)->getPrevious()->setNext(get(i));
				if (holder.getNext() != nullptr)
					get(j)->getNext()->setPrevious(get(i));

				get(j)->setNext(get(i)->getNext());
				get(j)->setPrevious(get(i)->getPrevious());
				get(i)->setNext(holder.getNext());
				get(i)->setPrevious(holder.getPrevious());

				if (get(j) == tail) tail = get(i);
				else if (get(i) == tail) tail = get(j);
				if (get(j) == head) head = get(i);
				else if (get(i) == head) head = get(j);
			}
		}
		//swap
		if (get(i+1)->getPrevious() != nullptr)
			get(i+1)->getPrevious()->setNext(pivot);
		if (get(i+1)->getNext() != nullptr)
			get(i+1)->getNext()->setPrevious(pivot);
		if (pivot->getPrevious() != nullptr)
			pivot->getPrevious()->setNext(get(i+1));
		if (pivot->getNext() != nullptr)
			pivot->getNext()->setPrevious(get(i+1));

		holder = *get(i+1);
		get(i+1)->setNext(pivot->getNext());
		get(i+1)->setPrevious(pivot->getPrevious());
		pivot->setNext(holder.getNext());
		pivot->setPrevious(holder.getPrevious());

		if (get(i+1) == tail) tail = pivot;
		else if (pivot == tail) tail = get(i+1);
		if (get(i+1) == head) head = pivot;
		else if (pivot == head) head = get(i+1);

		cout << "Giving back " << i + 1 << endl;
		return (i + 1);
	}
};
