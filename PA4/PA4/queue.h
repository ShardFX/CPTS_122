#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct queueNode
{
	int customerNumber;
	int serviceTime;
	int totalTime;

	struct queueNode *pNext;

}QueueNode;


typedef struct queue
{
	struct queueNode *pHead;
	struct queueNode *pTail;

}Queue;

typedef enum boolean
{
	TRUE, FALSE
}Boolean;


Boolean isEmpty(Queue *queue);
QueueNode *makeNode(int customerNumber, int serviceTime, int totalTime);
Boolean enqueue(Queue *queue, int customerNumber, int serviceTime, int totalTime);
void dequeue(Queue *queue);
Boolean printQueueRecursive(QueueNode *pHead);

#endif
