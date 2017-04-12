#pragma once
#include "node.h"

class BST
{
private: 
	Node * mpRoot;
	void destroyTree(Node * root);
	void insert(Node *& root, Node * newNode);
	void inOrderTraversal(Node * root);
	TransactionNode & findSmallest(Node *& root);
	TransactionNode & findLargest(Node *& root);


public:

	BST();
	BST(Node * newHead);
	~BST();

	void setHead(Node * newHead);
	Node * getHead();
	void insert(Node * newNode);
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();


};