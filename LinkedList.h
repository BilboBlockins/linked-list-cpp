/*
Brett Hiebert
LinkedList.h
LinkedList Template Class Declaration
Data Members: LinkedList has pointer headPtr, tailPtr, and a size_t nodeNum to keep track of the list size.
09/29/2018
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string> // Note: Needed here for fileName in tem
#include <fstream>
#include "Node.h" // Note: Node is a friend class - LinkedList can access Node private members

//LINKEDLIST CLASS
template <class Item>
class LinkedList
{
public:
	//DEFAULT CONSTRUCTOR
	LinkedList();

	//COPY CONSTRUCTOR
	LinkedList(const LinkedList& source); //deep copies all the data from one list to the newly create one

	//DESTRUCTOR
	~LinkedList(); // calls free to clear all the nodes

	//ASIGNMENT OPERATOR
	void operator =(const LinkedList& source); // assignment overload for deep copy of list data.

	//SETTERS (MODIFICATION MEMBER FUNCTIONS)
	void add(const Item& entry); //adds a node to the list - O(1)
	void addAtHead(const Item& entry);
	void insert(const Item& entryAfter, const Item& entry); // adds an item after the specified first entry - O(1)
	bool removeByItem(const Item& target); // removes a specific item - calls find so efficiency is O(n)
	void clear(); // public function to empty the list - O(n)

	//GETTERS
	std::size_t countItems(const Item& target) const; // will count all instances of target item - O(n)
	std::size_t getSize() const { return nodeNum; } // by keeping track of the list size as it is being created we can return list size with O(1) (more efficient) 
	void printAll(); // prints all list items - O(n);

	//OTHER MEMBER FUNCTIONS
	void readFile(std::string fileName);
	void writeFile(std::string fileName, std::string delim = " ");

	void removeAllDuplicates(); // removes any duplicate nodes - efficiency is not great O(n^2) (could do better if list was sorted - i.e. mergeSort and/or by tracking dupes on entry)
	void addAscending(const Item& entry); // adds an item in ascending order - O(n)
	void addDescending(const Item& entry); // adds an item in descending order - O(n)

private:
	Node<Item>* headPtr; // points at head node
	Node<Item>* tailPtr; // points at tail node
	std::size_t nodeNum; // keeps track of list size

	void free();
	Node<Item>* find(const Item& target); // finds target - O(n)
	Node<Item>* findPrevious(const Item& target); // finds the nodeptr previous to the target - O(n)
};

#include "LinkedList.tem" // contains template implementation

#endif


