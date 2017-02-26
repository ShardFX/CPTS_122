#pragma once
#include <iostream>
#include <string>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int newDay, int newMonth, int newYear);
	Date(string newDate);

	Date(const Date &newDate);
	
	void setDate(int newDay, int newMonth, int newYear);

	void print();
	string returnFormattedData();

};
