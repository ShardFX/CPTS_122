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

			c = MAINMENU;
			break;
		case SHUFFLE:

			c = MAINMENU;
			break;
		default:
			mainMenu();
			break;
		}
	}
}

void load()
{

	FILE *infile = fopen("musicPlayList.csv", "r+");

	loadRecord(infile, &pList);
	printf("loaded records from CSV");
	sleep(3);

}

void store()
{

}

void display()
{
	displayRecord(pList);
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

}

void sort()
{

}

void rate()
{

}

void play()
{
	record()
	playSong(pList,)
}

void shuffle()
{

}
