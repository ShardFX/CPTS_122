#include "node.h"

Node::Node()
{
	mData = "";
	mLeft = nullptr;
	mRight = nullptr;
}

Node::Node(std::string newData)
{
	mData = newData;
	mLeft = nullptr;
	mRight = nullptr;
}

Node::~Node()
{
	delete mLeft;
	delete mRight;
}

void Node::setData(std::string newData)
{
	mData = newData;
}

void Node::setLeft(Node * newLeft)
{
	mLeft = newLeft;
}

void Node::setRight(Node * newRight)
{
	mRight = newRight;
}

std::string Node::getData()
{
	return mData;
}

Node *& Node::getLeft()
{
	return mLeft;
}

Node *& Node::getRight()
{
	return mRight;
}

TransactionNode::TransactionNode()
{
	mUnits = 0;
	mData = "";
	this->setLeft(nullptr);
	this->setRight(nullptr);
}

TransactionNode::TransactionNode(int newUnits, std::string newData)
{
	mUnits = newUnits;
	mData = newData;
	this->setLeft(nullptr);
	this->setRight(nullptr);
}

TransactionNode::TransactionNode(TransactionNode *& newNode)
{
	mUnits = newNode->getUnits();
	mData = newNode->getData();
	setLeft(newNode->getLeft()); 
	setRight(newNode->getRight());

}


TransactionNode::~TransactionNode()
{
	delete getLeft();
	delete getRight();
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

int TransactionNode::getUnits()
{
	return mUnits;
}

void TransactionNode::printData()
{
	std::cout << mUnits << " " << getData();
}
