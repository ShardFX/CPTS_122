#include "queue.h"


int main(void)
{
	char *output = NULL;
	Queue *testQueue = malloc(sizeof(Queue));
	testQueue->pHead = testQueue->pTail = NULL;

	if (isEmpty(testQueue))
		printf("queue is empty\n");
	else
		printf("queue is not empty\n");





	enqueue(testQueue, "test1");
	enqueue(testQueue, "test2");
	enqueue(testQueue, "test3");
	enqueue(testQueue, "test4");
	enqueue(testQueue, "test5");
	
	if (isEmpty(testQueue))
		printf("queue is empty\n");
	else
		printf("queue is not empty\n");

	printQueueRecursive(testQueue->pHead);

	output = dequeue(testQueue);
	
	printf("%s\n", output);
	
	printf("%s\n", output);
	free(output);

	return 0;
}


