#include "queue.h"

Boolean isEmpty(Queue *queue)
{
	return (queue->pHead == NULL) ? FALSE : TRUE;
}
 
QueueNode *makeNode(int customerNumber, int serviceTime, int totalTime)
{
	QueueNode *pMem = malloc(sizeof(QueueNode));
	
	pMem->customerNumber = customerNumber;
	pMem->serviceTime = serviceTime;
	pMem->totalTime = totalTime;
	pMem->pNext = NULL;

	return pMem;
}

Boolean enqueue(Queue *queue, int customerNumber, int serviceTime, int totalTime)
{
	Boolean success = FALSE;

	if (queue->pHead == NULL)
	{
		queue->pHead = queue->pTail = makeNode(customerNumber, serviceTime, totalTime);
		success = TRUE;
	}
	else
	{
		queue->pTail->pNext = makeNode(customerNumber, serviceTime, totalTime);
		queue->pTail = queue->pTail->pNext;
		success = TRUE;
	}
	return success;
}

void dequeue(Queue *queue)
{
	QueueNode *pTemp = NULL;
	if (queue->pHead == queue->pTail)
	{
		free(queue->pHead);
		queue->pHead = queue->pTail = NULL;
	}
	else
	{
		pTemp = queue->pHead->pNext;
		free(queue->pHead);
		queue->pHead = pTemp;
	}
}

Boolean printQueueRecursive(QueueNode *pHead)
{
	if (pHead == NULL)
	{
		return TRUE;
	}

	printf("Customer:%d Service Time:%d Total Queue Time:%d\n", pHead->customerNumber, pHead->serviceTime, pHead->totalTime);

	return printQueueRecursive(pHead->pNext);
}