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

int ExercisePlan::getStepGoal()
{
	return stepGoal;
}

string ExercisePlan::getName()
{
	return name;
}

string ExercisePlan::getDate()
{
	return date.returnFormattedData();
}