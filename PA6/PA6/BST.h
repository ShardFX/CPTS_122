#pragma once

#include <iostream>
#include <string>
#include <locale>

/*
Using BST we built in lecture
From A.oFallon
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node 
{
public:
	Node(char newKey = 'G', string newValue = "--.");
	~Node();

	string getValue() const; 
	char getKey() const;
	Node *& getLeft();
	Node *& getRight();


	void setKey(const char newKey);
	void setValue(const string newValue);
	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);

private:
	char mKey;
	string mValue;
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


	void insert(char key, string value);
	void inorder();

	bool findInTree(char c);

private:
	Node *mpRoot;

	void insert(Node *& pTree, char key, string value);

	void inorder(Node *& pTree);

	bool findInTree(Node *&pTree, const char c);
};