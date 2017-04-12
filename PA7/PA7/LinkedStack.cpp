#include "LinkedStack.h"


/*
Definitions for Stack Node
*/
StackNode::StackNode()
{
	mDate = Date("00/00/0000");
	mNext = nullptr;
}

StackNode::StackNode(Date date)
{
	mDate = date;
	mNext = nullptr;
}

StackNode::StackNode(StackNode *& newNode)
{
	mDate = newNode->getDate();
	mNext = newNode->getNext();
}


StackNode::~StackNode()
{
}

Date StackNode::getDate() const
{
	return mDate;
}

StackNode *& StackNode::getNext()
{
	return mNext;
}

void StackNode::setNext(StackNode *& newNode)
{
	mNext = newNode;
}


/*
Definitions for Stack
*/

Stack::Stack()
{
	mHead = nullptr;
}

Stack::Stack(Stack *& newStack)
{
	mHead = newStack->mHead;
}

Stack::~Stack()
{
}

void Stack::push(StackNode * newNode)
{
	if (mHead == nullptr)
	{
		mHead = newNode;
	}
	else
	{
		newNode->setNext(mHead);
		mHead = newNode;
	}

}

bool Stack::pop(Date & popDate)
{
	if (mHead != nullptr)
	{
		popDate = mHead->getDate();
		mHead = mHead->getNext();
		return true;
	}
	return false;
}

bool Stack::peek(Date & peekDate)
{
	if (mHead != nullptr)
	{
		peekDate = mHead->getDate();
		return true;
	}
	return false;
}

bool Stack::isEmpty()
{
	if (mHead == nullptr) {
		return true;
	}
	return false;
}
