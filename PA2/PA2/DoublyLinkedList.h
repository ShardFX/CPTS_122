#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	Record data;
	Node *pPrev;
	Node *pNext;
}Node;

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

//Allocates memory for new Node
int makeNode(Node **pList, Record newData);

//Inserts new Node at front of list
int insertFront(Node **pList, Record newData);

//fills list from CSV
int loadRecord(FILE *infile);

//Stores list to CSV
int storeRecord();

//Displays all record nodes
int displayRecord();

//edits single node
int editRecord();

//overwrites existing rating
int rateSong();

//plays from search node location to end of list
int playSong();

//saves to CSV and stops program
void exit();

#endif
