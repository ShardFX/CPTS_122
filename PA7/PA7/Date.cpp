#include "Date.h"

Date::Date()
{
	day = month = 1;
	year = 2000;
}

Date::Date(int newDay, int newMonth, int newYear)
{
	day = newDay;
	month = newMonth;
	year = newYear;
}

Date::Date(string newDate)
{
	size_t position = 0;
	string delim = "/";

	position = newDate.find(delim);
	day = stoi(newDate.substr(0, position));
	newDate.erase(0, position + 1);

	position = newDate.find(delim);
	month = stoi(newDate.substr(0, position));
	newDate.erase(0, position + 1);

	position = newDate.find(delim);
	year = stoi(newDate.substr(0, position));
}

Date::Date(const Date &newDate)
{
	day = newDate.day;
	month = newDate.month;
	year = newDate.year;
}

void Date::setDate(int newDay, int newMonth, int newYear)
{
	day = newDay;
	month = newMonth;
	year = newYear;
}

void Date::print()
{
	cout << "Day: " << day << " Month: " << month << " Year: " << year << endl;
}

string Date::returnFormattedData() const
{
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}