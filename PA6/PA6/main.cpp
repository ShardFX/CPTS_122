#include "BST.h"
#include <fstream>
#include <sstream>

int main(void)
{
	BST morseCode = BST();
	std::ifstream file ("MorseTable.csv");


	string line;
	char key;
	string value;

	
	while(!file.eof())
	{
		std::getline(file, line);
		std::stringstream ss(line);
		if (line.find("\",\"")) {
			while (getline(ss, line, ','))
			{
				cout << line << endl;
			}
		}
		else
		{
			cout << "," << endl;
			getline(ss, line, ",");
			getline(ss, line, ",");
			getline(ss, line, ",");
			cout << line << endl;
		}

	}




	return 0;
}