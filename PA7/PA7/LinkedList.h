#pragma once
#include "LinkedStack.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <chrono>
#include <thread>


class ListNode 
{
private:
	int mRecord;
	int mID;
	string mName;
	string mEmail;
	int mUnits;
	string mMajor;
	string mLevel;
	Stack *mAbsences;
	int mNumAbsences;

	ListNode * pNext;

public:
	ListNode();
	ListNode(int record, int id, string name, string email
		, int units, string major, string level, Stack *absences, int numAbsences);
	ListNode(ListNode *& newListNode);
	~ListNode();

	void setRecord(int record);
	void setID(int ID);
	void setName(string name);
	void setEmail(string email);
	void setUnits(int units);
	void setMajor(string major);
	void setLevel(string level);
	void setTotalNumAbsences(int totalAbsences);
	void incrementAbsences();
	void setNext(ListNode *& newNext);

	int getRecord() const;
	int getID() const;
	string getName() const;
	string getEmail() const;
	int getUnits() const;
	string getMajor() const;
	string getLevel() const;
	int getNumAbsences() const;
	Stack * getAbsences();
	ListNode *& getNext();

	
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
	ListNode *& searchByName(string name);
	void listRecentAbsenses();
	void listByAbsenseCount(int minAbsenses);

	void import(string filename, bool overwrite);
	void save(string filename);

	void markAbsences(Date date);
	void editAbsences();
	void generateReport();
};