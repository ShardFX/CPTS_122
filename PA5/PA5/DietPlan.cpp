#include "DietPlan.h"

//constructor
DietPlan::DietPlan()
{
	calGoal = 0;
	name = "";
	date = Date();
}

DietPlan::DietPlan(int newCalGoal, string newName, Date newDate)
{
	calGoal = newCalGoal;
	name = newName;
	date = Date(newDate);
}

DietPlan::DietPlan(string newCalGoal, string newName, string newDate)
{
	calGoal = stoi(newCalGoal);
	name = newName;
	date = Date(newDate);
}

//copy constructor
DietPlan::DietPlan(const DietPlan &plan)
{
	calGoal = plan.calGoal;
	name = plan.name;
	date = Date(plan.date);
}

//destructor
DietPlan::~DietPlan()
{

}

void operator<<(ostream& os, const DietPlan& dietPlan)
{
	os << dietPlan.getName() << endl << dietPlan.getCalGoal() << endl << dietPlan.getDate() << endl << endl;
}

void operator<<(ofstream& os, const DietPlan& plan)
{
	os << plan.getName() << endl << plan.getCalGoal() << endl << plan.getDate() << endl << endl;
}

DietPlan& operator>>(ifstream& is, DietPlan& plan)
{
	string name, goal, date;

	is >> name >> goal >> date;
	plan = DietPlan(goal, name, date);
	return plan;
}

void DietPlan::setCalGoal(int newCals)
{
	calGoal = newCals;
}

void DietPlan::print()
{
	cout << "Calorie goal: " << calGoal << " Plan name: " << name << " date: " << date.returnFormattedData() << endl;
}

string DietPlan::returnFormattedData()
{
	return "Calorie goal: " + to_string(calGoal) + " Plan name: " + name + " date: " + date.returnFormattedData();
}

int DietPlan::getCalGoal() const
{
	return calGoal;
}

string DietPlan::getName() const
{
	return name;
}

string DietPlan::getDate() const
{
	return date.returnFormattedData();
}