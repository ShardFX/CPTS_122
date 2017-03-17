#include "BST.h"

/*
Node Class definitions
*/

Node::Node(char newKey, string newValue)
{
	mKey = newKey;
	mValue = newValue;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
}

string Node::getValue() const
{
	return mValue;
}

char Node::getKey() const
{
	return mKey;
}

Node *& Node::getLeft()
{
	return mpLeft;
}

Node *& Node::getRight()
{
	return mpRight;
}

void Node::setKey(const char newKey)
{
	mKey = newKey;
}

void Node::setValue(const string newValue)
{
	mValue = newValue;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}

void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}

/*
BST class definitions
*/

BST::BST()
{
	mpRoot = nullptr;
}

BST::BST(const BST & rhs)
{
	this->mpRoot = rhs.mpRoot;
}

BST::~BST()
{
}

Node * BST::getRoot() const
{
	return mpRoot;
}

void BST::setRoot(Node * const newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(char key, string value)
{
	insert(this->mpRoot, toupper(key), value);
}

void BST::insert(Node *& pTree, char key, string value)
{
	if (pTree = nullptr)
	{
		pTree = new Node(key, value);
	}
	else if (pTree->getKey() > key)
	{
		insert(pTree->getLeft(), key, value);
	}
	else if (pTree->getKey() < key)
	{
		insert(pTree->getRight(), key, value);
	}

}

void BST::inorder()
{
	inorder(this->mpRoot);
}

void BST::inorder(Node *& pTree)
{
	inorder(pTree->getLeft());
	cout << pTree->getKey() << " " << pTree->getValue() << endl;
	inorder(pTree->getRight());
}
