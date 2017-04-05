#pragma once
#include "Date.h"

class StackNode
{
private:
	Date mDate;
	StackNode * mNext;

public:
	StackNode();
	StackNode(Date date);
	StackNode(StackNode *& newNode);
	~StackNode();
	
	Date getDate() const;
	StackNode *& getNext();

};

class Stack
{
private:
	StackNode * mHead;

public:
	Stack();
	Stack(Stack *& newStack);
	~Stack();

	bool push(StackNode newNode);
	bool pop(Date & popDate);
	bool peek(Date & peekDate);

};