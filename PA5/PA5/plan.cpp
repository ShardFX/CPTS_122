#include "plan.h"

Plan::Plan()
{
	date = Date(1, 1, 2000);
}

Plan::Plan(Date newDate)
{
	date = Date(newDate);
}

Plan::Plan(const Plan &newPlan)
{

}

void Plan::setDate(int day, int month, int year)
{
	date = Date(day, month, year);
}

void Plan::setName(string newName)
{
	name = newName;
}