/*
 * stack_using_queue.c
 *
 *  Created on: Aug 28, 2018
 *      Author: prabhaka
 */

#include<stdio.h>
#include "Queue.h"
void *popSingleQueue();
QUEUE *stack_queue = NULL;
test_stack_using_one_queue()
{
	int a[] = {10,9,8,77,6,5,4,3,2,1};

	pushSingleQueue(&a[0]);
	pushSingleQueue(&a[1]);
	pushSingleQueue(&a[2]);
		pushSingleQueue(&a[3]);
		pushSingleQueue(&a[4]);
		pushSingleQueue(&a[5]);
		pushSingleQueue(&a[6]);
		pushSingleQueue(&a[7]);
		pushSingleQueue(&a[8]);

		int i = 0;
		     printf("Push order \n");
			for(i = 0 ; i < 9;i++)
			{
				printf(" %d ", a[i]);
			}
			printf("\n");
			PrintStacksSingleQueue(stack_queue);
			// printf("\nPop order \n");
				for(i = 0 ; i < 9;i++)
				{
					//printf(" %d ", *(int *)popSingleQueue());
				}


}



void pushSingleQueue(void *d)
{
	if(stack_queue == NULL)
	{
		stack_queue = CreateNewQueue();
		Enqueue(stack_queue,d);
		return;
	}
	int size = SizeOfQ(stack_queue);
	Enqueue(stack_queue,d);
	while(size > 0 )
	{
		size--;
		void *p = Dequeue(stack_queue);
		Enqueue(stack_queue,p);
	}
	return;
}

void *popSingleQueue()
{
	if(stack_queue == NULL)
	{
		return NULL;
	}

	return Dequeue(stack_queue);
}


PrintStacksSingleQueue()
{
	void *p = popSingleQueue();
	while(p)
	{
		printf("%d - ", *(int *)p);
		p = popSingleQueue();
	}
	printf("\n");
}
