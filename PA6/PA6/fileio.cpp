#include "fileio.h"

void fillBST(BST & table, string filename)
{

	std::ifstream file(filename);
	string line;


	while (!file.eof())
	{

		string key;
		string value;
		std::getline(file, line);
		std::stringstream ss(line);
		if (line.find("\",\"")) {

			getline(ss, key, ',');
			getline(ss, value, ',');
		}
		else
		{
			key = ',';
			getline(ss, line, ',');
			getline(ss, line, ',');
			getline(ss, value, ',');
		}
		table.insert(key[0], value);

	}
	file.close();

}

void convertAndDisplay(string convertFile, BST refTable)
{
	std::fstream file(convertFile);
	string line;

	while (!file.eof()) 
	{
		string c;

		std::getline(file, line);
		for (char c : line)
		{
			if (c == ' ')
			{
				cout << "   ";
			}
			else
			{
				refTable.findInTree(toupper(c));
			}
		}
		cout << endl;
	}
	file.close();
}
