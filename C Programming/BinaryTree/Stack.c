/*
 * Stack.c
 *
 *  Created on: Jun 8, 2016
 *      Author: sankarsa
 */
#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

//typedef struct stack_node{
//	void *data;
//	struct node *next;
//	struct node *prev;
//}STACK_NODE;
//
//typedef struct stack
//{
//	STACK_NODE *top;
//
//}STACK;
//
//STACK_NODE *CreateStackNode(void *data);
//STACK *CreateStack();
//STACK * Push(STACK *s, void *data);
//void * Pop(STACK *s);
//void * Peep(STACK *s);
//void  PrintStack(STACK *s);

STACK_NODE *CreateStackNode(void *data)
{
	STACK_NODE *new_node = malloc(sizeof(STACK_NODE));
	new_node->data =data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;

}

STACK * CreateStack()
{
	STACK *s = malloc(sizeof(STACK));
	s->top = NULL;
	return s;
}


STACK * Push(STACK *s, void *data)
{
	STACK_NODE *new_node = CreateStackNode(data);
	new_node->next = s->top;
	if(s->top)
		s->top->prev = new_node;
	s->top = new_node;
	return s;
}

void * Pop(STACK *s)
{
	void *data = NULL;
	STACK_NODE *top_node = s->top;
	if(top_node)
	{
		data = top_node->data;
		s->top = top_node->next;
		free(top_node);
	}
	return data;
}


void * Peep(STACK *s)
{
	void *data = NULL;
	STACK_NODE *top_node = s->top;
	if(top_node)
	{
		data = top_node->data;

	}
	return data;
}


void  PrintStack(STACK *s)
{
	void *data = NULL;
	STACK_NODE *temp = s->top;
	while(temp)
	{
		data = temp->data;
		printf("%d ", *(int *)data);
		temp = temp->next;
	}

}


//
//
//main()
//{
//	printf("Hello world \n");
//}

