#include "queue.h"

Boolean isEmpty(Queue *queue)
{
	return (queue->pHead == NULL) ? FALSE : TRUE;
}
 
QueueNode *makeNode(char *newData)
{
	QueueNode *pMem = malloc(sizeof(QueueNode));
	char *data = malloc(sizeof(char) * strlen(newData) + 1);
	strcpy(data, newData);
	pMem->data = data;

	pMem->pNext = NULL;
}

Boolean enqueue(Queue *queue, char *newData)
{
	Boolean success = FALSE;

	if (queue->pHead == NULL)
	{
		queue->pHead = makeNode(newData);
		queue->pTail = queue->pHead;
		success = TRUE;
	}
	else
	{
		QueueNode *pMem = makeNode(newData);
		pMem->pNext = queue->pHead;
		queue->pHead = pMem;
		success = TRUE;
	}
	return success;
}

char *dequeue(Queue *queue)
{
	char *data = malloc(sizeof(char) * strlen(queue->pHead->data) + 1);
	QueueNode *pTemp = NULL;
	if (queue->pHead == queue->pTail)
	{
		strcpy(data, queue->pHead->data);
		free(queue->pHead->data);
		free(queue->pHead);
		queue->pHead = queue->pTail = NULL;
	}
	else
	{
		pTemp = queue->pHead->pNext;
		strcpy(data, queue->pHead->data);
		free(queue->pHead->data);
		free(queue->pHead);
		queue->pHead = pTemp;
	}

	return data;
	}

Boolean printQueueRecursive(QueueNode *pHead)
{
	if (pHead == NULL)
	{
		return TRUE;
	}

	printf("%s\n", pHead->data);

	return printQueueRecursive(pHead->pNext);

}