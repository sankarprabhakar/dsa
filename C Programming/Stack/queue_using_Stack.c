/*
 * queue_using_Stack.c
 *
 *  Created on: Aug 22, 2018
 *      Author: prabhaka
 */

#include<stdio.h>
#include "Stack.h"
void * DequeueSQ();
void EnqueueSQ(void *d);
STACK *ip_stack = NULL; // input
STACK *op_stack = NULL; // output


void test_queue_using_stack()
{

	int a[] = {10,9,8,77,6,5,4,3,2,1};
	EnqueueSQ(&a[0]);
	EnqueueSQ(&a[1]);
	EnqueueSQ(&a[2]);
	EnqueueSQ(&a[3]);
	EnqueueSQ(&a[4]);
	EnqueueSQ(&a[5]);
	EnqueueSQ(&a[6]);
	EnqueueSQ(&a[7]);
 int i = 0;
     printf("Enqueue order \n");
//	for(i = 0 ; i < 8;i++)
//	{
//		printf(" %d ", a[i]);
//	}
	PrintStack(ip_stack);
	 printf("\nDequeue order \n");
		for(i = 0 ; i < 8;i++)
		{
			printf(" %d ", *(int *)DequeueSQ());
		}
}



void EnqueueSQ(void *d)
{
	if(ip_stack == NULL)
	{
		ip_stack = CreateStack();
	}
	Push(ip_stack,d);
	return;
}

void * DequeueSQ()
{
	if(op_stack == NULL)
	{
		op_stack = CreateStack();
	}
	if(Peep(op_stack) == NULL)
	{
		while(Peep(ip_stack) != NULL)
		{
			void *d = Pop(ip_stack);
			Push(op_stack, d);
		}
	}

	return 	Pop(op_stack);

}




