#include "BST.h"


//node methods

Node::Node(int newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
}

int Node::getData() const
{
	return mData;
}

Node *& Node::getLeft()
{
	return mpLeft;
}

Node *& Node::getRight()
{
	return mpRight;
}

void Node::setData(const int newData)
{
	mData = newData;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}

void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}




//BST class Methods

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

void BST::insert(int data)
{
	insert(this->mpRoot, data);
}

void BST::insert(Node *& pTree, int data)
{
	if (pTree = nullptr)
	{
		pTree = new Node(data);
	}
	else if (data < pTree->getData())
	{
		insert(pTree->getLeft(), data);
	}
	else if (data > pTree->getData())
	{
		insert(pTree->getRight(), data);
	}

}

void BST::inorder()
{
	inorder(this->mpRoot);
}

void BST::inorder(Node *& pTree)
{
	inorder(pTree->getLeft());
	cout << pTree->getData() << endl;
	inorder(pTree->getRight());
}
