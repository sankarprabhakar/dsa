/*
 * Stacking_using_queue.c
 *
 *  Created on: Aug 22, 2018
 *      Author: prabhaka
 */
#include<stdio.h>
#include "Stack.h"
#include "Queue.h"

void PushQS(void *d);
void* PopQS();
QUEUE *ip_queue = NULL;
QUEUE *op_queue = NULL;
test_stack_using_Queue()
{
	int a[] = {10,9,8,77,6,5,4,3,2,1};

	PushQS(&a[0]);
	PushQS(&a[1]);
	PushQS(&a[2]);
	PushQS(&a[3]);
	PushQS(&a[4]);
	PushQS(&a[5]);
	PushQS(&a[6]);
	PushQS(&a[7]);
	PushQS(&a[8]);

	int i = 0;
	     printf("Push order \n");
		for(i = 0 ; i < 9;i++)
		{
			printf(" %d ", a[i]);
		}
		PrintStack(ip_queue);
		 printf("\nPop order \n");
			for(i = 0 ; i < 9;i++)
			{
				printf(" %d ", *(int *)PopQS());
			}

}

void PushQS(void *d)
{
	if(ip_queue == NULL && op_queue == NULL)
	{
		ip_queue = CreateNewQueue();
		op_queue = CreateNewQueue();
	}

	Enqueue(ip_queue,d);
	while(SizeOfQ(op_queue) != 0)
	{
		void *val = Dequeue(op_queue);
		Enqueue(ip_queue,val);
	}
	/*Exchange the pointers*/
	QUEUE *t = ip_queue;
	ip_queue = op_queue;
	op_queue = t;
	return;
}


void* PopQS()
{
	if(ip_queue == NULL || op_queue == NULL)
	{
		return NULL;
	}
	void *val = Dequeue(op_queue);
	return val;
}
