#pragma once
#include "plan.h"

class DietPlan: public Plan
{
private:

	int calGoal;
	std::string name;

public:
	//constructor
	DietPlan();
	DietPlan(int newCalGoal, string newName, Date newDate);
	DietPlan(string newCalGoal, string newName, string newDate);

	//copy constructor
	DietPlan(const DietPlan &plan);

	//destructor
	~DietPlan();

	void setCalGoal(int newCals);

	void print();
	string returnFormattedData();


};