#pragma once
#include "BST.h"
#include <fstream>
#include <sstream>

class DataAnalysis
{
private:
	BST *mTreeSold;
	BST *mTreePurchased;
	std::ifstream mCsvStream;

	void loadCSV();
	void splitLines(std::stringstream ss);
	void readCSV();
	void selectTree();
	void printTrends();

public:
	void runAnalsis();

	DataAnalysis();
	~DataAnalysis();
};