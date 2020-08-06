/*
Brett Hiebert
Node.h
Node Template Class Declaration/Implementation
Data Members: Node has a datafield and a next node pointer.
09/29/2018
*/

#ifndef NODE_H
#define NODE_H

//NODE CLASS
template <class Item>
class Node
{
public:
	//CONSTRUCTOR - Note: default args both initialize data and allow for input on creation
	Node(const Item& initData = Item(), Node<Item>* initPtr = nullptr)
		{ data = initData; next = initPtr;}

	//GETTERS
	Item& getData() { return data; }
	Node* getLink() { return next; }

	//CONST GETTERS
	const Item& getData() const { return data; }
	const Node* getLink() const { return next; }

	//SETTERS (MODIFICATION MEMBER FUCTIONS) - Note: Not really used in LinkedList since Node is a friend class
	void setData(const Item& newData) { data = newData; }
	void setLink(Node* newLink) { next = newLink; }

private:
	Item data; // stores the date
	Node* next; // points to the next node (or null)
	template <class I> friend class LinkedList; // LinkedList is a friend class of Node so LinkedList can accsess private members directly.	
}; 

// Note: The member functions are so small I decided to eliminate the .cpp file and do them inline for Node.
#endif
