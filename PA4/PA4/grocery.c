#include "grocery.h"


void runGroceryQueue(Queue *express, Queue *normal, int runTime)
{
	srand(time(NULL));
	int currentTime = 1, 
		expressArrivalTime = (rand() % 4 + 1) + currentTime, 
		normalArrivalTime = (rand() % 4 + 3) + currentTime,
		totalExpressTime = 0, 
		totalNormalTime = 0, 
		eCustomer = 1, 
		nCustomer = 1;


	while (currentTime <= runTime)
	{
		//gen new express lane customer
		if (expressArrivalTime == currentTime)
		{
			int temp = (rand() % 4 + 1);
			totalExpressTime += temp;
			enqueue(express, eCustomer, temp + currentTime, totalExpressTime);

			expressArrivalTime = (rand() % 4 + 1) + currentTime;//gen new customer
			eCustomer++;
		}
		//gen new normal lane customer
		if (normalArrivalTime == currentTime)
		{
			int temp = (rand() % 4 + 3);
			totalNormalTime += temp;
			enqueue(normal, nCustomer, temp + currentTime, totalNormalTime);

			normalArrivalTime = (rand() % 4 + 3) + currentTime;//gen new customer
			nCustomer++;
		}
		//express finished customer
		if (express->pHead != NULL && express->pHead->serviceTime <= currentTime)
		{
			dequeue(express);
		}
		if (normal->pHead != NULL && normal->pHead->serviceTime <= currentTime)
		{
			dequeue(normal);
		}

		//normal finished customer
		if (currentTime == 1440)//reset customer numbers on new day
		{
			eCustomer = nCustomer = 1;
		}

		//if day is over reset customer number
		if (currentTime % 10 == 0)
		{
			printf("Express Queue:\n");
			printQueueRecursive(express->pHead);

			printf("Normal Queue:\n");
			printQueueRecursive(normal->pHead);
		}


		currentTime++;
	}



}





