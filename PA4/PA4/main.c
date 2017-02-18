#include "queue.h"
#include "grocery.h"

int main(void)
{
	Queue *express = malloc(sizeof(Queue)), *normal = malloc(sizeof(Queue));
	express->pHead = express->pTail = normal->pHead = normal->pTail = NULL;

	
	//loop 1 min steps for n minutes
	runGroceryQueue(express, normal, 2000);



	return 0;
}