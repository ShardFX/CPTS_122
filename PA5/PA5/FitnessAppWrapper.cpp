#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
}

void FitnessAppWrapper::runApp()
{

	DietPlan dietPlan[7];
	ExercisePlan exercisePlan[7];

	for (int i = 0; i < 7; i++)
	{
		dietPlan[i] = DietPlan();
		exercisePlan[i] = ExercisePlan();
	}

	displayMenu(dietPlan, exercisePlan);
}

DietPlan FitnessAppWrapper::loadDailyPlan(DietPlan weeklyPlan, ifstream &pFile)
{
	string name, goal, date;
	
	pFile >> name >> goal >> date;
	return DietPlan(goal, name, date);
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::loadWeeklyPlan(DietPlan weeklyPlan[])
{
	ifstream pFile(DF_NAME);
	for (int i = 0; i < 7; i++)
	{
		weeklyPlan[i] = loadDailyPlan(weeklyPlan[i], pFile);
	}
	pFile.close();
	this_thread::sleep_for(chrono::seconds(1));
}

ExercisePlan FitnessAppWrapper::loadDailyPlan(ExercisePlan weeklyPlan, ifstream &pFile)
{
	string name, goal, date, bl;

	pFile >> name >> goal >> date;
	return ExercisePlan(goal, name, date);

	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::loadWeeklyPlan(ExercisePlan weeklyPlan[])
{
	ifstream pFile(EF_NAME);
	for (int i = 0; i < 7; i++)
	{
		weeklyPlan[i] = loadDailyPlan(weeklyPlan[i], pFile);
	}
	pFile.close();
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::storeDailyPlan(DietPlan weeklyPlan,ofstream &pFile)
{
	pFile << weeklyPlan.getName() << endl << weeklyPlan.getCalGoal() << endl << weeklyPlan.getDate() << endl << endl;
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::storeWeeklyPlan(DietPlan weeklyPlan[])
{
	ofstream fs;
	fs.open(DF_NAME, ofstream::out | ofstream::trunc);
	
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(weeklyPlan[i],fs);
	}
	fs.close();
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::storeDailyPlan(ExercisePlan weeklyPlan, ofstream &pFile)
{
	pFile << weeklyPlan.getName() << endl << weeklyPlan.getStepGoal() << endl << weeklyPlan.getDate() << endl << endl;

	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::storeWeeklyPlan(ExercisePlan weeklyPlan[])
{
	ofstream fs;
	fs.open(DF_NAME, ofstream::out | ofstream::trunc);

	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(weeklyPlan[i],fs);
	}

	fs.close();
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::editDailyPlan(DietPlan &plan)
{
	string tName, tDate;
	int tCal;

	cout << "Enter new name: ";
	cin >> tName;

	cout << "Enter new Cal Goal: ";
	cin >> tCal;

	cout << "Enter new date in mm/dd/yyyy: ";
	cin >> tDate;

	DietPlan tPlan = DietPlan(tCal, tName, Date(tDate));
	plan = tPlan;
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::editDailyPlan(ExercisePlan &plan)
{
	string tName, tDate;
	int tStep;

	cout << "Enter new name: ";
	cin >> tName;

	cout << "Enter new steps Goal: ";
	cin >> tStep;

	cout << "Enter new date in mm/dd/yyyy: ";
	cin >> tDate;

	ExercisePlan tPlan = ExercisePlan(tStep, tName, Date(tDate));
	plan = tPlan;

	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::editWeeklyPlan(DietPlan(&weeklyPlan)[7])
{
	for (int i = 0; i < 7; i++)
	{
		editDailyPlan(weeklyPlan[i]);
	}
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::editWeeklyPlan(ExercisePlan(&weeklyPlan)[7])
{
	for (int i = 0; i < 7; i++)
	{
		editDailyPlan(weeklyPlan[i]);
	}
	this_thread::sleep_for(chrono::seconds(1));
}

void FitnessAppWrapper::displayMenu(DietPlan dietPlan[], ExercisePlan exercisePlan[])
{
	time_t ctime = time(NULL);
	tm *timeStats = localtime(&ctime);
	
	system("cls");
	Commands c = MENU;

	printf("\n(1)   Load Weekly Diet Plan\n(2)   Load Weekly Exercise Plan\n(3)   Store Weekly Diet Plan\n(4)   Store Weekly Exercise Plan\n(5)   Display Weekly Diet Plan\n(6)   Display Weekly Exercise Plan\n(7)   Edit Daily Diet Plan\n(8)   Edit Daily Exercise Plan\n(9)   Exit\n");
	scanf("%d", &c);

	while (true)
	{
		switch (c)
		{
		case MENU:
			displayMenu(dietPlan, exercisePlan);
			break;
		case LWDP:
			loadWeeklyPlan(dietPlan);
			c = MENU;
			break;
		case LWEP:
			loadWeeklyPlan(exercisePlan);
			c = MENU;
			break;
		case SWDP:
			storeWeeklyPlan(dietPlan);
			c = MENU;
			break;
		case SWEP:
			storeWeeklyPlan(exercisePlan);
			c = MENU;
			break;
		case DWDP:
			displayWeeklyPlan(dietPlan);
			c = MENU;
			break;
		case DWEP:
			displayWeeklyPlan(exercisePlan);
			c = MENU;
			break;
		case EDDP:
			editDailyPlan(dietPlan[timeStats->tm_wday]);
			c = MENU;
			break;
		case EDEP:
			editDailyPlan(exercisePlan[timeStats->tm_wday]);
			c = MENU;
			break;
		case EXIT:
			c = MENU;
			break;
		default:
			c = MENU;
			break;
		}
	}
}
