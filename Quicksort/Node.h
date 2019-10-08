#include <iostream>

using namespace std;

class Node
{
	int value;
	Node* previous;
	Node* next;

public:
	Node()
	{
		previous = nullptr;
		next = nullptr;
	}

	Node(int val)
	{
		value = val;
		previous = nullptr;
		next = nullptr;
	}

	~Node()
	{
		delete previous;
		delete next;
	}

	void setPrevious(Node * p) { this->previous = p; }
	void setNext(Node * n) { this->next = n; }
	int val() const { return value; }

	Node * const getNext()
	{
		return this->next;
	}

	Node * const getPrevious()
	{
		return this->previous;
	}

	Node& operator++()
	{
		value++;
		return *this;
	}
	Node& operator--()
	{
		value--;
		return *this;
	}
	Node& operator=(const Node& other)
	{
		this->value = other.val();
		return *this;
	}
	Node& operator=(const int other)
	{
		this->value = other;
		return *this;
	}
};

bool operator<(const Node& leftnode, const Node& rightnode)
{ 
	return leftnode.val() < rightnode.val(); 
}
bool operator>(const Node& leftnode, const Node& rightnode)
{ 
	return leftnode.val() > rightnode.val();
}
bool operator==(const Node& leftnode, const Node& rightnode) 
{ 
	return leftnode.val() == rightnode.val(); 
}
bool operator!=(const Node& leftnode, const Node& rightnode) 
{ 
	return !(leftnode == rightnode); 
}
