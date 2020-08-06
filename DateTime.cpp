/*
Brett Hiebert
DateTime.cpp
09/29/2018
*/

#include "DateTime.h"

//DEFAULT CONSTRUCTOR
DateTime::DateTime()
{
	setDate(1, 1, 2000);
	setTime(12, 0);
}

//ALTERNATE CONSTRUCTOR WITH PARAMETERS
DateTime::DateTime(int monthIn, int dayIn, int yearIn)
{
	setDate(monthIn, dayIn, yearIn);
	setTime(12, 0);
}

//ALTERNATE CONSTRUCTOR WITH PARAMETERS
DateTime::DateTime(int hourIn, int minuteIn)
{
	setTime(hourIn, minuteIn);
}

//ALTERNATE CONSTRUCTOR WITH PARAMETERS
DateTime::DateTime(int monthIn, int dayIn, int yearIn, int hourIn, int minuteIn)
{
	setMonth(monthIn);
	setDay(dayIn);
	setYear(yearIn);
	setTime(hourIn, minuteIn);
}

//DATE SETTER FUNCTION
void DateTime::setDate(int monthIn, int dayIn, int yearIn)
{
	setMonth(monthIn);
	setDay(dayIn);
	setYear(yearIn);
}

//TIME SETTER FUNCTION
void DateTime::setTime(int hourIn, int minuteIn)
{
	setHour(hourIn);
	setMinute(minuteIn);
}

//MONTH SETTER FUNCTION
bool DateTime::setMonth(int monthIn)
{
	if (monthIn >= 1 && monthIn <= 12)
	{
		month = monthIn;
		return true;
	}
	return false;
}

//DAY SETTER FUNCTION
bool DateTime::setDay(int dayIn)
{
	if (dayIn >= 1 && dayIn <= 31)
	{
		day = dayIn;
		return true;
	}
	return false;
}

//YEAR SETTER FUNCTION
bool DateTime::setYear(int yearIn)
{
	if (yearIn >= 1000)
	{
		year = yearIn;
		return true;
	}
	return false;
}

//HOUR SETTER FUNCTION
bool DateTime::setHour(int hourIn) {
	if (hourIn >= 0 && hourIn <= 23)
	{
		hour = hourIn;
		return true;
	}
	return false;
}

//MINUTE SETTER FUNCTION
bool DateTime::setMinute(int minuteIn) {
	if (minuteIn >= 0 && minuteIn <= 59)
	{
		minute = minuteIn;
		return true;
	}
	return false;
}

//DATE TO STRING FORMATTING FUNCTION
std::string DateTime::toString() const
{
	std::string consoleFormat;
	std::string minuteString;

	if (minute < 10) // format string to add additional 0 for digits 0-9
		minuteString = "0" + std::to_string(minute);
	else
		minuteString = std::to_string(minute);

	consoleFormat = std::to_string(month) + "/"
		+ std::to_string(day) + "/"
		+ std::to_string(year) + " "
		+ std::to_string(hour) + ":"
		+ minuteString;

	return consoleFormat;
}

//DATE TO FILE STRING FORMATTING FUNCTION
std::string DateTime::toFileString() const
{
	std::string fileFormat;

	fileFormat = std::to_string(month) + ","
		+ std::to_string(day) + ","
		+ std::to_string(year) + ","
		+ std::to_string(hour) + ","
		+ std::to_string(minute) + ",";

	return fileFormat;
}

//EXTRACTION OPERATOR OVERLOAD FUNCTION (FRIEND)
std::istream& operator >>(std::istream& is, DateTime& dateTimeIn)
{
	//declare variables for input and a bool flag to check the input
	int tmpInput;
	bool ok = false;

	while (!ok) // loop until we get valid integer inputs for the DateTime timestamp.
	{
		std::cout << std::endl; // Print new line at the start of the input loop
		std::cout << "Enter month number: "; //Prompt user for correct input type
		is >> tmpInput;
		if (is.fail() || !dateTimeIn.setMonth(tmpInput)) // Use the setter function to check the correct range and make sure we get integer input.
		{
			is.clear(); // if there is an error, clear the input
			is.ignore(); // ignore the stripped newline char
			std::cout << "\nERROR: Month value is not an integer or not in a valid range."; //print error message
			continue; // restart the loop.
		}
		std::cout << "Enter day number: "; //Same logic steps as month for the rest of the loop.
		is >> tmpInput;
		if (is.fail() || !dateTimeIn.setDay(tmpInput))
		{
			is.clear();
			is.ignore();
			std::cout << "\nERROR: Day value is not an integer or not in a valid range.";
			continue;
		}
		std::cout << "Enter year number: ";
		is >> tmpInput;
		if (is.fail() || !dateTimeIn.setYear(tmpInput))
		{
			is.clear();
			is.ignore();
			std::cout << "\nERROR: Year value is not an integer or not in a valid range.";
			continue;
		}
		std::cout << "Enter hour number (in 24-hour military time): ";
		is >> tmpInput;
		if (is.fail() || !dateTimeIn.setHour(tmpInput))
		{
			is.clear();
			is.ignore();
			std::cout << "\nERROR: Hour value is not an integer or not in a valid range.";
			continue;
		}
		std::cout << "Enter minute number: ";
		is >> tmpInput;
		if (is.fail() || !dateTimeIn.setMinute(tmpInput))
		{
			is.clear();
			is.ignore();
			std::cout << "\nERROR: Minute value is not an integer or not in a valid range.";
			continue;
		}
		ok = true; //if we get to this point all the values are ok and have been inserted into the DateTime object.
	}
	return is;
}

//FILE EXTRACTION OPERATOR OVERLOAD FUNCTION (FRIEND)
std::ifstream& operator >>(std::ifstream& ifs, DateTime& dateTimeIn)
{
	//Declare string variables to handle file input and int array to store extracted data.
	std::string dataField;
	int arr[5];

	for (int i = 0; i < 5; i++) // each of the 5 fields in the DataTime object....
	{
		getline(ifs, dataField, ','); 	//Grab a comma delimited field from the file.

		if(dataField == " ")
		{
			return ifs;
		}

		arr[i] = std::stoi(dataField); //Convert to int and store in the arr.

	}

	//Set the extracted data to the DateTime object (includes error checking in setter i.e. nothing will be set if values out of range).
	dateTimeIn.setMonth(arr[0]);
	dateTimeIn.setDay(arr[1]);
	dateTimeIn.setYear(arr[2]);
	dateTimeIn.setHour(arr[3]);
	dateTimeIn.setMinute(arr[4]);

	return ifs;
}

//INSERTION OPERATOR OVERLOAD FUNCTION (FRIEND)
std::ostream& operator <<(std::ostream& os, const DateTime& dateTimeIn)
{
	os << dateTimeIn.toString();
	return os;
}

//FILE INSERTION OPERATOR OVERLOAD FUNCTION (FRIEND)
std::ofstream& operator <<(std::ofstream& ofs, const DateTime& dateTimeIn)
{
	ofs << dateTimeIn.toFileString();
	return ofs;
}

//== OPERATOR OVERLOAD FUNCTION (FRIEND)
bool operator ==(const DateTime & d1, const DateTime & d2)
{
	if (d1.toString() == d2.toString()) //checks the full string of one date against another
		return true;
	return false;
}

//!= OPERATOR OVERLOAD FUNCTION (FRIEND)
bool operator !=(const DateTime & d1, const DateTime & d2)
{
	return !(d1 == d2); //simply returns opposite of ==
}

//< OPERATOR OVERLOAD FUNCTION (FRIEND)
bool operator <(const DateTime & d1, const DateTime & d2)
{
	if (d1.year < d2.year)  //If the first year is less than the second we know the whole first date is less than. 
		return true;
	else if (d1.year > d2.year) //Should return false if the first year is greater (no need to do other checks in that case)
		return false;
	else if (d1.month < d2.month) //If this point is reached the years must be the same so we check the next biggest time value. 
		return true;
	else if (d1.month > d2.month) //Same logic as above - no need to move on if d1.month is greater than d2.month.
		return false;
	else if (d1.day < d2.day) //Months are the same, so we check days 
		return true;
	else if (d1.day > d2.day) //Same logic as above
		return false;
	else if (d1.hour < d2.hour)
		return true;
	else if (d1.day > d2.day)
		return false;
	else if (d1.minute < d2.minute)
		return true;
	else
		return false; //At this point, d1 is either greater than or exactly equal to d2 so we return false either way.
}

//> OPERATOR OVERLOAD FUNCTION (FRIEND)
bool operator >(const DateTime& d1, const DateTime& d2)
{
	if (d1 != d2) // if they arent equal
		return !(d1 < d2); // return the opposite of <
	else
		return false;
}

//<= OPERATOR OVERLOAD FUNCTION (FRIEND)
bool operator <=(const DateTime& d1, const DateTime& d2)
{
	return !(d1 > d2); // > Will return false if d1 equal d2 or if d1 is greater than d2, so we can get <= by negating it.
}

//>= OPERATOR OVERLOAD FUNCTION (FRIEND)
bool operator >=(const DateTime& d1, const DateTime& d2)
{
	return !(d1 < d2); //Same logic as above for >=.
}

//+ OPERATOR OVERLOAD FUNCTION (FRIEND)
DateTime operator +(DateTime& d1, int minutesIn)
{
	int totalDays;
	int totalHours;
	int totalMinutes;

	totalDays = minutesIn / 1440; // integer division for total days
	totalHours = (minutesIn % 1440) / 60; // remaining minutes divided by 60 for total hours
	totalMinutes = (minutesIn % 1440) % 60; // remaining minutes will be total minutes.

	d1.setDay(d1.day + totalDays); //Set new values
	d1.setHour(d1.hour + totalHours);
	d1.setMinute(d1.minute + totalMinutes);

	return d1;
}

//- OPERATOR OVERLOAD FUNCTION (FRIEND) Note: returns the difference in int minutes.
int operator -(const DateTime& endTime, const DateTime& startTime)
{
	int minutesUsed = 0;
	int totalMinsUsed = 0;
	int minPastHourStartDay = 0;
	int minPastHourEndDay = 0;
	int totalHoursUsed = 0;
	int hoursUsedStartDay = 0;
	int hoursUsedEndDay = 0;
	int daysUsed = 0;

	if (endTime > startTime)//Check to make sure we don't calculate a negative values
	{
		daysUsed = endTime.day - startTime.day;

		if (daysUsed > 0) // This logic converts the days to hours and then the hours to minutes.
		{
			hoursUsedStartDay = 24 - startTime.getHour();
			hoursUsedEndDay = endTime.getHour();

			minPastHourStartDay = startTime.getMinute();
			minPastHourEndDay = endTime.getMinute();

			totalHoursUsed = hoursUsedStartDay + hoursUsedEndDay + (24 * (daysUsed - 1));

			minutesUsed = minPastHourEndDay + (totalHoursUsed * 60) - minPastHourStartDay;
			return minutesUsed;
		}
		else //If less than a day of use...
		{
			totalHoursUsed = endTime.getHour() - startTime.getHour();
			totalMinsUsed = endTime.getMinute() - startTime.getMinute();
			minutesUsed = totalMinsUsed + (totalHoursUsed * 60);
			return minutesUsed;
		}
	}
	else
		return 0;
}
