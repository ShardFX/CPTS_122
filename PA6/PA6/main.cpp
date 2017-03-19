#include "BST.h"
#include "fileio.h"

int main(void)
{
	BST morseCode = BST();
	
	fillBST(morseCode, "MorseTable.csv");
	convertAndDisplay("Convert.txt", morseCode);

	return 0;
}

