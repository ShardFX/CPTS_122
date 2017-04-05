#include "LinkedList.h"

/*
Definitions for List Node
*/
ListNode::ListNode()
{
	mID = 111;
	pNext = nullptr;
}

ListNode::ListNode(int record, int id, string name, string email, int units, string major, string level, Stack absences, int numAbsences)
{
	mRecord = record;
	mID = id;
	mName = name;
	mEmail = email;
	mUnits = units;
	mMajor = major;
	mLevel = level;
	mAbsences = absences;
	mNumAbsences = numAbsences;
	pNext = nullptr;
}

ListNode::ListNode(ListNode *& newListNode)
{
	mRecord = newListNode->getRecord();
	mID = newListNode->getID();
	mName = newListNode->getName();
	mEmail = newListNode->getEmail();
	mUnits = newListNode->getUnits();
	mMajor = newListNode->getMajor();
	mLevel = newListNode->getLevel();
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

void ListNode::setName(string name)
{
	mName = name;
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

void ListNode::setLevel(string level)
{
	mLevel = level;
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

string ListNode::getName() const
{
	return mName;
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

string ListNode::getLevel() const
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

ListNode *& List::searchByName(string name)
{
	ListNode * cur = mHead;
	while (cur != nullptr)
	{
		if (cur->getName() == name)
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

void List::import(string filename, bool overwrite)
{
	ifstream file = ifstream(filename);
	string line, Record, ID, Name, Email, Units, Program, level;
	stringstream ss;
	getline(file, line);//kills header line

	if (overwrite)
	{
		while (getline(file, line))
		{
			ss << line;
			getline(ss, Record, ',');
			getline(ss, ID, '"');
			getline(ss, Name, '"');
			getline(ss, Email, ',');
			getline(ss, Email, ',');
			getline(ss, Units, ',');
			getline(ss, Program, ',');
			getline(ss, level, ',');

			ListNode *node = new ListNode(stoi(Record), stoi(ID), Name, Email, stoi(Units), Program, level, Stack(), 0);

			this->insertAtFront(node);
		}
	}
	else
	{
		this->mHead = nullptr;
		while (getline(file, line))
		{
			ss << line;
			getline(ss, Record, ',');
			getline(ss, ID, '"');
			getline(ss, Name, '"');
			getline(ss, Email, ',');
			getline(ss, Email, ',');
			getline(ss, Units, ',');
			getline(ss, Program, ',');
			getline(ss, level, ',');

			ListNode *node = new ListNode(stoi(Record), stoi(ID), Name, Email, stoi(Units), Program, level, Stack(), 0);

			this->insertAtFront(node);
		}
	}
}
