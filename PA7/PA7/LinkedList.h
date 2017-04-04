#pragma once
#include "LinkedStack.h"


class ListNode 
{
private:
	int mRecord;
	int mID;
	string mFName;
	string mLName;
	string mEmail;
	int mUnits;
	string mMajor;
	enum Level mLevel;
	Stack mAbsences;
	int mNumAbsences;

	ListNode * pNext;

public:
	ListNode();
	ListNode(int record, int id, string firstName, string lastName, string email
		, int units, string major, Level level, Stack absences, int numAbsences);
	ListNode(ListNode *& newListNode);
	~ListNode();

	void setRecord(int record);
	void setID(int ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setUnits(int units);
	void setMajor(string major);
	void setLevel(enum Level l);
	void setTotalNumAbsences(int totalAbsences);
	void incrementAbsences();
	void setNext(ListNode *& newNext);

	int getRecord() const;
	int getID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getUnits() const;
	string getMajor() const;
	Level getLevel() const;
	int getNumAbsences() const;
	Stack getAbsences();
	ListNode *& getNext();

	
};

enum Level {
	freshman, sophomore, junior, senior, graduate
};

class List
{
private:
	ListNode * mHead;

public:
	List();
	List(List *& newList);
	~List();

	bool insertAtFront(ListNode *& newNode);
	ListNode *& searchByID(int ID);
	ListNode *& searchByName(string firstName, string lastName);
	void listRecentAbsenses();
	void listByAbsenseCount(int minAbsenses);

	void import(string filename);
};