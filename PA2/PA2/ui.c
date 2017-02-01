#include "ui.h"
#include "DoublyLinkedList.h"

static

Node *pList = NULL;

void mainMenu()
{
	system("cls");
	Commands c = 0;

	printf("Main Menu\n(1)   load\n(2)   store\n(3)   display\n(4)   insert\n(5)   delete\n(6)   edit\n(7)   sort\n(8)   rate\n(9)   play\n(10) shuffle\n(11) exit\n");
	scanf("%d", &c);

	while (c != EXIT)
	{
		switch (c)
		{
		case MAINMENU:
			mainMenu();
			break;
		case LOAD:
			load();
			c = MAINMENU;
			break;
		case STORE:
			store();
			c = MAINMENU;
			break;
		case DISPLAY:
			display();
			c = MAINMENU;
			break;
		case INSERT:

			c = MAINMENU;
			break;
		case DELETE:

			c = MAINMENU;
			break;
		case EDIT:

			c = MAINMENU;
			break;
		case SORT:

			c = MAINMENU;
			break;
		case RATE:

			c = MAINMENU;
			break;
		case PLAY:
			play();
			c = MAINMENU;
			break;
		case SHUFFLE:

			c = MAINMENU;
			break;
		case EXIT:
			saveAndExit();
			exit(0);
		default:
			mainMenu();
			break;
		}
	}
}


//complete
void load()
{
	system("cls");
	printf("Loading from musicPlayList.csv\n");

	FILE *infile = fopen("musicPlayList.csv", "r+");

	loadRecord(infile, &pList);
	fclose(infile);
	printf("loaded records from CSV\n");
	sleep(3);
}

void store()
{
	system("cls");
	printf("Saving to musicPlayList.csv\n");
	FILE *infile = fopen("musicPlayList.csv", "r+");

	storeRecord(infile, pList);
	fclose(infile);
	printf("Store success");
	sleep(3);
}


//complete
void display()
{
	system("cls");
	int c = 1;
	char artist[50];

	printf("(1)	Print all songs\n(2) Print songs by artist\n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		displayRecord(pList);
		break;
	case 2:
		printf("Enter artist: ");
		scanf("%[\n]s", artist);

		displayRecordByArtist(pList, artist,FALSE);
		break;
	default:
		display();
		break;
	}

	sleep(3);
}

void insert()
{

}

void del()
{

}

void edit()
{
	int c = 0;
	Record tempRecord;
	char tempString[100];
	int tempInt = 0;

	system("cls");

	printf("(1)	input Record\n(2)	search records based on artist\n");
	scanf("%d", &c);



	switch (c)
	{
	case 1:

		printf("Enter album title: ");
		scanf("%[^\n]s", tempString);

		strcpy(tempRecord.albumTitle, tempString);

		printf("Enter artist: ");
		scanf("%[^\n]s", tempString);

		strcpy(tempRecord.artist, tempString);

		printf("Enter genre: ");
		scanf("%[^\n]s", tempString);

		strcpy(tempRecord.genre, tempString);

		printf("Enter song title: ");
		scanf("%[^\n]s", tempString);

		strcpy(tempRecord.songTitle, tempString);

		printf("Enter rating: ");
		scanf("%d", &tempInt);

		tempRecord.rating = tempInt;

		printf("Enter times played: ");
		scanf("%d", &tempInt);

		tempRecord.timesPlayed = tempInt;

		printf("Enter duration minutes: ");
		scanf("%d", &tempInt);

		tempRecord.songLength.minutes = tempInt;

		printf("Enter duration seconds: ");
		scanf("%d", &tempInt);

		tempRecord.songLength.seconds = tempInt;
		
		editRecord(&pList, tempRecord, TRUE);
		
		break;
	case 2:
		printf("Enter artist name: \n");
		scanf("%[^\n]s", tempString);

		displayRecordByArtist(pList, tempString, TRUE);

		break;
	default:
		
		break;
	}

	sleep(3);

}

void sort()
{

}

void rate()
{
	char tempString[50];
	Record tempRecord;
	int tempInt;
	Boolean success = FALSE;

	printf("Enter album title: ");
	scanf("%[^\n]s", tempString);

	strcpy(tempRecord.albumTitle, tempString);

	printf("Enter artist: ");
	scanf("%[^\n]s", tempString);

	strcpy(tempRecord.artist, tempString);

	printf("Enter song title: ");
	scanf("%[^\n]s", tempString);
	strcpy(tempRecord.songTitle, tempString);

	printf("Enter new rating: ");
	scanf("%d", &tempInt);
	tempRecord.rating = tempInt;

	success = editRecord(&pList, tempRecord, FALSE);

	sleep(3);

}

void play()
{
	char tempString[50];
	Record tempRecord;

	printf("Enter album title: ");
	scanf("%[^\n]s", tempString);

	strcpy(tempRecord.albumTitle, tempString);

	printf("Enter artist: ");
	scanf("%[^\n]s", tempString);

	strcpy(tempRecord.artist, tempString);

	printf("Enter song title: ");
	scanf("%[^\n]s", tempString);
	strcpy(tempRecord.songTitle, tempString);
	
	playSong(pList, tempRecord);

	sleep(3);
}

void shuffle()
{

}

void saveAndExit()
{

}