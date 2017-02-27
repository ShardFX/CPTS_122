#pragma once
#include "plan.h"

class ExercisePlan : public Plan
{
private:

	int stepGoal;

public:
	//constructor
	ExercisePlan();
	ExercisePlan(int newStepGoal, string newName, Date newDate);
	ExercisePlan(string newStepGoal, string newName, string newDate);

	//copy constructor
	ExercisePlan(const ExercisePlan &plan);

	//destructor
	~ExercisePlan();
	
	void setStepGoal(int newStepGoal);

	void print(); 

	int getStepGoal();
	string getName();
	string getDate();

	string returnFormattedData();


};