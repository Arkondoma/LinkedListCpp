#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;

	list.push(new Node(1));
	list.push(new Node(4));
	list.push(new Node(2));
	list.push(new Node(5));
	list.insert(new Node(3), 2);
	
	// Should print 1, 4, 3, 2, 5, 3, error (5), 5
	list.print();
	cout << list[2].val() << endl;
	cout << list[6].val() << endl;
	cout << list.length() << endl;

	cout << endl << " -- Sorting -- " << endl << endl;

	list.sort();
	list.print();
}
