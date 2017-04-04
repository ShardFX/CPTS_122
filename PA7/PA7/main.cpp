#include <ctime>
#include "LinkedList.h"
#include "main.h"


int main(void)
{
	string courseFile = "classList.csv";
	string masterFile = "master.txt";

	time_t t = time(0);
	struct tm * now = localtime(&t);
	Date today = Date(now->tm_mday, now->tm_mon, now->tm_year + 1900);

	List masterList;

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
			break;
		case 1:
			masterList.import(courseFile);
			c = 0;
			break;
		case 2:
			masterList.load();
			c = 0;
			break;
		case 3:
			masterList.store();
			c = 0;
			break;
		case 4:
			masterList.markAbsences();
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
	return false;
	return 0;
}