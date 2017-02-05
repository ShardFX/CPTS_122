#ifndef UI
#define UI

#include <stdio.h>
#include <string.h>


typedef enum commands {
	MAINMENU,LOAD,STORE,DISPLAY,INSERT,DELETE,EDIT,SORT,RATE,PLAY,SHUFFLE,EXIT
}Commands;


void mainMenu();

void load();

void store();

void display();

void insert();

void del();

void edit();

void sort();

void rate();

void play();

void shuffle();

void saveAndExit();

//clears stdin buffer
void clean();

int *randWithoutRep(int count);
#endif