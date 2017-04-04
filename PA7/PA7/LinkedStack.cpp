#include "LinkedStack.h"


/*
Definitions for Stack Node
*/
StackNode::StackNode()
{
	mDate = Date("00/00/0000");
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

bool Stack::push(StackNode newNode)
{


	return false;
}

bool Stack::pop(Date & popDate)
{


	return false;
}

bool Stack::peek(Date & peekDate)
{


	return false;
}
