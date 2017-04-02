#include "ExercisePlan.h"
//constructor
ExercisePlan::ExercisePlan()
{
	stepGoal = 0;
	name = "";
	date = Date();
}
ExercisePlan::ExercisePlan(int newStepGoal, string newName, Date newDate)
{
	stepGoal = newStepGoal;
	name = newName;
	date = Date(newDate);
}

ExercisePlan::ExercisePlan(string newStepGoal, string newName, string newDate)
{
	stepGoal = stoi(newStepGoal);
	name = newName;
	date = Date(newDate);
}

//copy constructor
ExercisePlan::ExercisePlan(const ExercisePlan &plan)
{
	stepGoal = plan.stepGoal;
	name = plan.name;
	date = plan.date;
}

//destructor
ExercisePlan::~ExercisePlan()
{

}

void operator<<(ostream& os, const ExercisePlan& exercisePlan)
{
	os << exercisePlan.getName() << endl << exercisePlan.getStepGoal() << endl << exercisePlan.getDate() << endl << endl;
}

void operator<<(ofstream& os, const ExercisePlan& exercisePlan)
{
	os << exercisePlan.getName() << endl << exercisePlan.getStepGoal() << endl << exercisePlan.getDate() << endl << endl;
}

ExercisePlan& operator>>(ifstream& is, ExercisePlan exercisePlan)
{
	string name, goal, date;

	is >> name >> goal >> date;
	exercisePlan = ExercisePlan(goal, name, date);
	return exercisePlan;
}

void ExercisePlan::setStepGoal(int newStepGoal)
{
	stepGoal = newStepGoal;
}


void ExercisePlan::print()
{
	cout << "Steps goal: " << stepGoal << " Plan name: " << name << " date: " << date.returnFormattedData() << endl;
}

string ExercisePlan::returnFormattedData()
{
	return "Steps goal: " + to_string(stepGoal) + " Plan name: " + name + " date: " + date.returnFormattedData();
}

int ExercisePlan::getStepGoal() const
{
	return stepGoal;
}

string ExercisePlan::getName() const
{
	return name;
}

string ExercisePlan::getDate() const
{
	return date.returnFormattedData();
}