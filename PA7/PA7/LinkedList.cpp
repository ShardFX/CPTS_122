#include "LinkedList.h"

/*
Definitions for List Node
*/
ListNode::ListNode()
{
	mID = 111;
	pNext = nullptr;
}

ListNode::ListNode(int record, int id, string firstName, string lastName, string email, int units, string major, Level level, Stack absences, int numAbsences)
{
	mRecord = record;
	mID = id;
	mFName = firstName;
	mLName = lastName;
	mEmail = email;
	mUnits = units;
	mMajor = major;
	mAbsences = absences;
	mNumAbsences = numAbsences;
	pNext = nullptr;
}

ListNode::ListNode(ListNode *& newListNode)
{
	mRecord = newListNode->getRecord();
	mID = newListNode->getID();
	mFName = newListNode->getFirstName();
	mLName = newListNode->getLastName();
	mEmail = newListNode->getEmail();
	mUnits = newListNode->getUnits();
	mMajor = newListNode->getMajor();
	mAbsences = newListNode->mAbsences;
	mNumAbsences = newListNode->getNumAbsences();
	pNext = newListNode->getNext();
}

ListNode::~ListNode()
{
}

void ListNode::setRecord(int record)
{
	mRecord = record;
}

void ListNode::setID(int ID)
{
	mID = ID;
}

void ListNode::setFirstName(string firstName)
{
	mFName = firstName;
}

void ListNode::setLastName(string lastName)
{
	mLName = lastName;
}

void ListNode::setEmail(string email)
{
	mEmail = email;
}

void ListNode::setUnits(int units)
{
	mUnits = units;
}

void ListNode::setMajor(string major)
{
	mMajor = major;
}

void ListNode::setLevel(enum Level l)
{
	mLevel = l;
}

void ListNode::setTotalNumAbsences(int totalAbsences)
{
	mNumAbsences = totalAbsences;
}

void ListNode::incrementAbsences()
{
	mNumAbsences++;
}

void ListNode::setNext(ListNode *& newNext)
{
	pNext = newNext;
}

int ListNode::getRecord() const
{
	return mRecord;
}

int ListNode::getID() const
{
	return mID;
}

string ListNode::getFirstName() const
{
	return mFName;
}

string ListNode::getLastName() const
{
	return mLName;
}

string ListNode::getEmail() const
{
	return mEmail;
}

int ListNode::getUnits() const
{
	return mUnits;
}

string ListNode::getMajor() const
{
	return mMajor;
}

Level ListNode::getLevel() const
{
	return mLevel;
}

int ListNode::getNumAbsences() const
{
	return mNumAbsences;
}

Stack ListNode::getAbsences()
{
	return mAbsences;
}

ListNode *& ListNode::getNext()
{
	return pNext;
}


/*
Definitions for List
*/
List::List()
{
	mHead = nullptr;
}

List::List(List *& newList)
{
	mHead = newList->mHead;
}

List::~List()
{
}

bool List::insertAtFront(ListNode *& newNode)
{
	if (mHead != nullptr)
	{
		newNode->setNext(mHead);
		mHead = newNode;
		return true;
	}
	else
	{
		mHead = newNode;
		return true;
	}
}

ListNode *& List::searchByID(int ID)
{
	ListNode * cur = mHead;
	while (cur != nullptr)
	{
		if (cur->getID() == ID)
		{
			return cur;
		}
		cur = cur->getNext();
	}
}

ListNode *& List::searchByName(string firstName, string lastName)
{
	ListNode * cur = mHead;
	while (cur != nullptr)
	{
		if (cur->getFirstName() == firstName && cur->getLastName() == lastName)
		{
			return cur;
		}
		cur = cur->getNext();
	}
}

void List::listRecentAbsenses()
{
	ListNode * cur = mHead;
	Date tempDate;
	while (cur != nullptr)
	{
		if (cur->getNumAbsences() > 0)
		{
			cout << cur->getID() << " : ";
			cur->getAbsences().peek(tempDate);
			tempDate.print();
		}
		cur = cur->getNext();
	}
}

void List::listByAbsenseCount(int minAbsenses)
{
	ListNode * cur = mHead;
	while (cur != nullptr)
	{
		cout << cur->getID() << " : " << cur->getNumAbsences() << endl;
		cur = cur->getNext();
	}
}

void List::import(string filename)
{

}
