#pragma once
#include <iostream>
#include "date.h"
using namespace std;

class Plan
{

protected:
	Date date;
	std::string name;

public:
	Plan();
	Plan(Date newDate);
	Plan(const Plan &newPlan);

	void setDate(int day, int month, int year);
	void setName(string newName);

};
