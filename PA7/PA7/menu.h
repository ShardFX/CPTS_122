#pragma once
#include "LinkedList.h"
class Menu
{
private:
	string courseFile = "classList.csv";
	string masterFile = "master.txt";
	Date today;
	List masterList;

public:
	Menu();
	~Menu();

	void run();
};