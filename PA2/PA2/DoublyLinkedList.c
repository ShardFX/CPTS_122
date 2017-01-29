#include"DoublyLinkedList.h"


Duration splitDurationString(char durationString[5])
{
	Duration tDuration;
	char * token;
	token = strtok(durationString, ":");
	tDuration.minutes = token;

	token = strtok(NULL, ":");
	tDuration.seconds = token;
	return tDuration;


}

Node * makeNode(Record newData)
{
	Node * pMem = (Node*)malloc(sizeof(Node));

	strcpy(pMem->data.albumTitle, newData.albumTitle);
	strcpy(pMem->data.artist, newData.artist);
	strcpy(pMem->data.genre, newData.genre);
	strcpy(pMem->data.songTitle, newData.songTitle);

	pMem->data.rating = newData.rating;
	pMem->data.timesPlayed = newData.timesPlayed;
	pMem->data.songLength.minutes = newData.songLength.minutes;
	pMem->data.songLength.seconds = newData.songLength.seconds;

	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}

Boolean insertFront(Node **pList, Record newData)
{
	Node * pMem = makeNode(newData), * pCur = NULL;
	
	Boolean success = FALSE;

	pCur = *pList;
	if (pCur == NULL)
	{
		*pList = pMem;
		success = TRUE;
	}
	else
	{
		pMem->pNext = *pList;
		pMem->pPrev = NULL;
		pCur->pNext->pPrev = pMem;
		*pList = pMem;
		success = TRUE;
	}
	return success;

}

Boolean loadRecord(FILE *infile, Node **pList)
{
	char fileByLine[1000], *token;
	Record pTemp;

	Boolean success = FALSE;
	//no header file
	//fgets(fileByLine, 1000, infile);

	while (fgets(fileByLine, 1000, infile) != NULL)
	{
		token = strtok(fileByLine, ",");
		strcpy(pTemp.artist, token);

		token = strtok(NULL, ",");
		strcpy(pTemp.albumTitle, token);

		token = strtok(NULL, ",");
		strcpy(pTemp.songTitle, token);

		token = strtok(NULL, ",");
		strcpy(pTemp.genre, token);

		token = strtok(NULL, ",");
		pTemp.songLength = splitDurationString(token);

		token = strtok(NULL, ",");
		pTemp.timesPlayed = atoi(token);

		token = strtok(NULL, ",");
		pTemp.rating = atoi(token);

		success = insertFront(pList, pTemp);
	}
	return success;
}

Boolean storeRecord(FILE *infile, Node *pList)
{
	Node *pCur = NULL;
	Boolean success = TRUE;

	if (infile == NULL)
		success = FALSE;

	while (pCur != NULL)
	{
		fprintf(infile, "%s,%s,%s,%s,%i:%i,%i,%i\n",
			pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre,
			pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.timesPlayed,
			pCur->data.rating);
		pCur = pCur->pNext;
	}
	return success;
}

Boolean displayRecord(Node *pList)
{
	Node *pCur = NULL;
	pCur = pList;

	while (pCur != NULL)
	{
		printf("%s, %s, %s, %s, %i:%i, %i, %i\n", 
			pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre,
			pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.timesPlayed,
			pCur->data.rating);
		pCur = pCur->pNext;
	}
}

Boolean editRecord(Node *pList, Record searchContact)
{
	Node *pCur = NULL, *pPrev = NULL;
	Boolean success = FALSE;
	char charInput[50];
	int intInput;

	pCur = pList;
	if (pCur != NULL)
	{
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.songTitle, searchContact.songTitle) == 0 &&
				strcmp(pCur->data.artist, searchContact.artist) == 0 &&
				strcmp(pCur->data.albumTitle, searchContact.albumTitle) == 0
				)
			{
				printf("Enter new Genre for %s\n", searchContact.songTitle);
				scanf("%s", charInput);
				strcpy(pCur->data.genre, charInput);

				printf("Enter new rating for %s\n", searchContact.songTitle);
				scanf("%i", intInput);
				pCur->data.rating = intInput;

				success = TRUE;
			}
			pPrev = pCur;
			pCur = pCur->pNext;
		}
	}
	return success;
}

Boolean rateSong(Node *pList, Record searchContact)
{
	Node *pCur = NULL, *pPrev = NULL;
	Boolean success = FALSE;
	int tempInput;

	pCur = pList;
	if (pCur != NULL)
	{
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.songTitle, searchContact.songTitle) == 0 &&
				strcmp(pCur->data.artist, searchContact.artist) == 0 &&
				strcmp(pCur->data.albumTitle, searchContact.albumTitle) == 0
				)
			{
				printf("Enter new rating for %s\n", searchContact.songTitle);
				scanf("%i", tempInput);
				pCur->data.rating = tempInput;
			}
		}
	}
	return success;
}

Boolean playSong(Node *pList, Record searchContact)
{
	Node *pCur = NULL;
	Boolean success = FALSE;

	pCur = pList;

	while (pCur != NULL)
	{
		if (strcmp(pCur->data.songTitle, searchContact.songTitle) == 0 &&
			strcmp(pCur->data.artist, searchContact.artist) == 0 &&
			strcmp(pCur->data.albumTitle, searchContact.albumTitle) == 0
			)
		{

			success = TRUE;
		}

		if (success)
		{
			printf("%s, %s, %s, %s, %i:%i, %i, %i\n",
				pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre,
				pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.timesPlayed,
				pCur->data.rating);
			sleep(2);
		}
		pCur = pCur->pNext;
	}
}

void exit()
{

}