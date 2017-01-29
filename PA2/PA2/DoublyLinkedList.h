#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record 
{
	char artist[50];
	char albumTitle[100];
	char songTitle[100];
	char genre[30];
	Duration songLength;
	int timesPlayed;
	int rating;
}Record;

typedef struct node
{
	Record data;
	Node *pPrev;
	Node *pNext;
}Node;

typedef enum boolean
{
	FALSE, TRUE
}Boolean;

Duration splitDurationString(char durationString[5]);

//Allocates memory for new Node
Node * makeNode(Record newData);

//Inserts new Node at front of list
Boolean insertFront(Node **pList, Record newData);

//fills list from CSV
Boolean loadRecord(FILE *infile, Node **pList);

//Stores list to CSV
Boolean storeRecord(FILE *infile, Node *pList);

//Displays all record nodes
Boolean displayRecord(Node *pList);

//edits single node
Boolean editRecord(Node *pList, Record searchContact);

//overwrites existing rating
Boolean rateSong(Node *pList, Record searchContact);

//plays from search node location to end of list
Boolean playSong(Node *pList, Record searchContact);

//saves to CSV and stops program
void exit();

#endif
