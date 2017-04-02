#pragma once
#include "plan.h"
#include <fstream>
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
	
	friend void operator<<(ostream & os, const ExercisePlan & exercisePlan);
	friend void operator<<(ofstream& os, const ExercisePlan& exercisePlan);
	friend ExercisePlan& operator>>(ifstream& os, ExercisePlan& exercisePlan);

	void setStepGoal(int newStepGoal);

	void print(); 

	int getStepGoal() const;
	string getName() const;
	string getDate() const;

	string returnFormattedData();


};