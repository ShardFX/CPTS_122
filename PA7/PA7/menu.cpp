#include "menu.h"

Menu::Menu()
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	today = Date(now->tm_mday, now->tm_mon, now->tm_year + 1900);
	masterList = List();
}

Menu::~Menu()
{
}

void Menu::run()
{
	bool success = true;
	int c = 0;

	system("cls");
	cout << "(1)	Import Course List" << endl;
	cout << "(2)	Load Master List" << endl;
	cout << "(3)	Store Master List" << endl;
	cout << "(4)	Mark Absences" << endl;
	cout << "(5)	Edit Absences" << endl;
	cout << "(6)	Generate Report" << endl;
	cout << "(7)	Exit" << endl;
	cin >> c;

	while (success)
	{
		switch (c)
		{
		case 0:
			system("cls");
			cout << "(1)	Import Course List" << endl;
			cout << "(2)	Load Master List" << endl;
			cout << "(3)	Store Master List" << endl;
			cout << "(4)	Mark Absences" << endl;
			cout << "(5)	Edit Absences" << endl;
			cout << "(6)	Generate Report" << endl;
			cout << "(7)	Exit" << endl;
			cin >> c;
			break;
		case 1:
			masterList.import(courseFile, true);
			c = 0;
			break;
		case 2:
			masterList.import(masterFile, false);
			c = 0;
			break;
		case 3:
			masterList.save(masterFile);
			c = 0;
			break;
		case 4:
			masterList.markAbsences(today);
			c = 0;
			break;
		case 5:
			masterList.editAbsences();
			c = 0;
			break;
		case 6:
			masterList.generateReport();
			c = 0;
			break;
		case 7:
			success = false;
			break;
		default:
			success = false;
			c = 0;
			break;
		}
	}

}
