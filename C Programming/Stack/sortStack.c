/*
 * sortStack.c
 *
 *  Created on: Aug 20, 2018
 *      Author: prabhaka
 */

#include<stdio.h>
#include "Stack.h"
#include "Queue.h"
void test_sortingStack()
{
	STACK *s = CreateStack();
		int a[] = {10,9,8,77,6,5,4,3,2,1};
		Push(s,&a[0]);
		Push(s,&a[1]);
		Push(s,&a[2]);
		Push(s,&a[3]);
		Push(s,&a[4]);
		Push(s,&a[5]);
		Push(s,&a[6]);
		Push(s,&a[7]);

		PrintStack(s);
		//reverseUsingQ(s);
		sortStack(s);
		//reverseStack(s);
		printf("\n");
		PrintStack(s);
		return;

}
void sortStack(STACK *s)
{
	//

	if(Peep(s) == NULL)
		return;
	void *p = Pop(s);
	printf("*\n");
	sortStack(s);
	insertSorted(s,p);
}

void insertSorted(STACK *s, void *d)
{

	if((Peep(s) == NULL) || *((int *)Peep(s)) > (*(int *)d))
	{
		Push(s,d);
		return;
	}
	void *p = Pop(s);
	insertSorted(s,d);
	Push(s,p);
}

