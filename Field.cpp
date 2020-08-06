/*
Brett Hiebert
Field.cpp
09/29/2018
*/

//Note: Removed using namespace std & implemented strToUpper & strToLower

#include "Field.h"

Field::Field() // default  constructor
	: std::string()  // calls the string default constructor
{
	arraySize = 0;
}
Field::Field(const std::string& str)
	: std::string (str) // calls the string copy constructor
{
	arraySize = 0;
}
Field::Field(const char* cStr)
	: std::string (cStr)  // calls the constructor passes const char*
{
	arraySize = 0;
}

std::string * Field::split(char delimiter)
{
	int commaIndex = 0;
	arraySize = 1;
	std::string* tmpPtr = NULL;
	std::string tmp = *this;
	std::string* fields = new std::string[arraySize];
	int used = 0;

	commaIndex = this->find(delimiter);  // (*this).find(delimiter);
	do
	{
		if (used >= arraySize) // full - no more room
		{   // spiderman - memory allocation at runtime
			arraySize++;
			tmpPtr = new std::string[arraySize];
			for (int i = 0; i < used; i++)
				tmpPtr[i] = fields[i];
			//copy(fields, fields + used, tmpPtr);
			delete[] fields;
			fields = tmpPtr;
		}
		fields[used++] = tmp.substr(0, commaIndex);
		tmp = tmp.erase(0, commaIndex + 1);
		commaIndex = tmp.find(delimiter);
	} while (commaIndex != std::string::npos);

	return fields;
}

std::istream& operator>>(std::istream& is, Field & fld)
{
	// get everything up until the enter key is pressed
	if (is.peek() == '\n') // check to make sure a newline (enter key)
		is.ignore();     // from previous input cin >> ...; was not left
	getline(is, fld, '\n');
	return is;
}
std::ifstream& operator>>(std::ifstream& ifs, Field & fld)
{
	if (ifs.peek() == '\n')
		ifs.ignore();
	getline(ifs, fld, ',');
	return ifs;
}

void Field::strToUpper()
{
	std::string tmp = (*this); //Create a tmp variable to hold the contents of the field while manipulating it.

	for (unsigned int i = 0; i < tmp.length(); i++) //for each character...
	{
		tmp[i] = toupper(tmp[i]); //Convert to uppercase.
	}

	(*this) = tmp; //Set the contents of the field to the modified string.
}

void Field::strToLower() //Same as strToUpper logic but converts to lowercase characters
{
	std::string tmp = (*this);

	for (unsigned int i = 0; i < tmp.length(); i++)
	{
		tmp[i] = tolower(tmp[i]); //Convert to lowercase.
	}

	(*this) = tmp;
}
