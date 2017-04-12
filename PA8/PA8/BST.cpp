#include "BST.h"

void BST::destroyTree(Node * root)
{
	if (root != nullptr)
	{
		destroyTree(root->getLeft());
		destroyTree(root->getRight());
	}
	delete root;
}

void BST::insert(Node * newNode)
{
	insert(this->mpRoot, newNode);
}

void BST::inOrderTraversal(Node *& root)
{
	if (root != nullptr)
	{
		inOrderTraversal(root->getLeft());
		std::cout << root->getData() << " : " << dynamic_cast<TransactionNode *>(root)->getUnits() << std::endl;
		inOrderTraversal(root->getRight());
	}
}

TransactionNode & BST::findSmallest()
{
	return findSmallest(mpRoot);
}

TransactionNode & BST::findLargest()
{
	return findLargest(mpRoot);
}

BST::BST()
{
	mpRoot = nullptr;
}

BST::BST(Node * newHead)
{
	mpRoot = newHead;
}

BST::~BST()
{
	destroyTree(this->mpRoot);
}

void BST::setHead(Node * newHead)
{
	mpRoot = newHead;
}

Node * BST::getHead()
{
	return mpRoot;
}

void BST::insert(Node *& root, Node * newNode)
{
	if (root == nullptr)
	{
		root = newNode;
		return;
	}
	else if (dynamic_cast<TransactionNode *>(root)->getUnits() > dynamic_cast<TransactionNode *>(newNode)->getUnits())
	{
		insert(root->getLeft(), newNode);
	}
	else if (dynamic_cast<TransactionNode *>(root)->getUnits() < dynamic_cast<TransactionNode *>(newNode)->getUnits())
	{
		insert(root->getRight(), newNode);

	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

//can't be empty;
TransactionNode & BST::findSmallest(Node *& root)
{
	if (root->getLeft() != nullptr)
	{
		return findSmallest(root->getLeft());
	}
	return  dynamic_cast<TransactionNode &>((*root));
}

TransactionNode & BST::findLargest(Node *& root)
{
	if (root->getRight() != nullptr)
	{
		return findLargest(root->getRight());
	}
	return dynamic_cast<TransactionNode &>((*root));
}
