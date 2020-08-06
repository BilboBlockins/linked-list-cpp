/*
Brett Hiebert
LinkedListTest
Description: This is a test program for the LinkedList and Node classes. It imports different data types into the linked list data structure and tests various LinkedList member functions.
2018
*/

//INCLUDE LINKEDLIST AND DATA TYPES TO TEST
#include <iostream>
#include <string>
#include "Field.h"
#include "DateTime.h"
#include "LinkedList.h"

int main()
{
//DECLARE DIFFERENT LINKEDLIST TYPES
	LinkedList<DateTime> dateTimeList;
	LinkedList<Field> fieldList;
	LinkedList<std::string> stringList;
	LinkedList<double> doubleList;
	LinkedList<int> intList;

//INTS (TESTS FOR INT LINKEDLIST)
	std::cout << "INTS" << std::endl;
	std::cout << "===========================================" << std::endl; // divider for int type

	intList.readFile("intTest.dat"); // load data

	std::cout << "There are " << intList.getSize() << " nodes." << std::endl; // count initial nodes
	std::cout << "There is " << intList.countItems(3) << " 3" << std::endl; // count initial item number in list
	std::cout << "===========================================" << std::endl;
	intList.printAll(); // print all the initial data
	std::cout << std::endl;

	intList.writeFile("intTest.dat"); // rewrite the data back to the file (so initial data for testing remains the same)

	intList.add(3); // add some duplicate data
	intList.add(3);
	intList.add(3);

	intList.addAscending(6); // add some data ascending - 6 will be placed before nodes bigger than it but after nodes smaller (will be at end)
	intList.addDescending(6); // add some data descending - 6 will be placed before nodes smaller than it but after nodes bigger (will be at beginning)

	std::cout << "There are " << intList.getSize() << " nodes." << std::endl; // get and print the list size again.
	std::cout << "There are " << intList.countItems(3) << " 3s" << std::endl;
	std::cout << "===========================================" << std::endl;
	intList.printAll();
	std::cout << std::endl;

	intList.removeAllDuplicates(); // remove all the duplicate nodes (1 6 and 3 3s will be deleted)
	intList.removeByItem(6); // remove the other 6
	intList.insert(3, 4); // insert the missing 4

	std::cout << "There are " << intList.getSize() << " nodes." << std::endl; // get and print the list size again.
	std::cout << "There is " << intList.countItems(3) << " 3" << std::endl;
	std::cout << "===========================================" << std::endl;
	intList.printAll(); // should be 1-5

	std::cout << "\n" << std::endl;

//DOUBLES - Same pattern as above but with doubles
	std::cout << "DOUBLES" << std::endl;
	std::cout << "===========================================" << std::endl;

	doubleList.readFile("doubleTest.dat");

	std::cout << "There are " << doubleList.getSize() << " nodes." << std::endl;
	std::cout << "There is " << doubleList.countItems(3.3) << " 3.3" << std::endl;
	std::cout << "===========================================" << std::endl;
	doubleList.printAll();
	std::cout << std::endl;

	doubleList.writeFile("doubleTest.dat");

	doubleList.add(3.3);
	doubleList.add(3.3);
	doubleList.add(3.3);

	doubleList.addAscending(6.6);
	doubleList.addDescending(6.6);

	std::cout << "There are " << doubleList.getSize() << " nodes." << std::endl;
	std::cout << "There are " << doubleList.countItems(3.3) << " 3.3s" << std::endl;
	std::cout << "===========================================" << std::endl;
	doubleList.printAll();
	std::cout << std::endl;

	doubleList.removeAllDuplicates();
	doubleList.removeByItem(6.6);
	doubleList.insert(3.3, 4.4);

	std::cout << "There are " << doubleList.getSize() << " nodes." << std::endl;
	std::cout << "There is " << doubleList.countItems(3.3) << " 3.3" << std::endl;
	std::cout << "===========================================" << std::endl;
	doubleList.printAll();

	std::cout << "\n" << std::endl;

//STRINGS - Same pattern as above but with strings. Note: String > < operators check for string length so addAscending and addDescending organize by string length.
	std::cout << "STRINGS" << std::endl;
	std::cout << "===========================================" << std::endl;

	stringList.readFile("stringTest.dat");

	std::cout << "There are " << stringList.getSize() << " nodes." << std::endl;
	std::cout << "There is " << stringList.countItems("Three") << " Three" << std::endl;
	std::cout << "===========================================" << std::endl;
	stringList.printAll();
	std::cout << std::endl;

	stringList.writeFile("stringTest.dat");

	stringList.add("Three");
	stringList.add("Three");
	stringList.add("Three");

	stringList.addAscending("Six"); // Note string size is based on length of string.
	stringList.addDescending("Six");

	std::cout << "There are " << stringList.getSize() << " nodes." << std::endl;
	std::cout << "There are " << stringList.countItems("Three") << " Threes" << std::endl;
	std::cout << "===========================================" << std::endl;
	stringList.printAll();
	std::cout << std::endl;

	stringList.removeAllDuplicates();
	stringList.removeByItem("Six");
	stringList.insert("Three", "Four");

	std::cout << "There are " << stringList.getSize() << " nodes." << std::endl;
	std::cout << "There is " << stringList.countItems("Three") << " Three" << std::endl;
	std::cout << "===========================================" << std::endl;
	stringList.printAll(); // result should still be "One" - "Five"

	std::cout << "\n" << std::endl;

//FIELDS - Simple check that the data type works. Different than strings because comma delimited (must include "," delimiter in writeFile);
	std::cout << "FIELDS" << std::endl;
	std::cout << "===========================================" << std::endl;

	fieldList.readFile("fieldTest.dat"); // field is delimited by commas so it is ok to have spaces in the data.

	fieldList.writeFile("fieldTest.dat", ","); // comma delimiter is used when writing fields

	fieldList.insert("Field Three", "Field Four"); // otherwise, this works the same as string

	fieldList.printAll(); // Should be "Field One" - "Field Five"

	std::cout << "\n" << std::endl;

//DATETIME - Simple check that the data type works.
	std::cout << "DATETIME" << std::endl;
	std::cout << "===========================================" << std::endl;

	DateTime d3(11, 3, 2018); // create some datetime instances
	DateTime d4(11, 4, 2018);
	DateTime d5(11, 5, 2018);

	dateTimeList.readFile("dateTimeTest.dat"); // d1 and d2 come from the data file

	dateTimeList.writeFile("dateTimeTest.dat"); // write file so initial data doesn't change

	//Note: With addAscending() (or descending) the dates can be added in random order and will be arranging correctly since >< operators are defined in the DateTime class
	dateTimeList.addAscending(d3);
	dateTimeList.addAscending(d5);
	dateTimeList.addAscending(d4);

	dateTimeList.printAll();

	std::cin.get(); // wait for key
	return 0;
}
