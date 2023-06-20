/*
 * reverse_stack.c
 *
 *  Created on: Aug 20, 2018
 *      Author: prabhaka
 */
/*logic
 * - use a recursion or stack to empty the stack
 * - insert the poped elements one by one at the bottom of stack. <<this is again a recursion>>
 *
 * */

/*logic 2:
 * - Pop all element and enqueue to a Queue.
 * - Dequeue from Queue and push it back to stack
 *
 * */
#include<stdio.h>
#include "Stack.h"
#include "Queue.h"

int test_reverseStack()
{
	STACK *s = CreateStack();
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	Push(s,&a[0]);
	Push(s,&a[1]);
	Push(s,&a[2]);
	Push(s,&a[3]);
	Push(s,&a[4]);
	Push(s,&a[5]);
	Push(s,&a[6]);
	Push(s,&a[7]);

	PrintStack(s);
	reverseUsingQ(s);
	//reverseStack(s);
	printf("\n");
	PrintStack(s);
	return 0;
}


void reverseStack(STACK *s)
{
	void *item = Pop(s);
	if(!item)
	{
		return;
	}
	reverseStack(s);
	insertAtBottom(s, item);
}

void insertAtBottom(STACK *s, void *data)
{
	void *temp = Pop(s);
	if(!temp)
	{
		Push(s,data);
		return;
	}
	insertAtBottom(s,data);
	Push(s,temp);
	//printf("\n");
	//PrintStack(s);
}

void reverseUsingQ(STACK *s)
{
	void *p = Pop(s);
	QUEUE *q = CreateNewQueue();
	while(p != NULL)
	{
	  Enqueue(q,p);
	  p = Pop(s);
	}

	p = Dequeue(q);
	while(p != NULL)
	{
	   Push(s,p);
	   p = Dequeue(q);
	}

}
