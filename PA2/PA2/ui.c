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

	while (TRUE)
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
			edit();
			c = MAINMENU;
			break;
		case SORT:

			c = MAINMENU;
			break;
		case RATE:
			rate();
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
			break;
		default:
			c = MAINMENU;
			break;
		}
	}
}


//complete
void load()
{
	system("cls");
	printf("Loading from musicPlayList.csv\n");

	FILE *infile = fopen("musicPlayList.csv", "r");

	loadRecord(infile, &pList);
	fclose(infile);
	printf("loaded records from CSV\n");
	sleep(3);
}

void store()
{
	system("cls");
	printf("Saving to musicPlayList.csv\n");
	FILE *infile = fopen("musicPlayList.csv", "w");

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
	fgets(artist, 50, stdin);
	c = atoi(artist);

	switch (c)
	{
	case 1:
		displayRecord(pList);
		break;
	case 2:
		printf("Enter artist: ");
		fgets(artist,50,stdin);

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
	char input[100];

	system("cls");
	clean();

	printf("(1)	edit/append Record\n(2)	search records based on artist\n");
	fgets(input, 100, stdin);
	c = atoi(input);



	switch (c)
	{
	case 1:

		printf("Enter album title: ");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;
		strcpy(tempRecord.albumTitle, input);

		printf("Enter artist: ");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;
		strcpy(tempRecord.artist, input);

		printf("Enter genre: ");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;
		strcpy(tempRecord.genre, input);

		printf("Enter song title: ");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;
		strcpy(tempRecord.songTitle, input);

		printf("Enter rating: ");
		fgets(input, 100, stdin);
		tempRecord.rating = atoi(input);

		printf("Enter times played: ");
		fgets(input, 100, stdin);
		tempRecord.timesPlayed = atoi(input);

		printf("Enter duration minutes: ");
		fgets(input, 100, stdin);
		tempRecord.songLength.minutes = atoi(input);

		printf("Enter duration seconds: ");
		fgets(input, 100, stdin);
		tempRecord.songLength.seconds = atoi(input);
		
		editRecord(&pList, tempRecord, TRUE);
		
		break;
	case 2:
		printf("Enter artist name: \n");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;
		strcpy(tempRecord.artist, input);

		displayRecordByArtist(pList, input, TRUE);

		printf("Enter song title: ");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;

		strcpy(tempRecord.songTitle, input);
		

		printf("Enter album title: ");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;

		strcpy(tempRecord.albumTitle, input);

		tempRecord.genre[0] = '\0';
		tempRecord.rating = -1;
		tempRecord.songLength.minutes = -1;
		tempRecord.songLength.seconds = -1;
		tempRecord.timesPlayed = -1;

		editRecord(&pList, tempRecord, FALSE);


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
	Record tempRecord;
	char input[100];

	system("cls");
	clean();


	printf("Enter artist name: \n");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = 0;
	strcpy(tempRecord.artist, input);

	displayRecordByArtist(pList, input, TRUE);

	printf("Enter song title: ");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = 0;

	strcpy(tempRecord.songTitle, input);


	printf("Enter album title: ");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = 0;

	strcpy(tempRecord.albumTitle, input);

	tempRecord.genre[0] = '\0';
	tempRecord.rating = -1;
	tempRecord.songLength.minutes = -1;
	tempRecord.songLength.seconds = -1;
	tempRecord.timesPlayed = -1;

	rateSong(pList, tempRecord);

	sleep(3);

}

void play()
{
	char input[50];
	Record tempRecord;

	system("cls");
	clean();

	printf("Enter artist name: \n");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = 0;
	strcpy(tempRecord.artist, input);

	displayRecordByArtist(pList, input, TRUE);

	printf("Enter song title: ");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = 0;

	strcpy(tempRecord.songTitle, input);


	printf("Enter album title: ");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = 0;

	strcpy(tempRecord.albumTitle, input);

	tempRecord.genre[0] = '\0';
	tempRecord.rating = -1;
	tempRecord.songLength.minutes = -1;
	tempRecord.songLength.seconds = -1;
	tempRecord.timesPlayed = -1;
	
	system("cls");
	playSong(pList, tempRecord);

	printf("Out of music to play!");

	sleep(3);
}

void shuffle()
{

}

void saveAndExit()
{
	store();
	exit(0);
}

void clean()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}