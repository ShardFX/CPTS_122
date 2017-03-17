#pragma once

#include <iostream>
/*
Using BST we built in lecture
From A.oFallon
*/

using std::cin;
using std::cout;
using std::endl;

class Node 
{
public:
	Node(int newData = 0);
	~Node();

	int getData() const; 
	Node *& getLeft();
	Node *& getRight();


	void setData(const int newData);
	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);

private:
	int mData;
	Node *mpLeft;
	Node *mpRight;
};

class BST
{
public:
	BST();
	BST(const BST &rhs);
	~BST();

	Node *getRoot() const;

	void setRoot(Node * const newRoot);


	void insert(int data);
	void inorder();

private:
	Node *mpRoot;

	void insert(Node *& pTree, int data);

	void inorder(Node *& pTree);
};