/*
Brett Hiebert
Field.h
Field Class Declaration
Data Members:
A field inherits its data members from std::string.
09/29/2018
*/

//Note: Removed using namespace std & implemented strToUpper & strToLower

#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <fstream>   // ifstream
#include <iostream>  // istream

//Note: Removed "using namespace std" for consistency.

// Field (sub) is a string (super)
class Field : public std::string
{
public:
	// constructors
	Field(); // default  constructor: Field address;
	Field(const std::string& str);
	Field(const char* cStr); 

	// new features of child
	std::string* split(char delimiter = ',');

	void strToUpper(); //Note: Changes the string stored inside the field to all uppercase characters
	void strToLower();//Note: Changes the string stored inside the field to all lowercase characters

	int getArraySize() const { return arraySize; }
private:
	int arraySize;
	// nothing here - no new data 
	// inherits the data from string
};

std::istream& operator>>(std::istream& is, Field & fld);
std::ifstream& operator>>(std::ifstream& ifs, Field & fld);

#endif
