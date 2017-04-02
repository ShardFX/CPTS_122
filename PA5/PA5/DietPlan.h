#pragma once
#include "plan.h"
#include <fstream>

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

	friend void operator<<(ostream& os, const DietPlan& dietPlan);
	friend void operator<<(ofstream& os, const DietPlan& exercisePlan);
	friend DietPlan& operator>>(ifstream& os, DietPlan& exercisePlan);

	void setCalGoal(int newCals);

	int getCalGoal() const;
	string getName() const;
	string getDate() const;

	void print();
	string returnFormattedData();


};