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
	getline(mCsvStream, line);
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
	std::cout << "Purchases: " << std::endl;
	mTreePurchased->inOrderTraversal();
	std::cout << "Sales: " << std::endl;
	mTreeSold->inOrderTraversal();

	TransactionNode largestPurchased = mTreePurchased->findLargest();
	TransactionNode largestSold = mTreeSold->findLargest();

	TransactionNode smallestPurchased = mTreePurchased->findSmallest();
	TransactionNode smallestSold = mTreeSold->findSmallest();

	std::cout << "Most purchased: " << largestPurchased.getData() << " : " << largestPurchased.getUnits() << std::endl;
	std::cout << "Most sold: " << largestSold.getData() << " : " << largestSold.getUnits() << std::endl;
	std::cout << "Least purchased: " << smallestPurchased.getData() << " : " << smallestPurchased.getUnits() << std::endl;
	std::cout << "Least sold: " << smallestSold.getData() << " : " << smallestSold.getUnits() << std::endl;

}

void DataAnalysis::runAnalsis()
{
	loadCSV();
	readCSV();
	printTrends();
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
