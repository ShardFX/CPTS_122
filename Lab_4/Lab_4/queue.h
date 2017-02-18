#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct queueNode
{
	char *data;
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
QueueNode *makeNode(char *newData);
Boolean enqueue(Queue *queue, char *newData);
char *dequeue(Queue *queue);
Boolean printQueueRecursive(QueueNode *pHead);

#endif
