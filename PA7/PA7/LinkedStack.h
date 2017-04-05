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
	void setNext(StackNode *& newNode);

};

class Stack
{
private:
	StackNode * mHead;

public:
	Stack();
	Stack(Stack *& newStack);
	~Stack();

	void push(StackNode * newNode);
	void pop(Date & popDate);
	void peek(Date & peekDate);

};