#pragma once
#include <iostream>
#include <string>

class Node
{
protected:
	std::string mData;
	Node * mLeft;
	Node * mRight;

public:
	Node();
	Node(std::string newData);

	virtual ~Node();

	void setData(std::string newData);
	void setLeft(Node * newLeft);
	void setRight(Node * newRight);

	std::string getData();
	Node *& getLeft();
	Node *& getRight();

	virtual void printData() = 0;

};

class TransactionNode: public Node
{
protected:
	int mUnits;

public:
	TransactionNode();
	TransactionNode(int newUnits, std::string newData);
	~TransactionNode();

	void setUnits(int newUnits);

	int getUnits();

	void printData();
};