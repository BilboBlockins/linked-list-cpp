/*
Brett Hiebert
DateTime.h
DateTime Class Declaration
Data Members:
A DateTime has integer month, day, year, hour, and minute as its (private) data members.
09/29/2018
*/

#ifndef DATETIME_H //macro guard
#define DATETIME_H

#include <iostream>
#include <string>
#include <fstream>

class DateTime
{
public:
	//DEFAULT CONSTRUCTOR
	DateTime(); // NOTE: CONSTRUCTORS HAVE NO RETURN TYPES

	//3 OTHER CONSTRUCTORS THAT TAKE PARAMETERS (CONSTRUCTOR OVERLOADING)
	DateTime(int monthIn, int dayIn, int yearIn); // Note: Can add default values in constructor definition (i.e. (int yearIn = 2000) ...etc).
	DateTime(int hourIn, int minuteIn);
	DateTime(int monthIn, int dayIn, int yearIn, int hourIn, int minuteIn);

	//PUBLIC SET MEMBER FUNCTIONS (SETTERS) // Note: Changed data member setters to bool in project 2 to reuse code for error checking.
	void setDate(int monthIn, int dayIn, int yearIn);
	void setTime(int hourIn, int minuteIn);
	bool setMonth(int monthIn);
	bool setDay(int dayIn);
	bool setYear(int yearIn);
	bool setHour(int hourIn);
	bool setMinute(int minuteIn);

	//PUBLIC GET MEMBER FUNCTIONS (GETTERS)
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }
	int getHour() const { return hour; }
	int getMinute() const { return minute; }

	//OTHER MEMBER FUNCTIONS							
	std::string toString() const; // Note: converts to string with display format (09/05/2018)
	std::string toFileString() const; 	// Note: converts to string with comma delimiter built-in (09,05,2018)


	//OPERATOR OVERLOADING FUNCTIONS
	friend std::istream& operator >>(std::istream& is, DateTime& dateTimeIn);
	friend std::ifstream& operator >>(std::ifstream& ifs, DateTime& dateTimeIn);

	friend std::ostream& operator <<(std::ostream& os, const DateTime& dateTimeIn);
	friend std::ofstream& operator <<(std::ofstream& ofs, const DateTime& dateTimeIn);

	friend bool operator ==(const DateTime& d1, const DateTime& d2); // friend standalone function.
	friend bool operator !=(const DateTime& d1, const DateTime& d2);
	friend bool operator <(const DateTime& d1, const DateTime& d2);
	friend bool operator >(const DateTime& d1, const DateTime& d2);
	friend bool operator <=(const DateTime& d1, const DateTime& d2);
	friend bool operator >=(const DateTime& d1, const DateTime& d2);

	friend DateTime operator +(DateTime& d1, int minutesIn); // Note: You can't add 2 dates (no point of reference) so I changed the second param to int minutes to return Date + minutes.
	friend int operator -(const DateTime& endTime, const DateTime& startTime); //Note: To use this effectively in my program I needed to convert this to return int (minutes).

private:
	//PRIVATE DATA MEMBERS
	int month;
	int day;
	int year;
	int hour;
	int minute;
}; //Note: Class declarations must end in with semicolon

#endif
