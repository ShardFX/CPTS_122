#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>

#include "DietPlan.h"
#include "ExercisePlan.h"

using namespace std;

class FitnessAppWrapper
{
private:
	string EF_NAME = "exercisePlans.txt";
	string DF_NAME = "dietPlans.txt";


public:
	FitnessAppWrapper();
	void runApp();

	DietPlan loadDailyPlan(DietPlan weeklyPlan, ifstream &pFile);
	void loadWeeklyPlan(DietPlan weeklyPlan[]);

	ExercisePlan loadDailyPlan(ExercisePlan weeklyPlan, ifstream &pFile);
	void loadWeeklyPlan(ExercisePlan weeklyPlan[]);

	void editDailyPlan(DietPlan &plan);
	void editDailyPlan(ExercisePlan &plan);

	void editWeeklyPlan(DietPlan (&weeklyPlan)[7]);
	void editWeeklyPlan(ExercisePlan (&weeklyPlan)[7]);

	void storeDailyPlan(DietPlan weeklyPlan, ofstream &pFile);
	void storeWeeklyPlan(DietPlan weeklyPlan[]);

	void storeDailyPlan(ExercisePlan weeklyPlan, ofstream &pFile);
	void storeWeeklyPlan(ExercisePlan weeklyPlan[]);

	bool displayMenu(DietPlan dietPlan[], ExercisePlan exercisePlan[]);

	template<typename T>
	void displayDailyPlan(T plan[])
	{
		for (int i = 0; i < 7; i++)
		{
			plan[i].print();
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
	template<typename T>
	void displayWeeklyPlan(T plan[])
	{
		for (int i = 0; i < 7; i++)
		{
			plan[i].print();
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
};

typedef enum commands {
	MENU, LWDP, LWEP, SWDP, SWEP, DWDP, DWEP, EDDP, EDEP, EXIT,
}Commands;

