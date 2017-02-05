#include"DoublyLinkedList.h"


Duration splitDurationString(char durationString[5])
{
	Duration tDuration;
	char * token;
	token = strtok(durationString, ":");
	tDuration.minutes = atoi(token);

	token = strtok(NULL, ":");
	tDuration.seconds = atoi(token);
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
	Node * pMem = makeNode(newData), *pCur = NULL;

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
		pCur->pPrev = pMem;
		pMem->pPrev = NULL;
		*pList = pMem;
		success = TRUE;
	}
	return success;

}

Boolean loadRecord(FILE *infile, Node **pList)
{
	char fileByLine[1000], *token, *tempDuration, first[25], last[25];
	Record pTemp;

	Boolean success = FALSE;
	//no header file
	//fgets(fileByLine, 1000, infile);

	while (fgets(fileByLine, 1000, infile) != NULL)
	{
		
		token = strtok(fileByLine, ",");
		
		if (token[0] == 34) {
			//removes leading '\"'
			strcpy(last, token + 1);

			token = strtok(NULL, ",");
			// removes trailing '\"'
			strcpy(first, token);
			first[strlen(first) - 1] = ' ';
			strcat(first, last);
			strcpy(pTemp.artist, first + 1);


			token = strtok(NULL, ",");
			strcpy(pTemp.albumTitle, token);
		}
		else
		{
			strcpy(pTemp.artist, token);

			token = strtok(NULL, ",");
			strcpy(pTemp.albumTitle, token);
		}

		token = strtok(NULL, ",");
		strcpy(pTemp.songTitle, token);

		token = strtok(NULL, ",");
		strcpy(pTemp.genre, token);

		token = strtok(NULL, ",");
		tempDuration = token;

		token = strtok(NULL, ",");
		pTemp.timesPlayed = atoi(token);

		token = strtok(NULL, ",");
		pTemp.rating = atoi(token);

		pTemp.songLength = splitDurationString(tempDuration);

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

	pCur = pList;
	while (pCur != NULL)
	{
		fprintf(infile, "%s,%s,%s,%s,%i:%i,%i,%i",
			pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre,
			pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.timesPlayed,
			pCur->data.rating);
		if (pCur->pNext != NULL)
		{
			fprintf(infile, "\n");
		}
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

Boolean displayRecordByArtist(Node *pList, char artist[50], Boolean numerical)
{
	Boolean success = FALSE;
	Node *pCur = NULL;
	int position = 0;

	pCur = pList;

	//cull newline character from string.


	while (pCur != NULL)
	{
		if (strcmp(pCur->data.artist, artist) == 0)
		{
			if (numerical)
			{
				printf("(%d)	%s, %s, %s, %s, %i:%i, %i, %i\n", position,
					pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre,
					pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.timesPlayed,
					pCur->data.rating);
				position++;
			}
			else
			{
				printf("%s, %s, %s, %s, %i:%i, %i, %i\n",
					pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre,
					pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.timesPlayed,
					pCur->data.rating);
			}
			
			
			success = TRUE;

		}
		pCur = pCur->pNext;
	}
	if (!success)
		printf("No artist matches found\n");
}

Boolean editRecord(Node **pList, Record searchContact, Boolean append)
{
	Node *pCur = NULL, *pPrev = NULL;
	Boolean success = FALSE;
	char input[50];

	pCur = *pList;
	while (pCur != NULL)
	{
		//compares title, artist, songtitle to ensure correct record
		if (strcmp(pCur->data.songTitle, searchContact.songTitle) == 0 &&
			strcmp(pCur->data.artist, searchContact.artist) == 0 &&
			strcmp(pCur->data.albumTitle, searchContact.albumTitle) == 0
			)
		{
			if (searchContact.genre[0] == '\0')
			{
				printf("Enter new Genre for %s\n", searchContact.songTitle);
				fgets(input, 50, stdin);
				input[strlen(input) - 1] = 0;
				strcpy(pCur->data.genre, input);
			}
			else
			{
				strcpy(pCur->data.genre, searchContact.genre);
			}

			if (searchContact.rating == -1)
			{
				printf("Enter new rating for %s\n", searchContact.songTitle);
				fgets(input, 50, stdin);
				pCur->data.rating = atoi(input);
			}
			else
			{
				pCur->data.rating = searchContact.rating;
			}
			if (searchContact.timesPlayed == -1)
			{
				printf("Enter times played: ");
				fgets(input, 100, stdin);
				pCur->data.timesPlayed = atoi(input);
			}
			else
			{
				pCur->data.timesPlayed = searchContact.timesPlayed;
			}
			if (searchContact.songLength.minutes == -1)
			{
				printf("Enter duration minutes: ");
				fgets(input, 100, stdin);
				pCur->data.songLength.minutes = atoi(input);
			}
			else
			{
				pCur->data.songLength.minutes = searchContact.songLength.minutes;
			}
			if (searchContact.songLength.seconds == -1)
			{
				printf("Enter duration seconds: ");
				fgets(input, 100, stdin);
				pCur->data.songLength.seconds = atoi(input);
			}
			else
			{
				pCur->data.songLength.seconds = searchContact.songLength.seconds;
			}
			success = TRUE;
		}
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	// append as new node if doesnt match any in list
	if (append && !success) 
	{
		insertFront(pList, searchContact);
		success = TRUE;
	}
	return success;
}

Boolean deleteRecord(Node **pList, Record searchContact)
{
	Node *pCur = NULL, *pPrev = NULL, *pNext = NULL;
	Boolean success = FALSE;
	char input[50];

	pCur = *pList;
	while (pCur != NULL)
	{
		//compares title, artist, songtitle to ensure correct record
		if (strcmp(pCur->data.songTitle, searchContact.songTitle) == 0 &&
			strcmp(pCur->data.artist, searchContact.artist) == 0 &&
			strcmp(pCur->data.albumTitle, searchContact.albumTitle) == 0
			)
		{
			if (pNext == NULL)
			{
				pPrev->pNext = pNext;
			}
			else
			{
				pPrev->pNext = pNext;
				pNext->pPrev = pPrev;
			}
			return TRUE;
		}
		pPrev = pCur;
		pCur = pCur->pNext;
		pNext = pCur->pNext;
	}

}

Boolean rateSong(Node *pList, Record searchContact)
{
	Node *pCur = NULL, *pPrev = NULL;
	Boolean success = FALSE;
	char input[10];

	pCur = pList;
	while (pCur != NULL)
	{
		if (strcmp(pCur->data.songTitle, searchContact.songTitle) == 0 &&
			strcmp(pCur->data.artist, searchContact.artist) == 0 &&
			strcmp(pCur->data.albumTitle, searchContact.albumTitle) == 0
			)
		{
			printf("Enter new rating for %s:\n", searchContact.songTitle);
			fgets(input, 50, stdin);
			pCur->data.rating = atoi(input);
		}

		pCur = pCur->pNext;
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

Boolean sortRecords(Node *pList, int sortType)
{
	Record prevData;
	Node *pCur = NULL, *pNext = NULL;
	int count = 1;

	while (TRUE)
	{
		if (pNext == NULL)
		{
			pCur = pList;
			pNext = pCur->pNext;
			if (count == 0)
			{
				return TRUE;
			}
			count = 0;
		}

		if (sortType == 1)
		{
			if (strcmp(pCur->data.artist, pNext->data.artist) > 0)
			{
				//swap data
				prevData = pCur->data;
				pCur->data = pNext->data;
				pNext->data = prevData;
				count++;
			}
		}
		if (sortType == 2)
		{
			if (strcmp(pCur->data.albumTitle, pNext->data.albumTitle) > 0)
			{
				//swap data
				prevData = pCur->data;
				pCur->data = pNext->data;
				pNext->data = prevData;
				count++;
			}
		}
		if (sortType == 3)
		{
			if (pCur->data.rating < pNext->data.rating)
			{
				//swap data
				prevData = pCur->data;
				pCur->data = pNext->data;
				pNext->data = prevData;
				count++;
			}
		}
		if (sortType == 4)
		{
			if (pCur->data.timesPlayed < pNext->data.timesPlayed)
			{
				//swap data
				prevData = pCur->data;
				pCur->data = pNext->data;
				pNext->data = prevData;
				count++;
			}
		}
		pCur = pNext;
		pNext = pCur->pNext;

	}



}

void sleep(int seconds)
{
	int startTime = time(0);
	while (time(0) < startTime + seconds);
}