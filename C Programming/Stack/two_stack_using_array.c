/*
 * two_stack_using_array.c
 *
 *  Created on: Aug 22, 2018
 *      Author: prabhaka
 */
#include<stdio.h>

test_two_stack()
{
	CreateStackArr(3);
	Push1(1);
	Push2(2);
	Push1(4);
	Push2(3);
	PrintStacks();

}
int top1 = -1,top2 = 0;
int *stack = NULL;
int size = 0;
void CreateStackArr(int n)
{
	if(stack)
		free(stack);
	stack = malloc(sizeof(int) * n);
	size = n ;
	top2 = n;
	return;

}



void Push1(int data)
{
	if(top1 + 1 < top2)
	{
		top1++;
		stack[top1] = data;
	}
	else
	{
		printf("Stack is full \n");
	}
	return;
}


void Push2(int data)
{
	if(top1 + 1 < top2)//check for one space between two stacks
	{
		top2--;
		stack[top2] = data;
	}
	else
	{
		printf("Stack is full \n");
	}
	return;
}

int Pop1()
{
	if(top1 > -1)
	{
		int data = stack[top1];
		top1--;
		return data;
	}
	return 0;
}
int Pop2()
{
	if(top2 > size)
	{
		int data = stack[top2];
		top2++;
		return data;
	}
	return 0;
}

PrintStacks()
{
	int i = top1;
	printf("\nStack 1 --> ");

	for(;i >= 0 ; i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\nStack 2 --> ");
	i = top2;
	for(;i < size ; i++)
		{
			printf("%d ",stack[i]);
		}
}
