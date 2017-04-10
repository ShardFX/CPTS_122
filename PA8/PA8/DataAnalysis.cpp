#include "DataAnalysis.h"

void DataAnalysis::loadCSV()
{
	mCsvStream.open("data.csv");
}

void DataAnalysis::splitLines(std::stringstream ss)
{
	int units = 0;
	std::string data, line;
	bool sold = true;

	getline(ss, line, ',');
	units = stoi(line);

	getline(ss, line, ',');
	data = line;

	getline(ss, line, ',');
	if (line != "Sold") { sold = false; }

	Node *newNode = new TransactionNode(units, data);
	if (sold)
	{
		mTreeSold->insert(newNode);
	}
	else
	{
		mTreePurchased->insert(newNode);
	}
}

void DataAnalysis::readCSV()
{
	std::string line;
	while (getline(mCsvStream, line))
	{
		splitLines(std::stringstream(line));
	}
}

void DataAnalysis::selectTree()
{
	//not worth splitting this far....
}

void DataAnalysis::printTrends()
{
}

void DataAnalysis::runAnalsis()
{
}

DataAnalysis::DataAnalysis()
{
	mTreeSold = new BST();
	mTreePurchased = new BST();
}

DataAnalysis::~DataAnalysis()
{
	delete mTreePurchased;
	delete mTreeSold;
	mCsvStream.close();
}
