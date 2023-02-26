/*
 * Stack.c
 *
 *  Created on: Feb 26, 2023
 *      Author: sankar 
 */
#include <stdio.h>
#include "stack.h"


/*
 * Stack.c
 *
 *  Created on: Jun 8, 2016
 *      Author: sankarsa
 */
#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

/*
* Function name : CreateStackNode
* Parameter     : void pointer to data
*/
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
	if(NULL != s && NULL != s->top)
    {
        new_node->next = s->top;
		s->top->prev   = new_node; 
    }
	s->top = new_node;
	return s;
}
/*Pop out the top of the stack and set the top as the next node*/
void * Pop(STACK *s)
{
    void *data = NULL;
    if(NULL != s)
    {
	    STACK_NODE *top_node = s->top;
        if(top_node)
        {
            data = top_node->data;
            s->top = top_node->next;
            if (NULL != top_node->next)
            {
                /*set the previous node top to NULL*/
                ((STACK_NODE *)top_node->next)->prev = NULL;
            }
            free(top_node);
        }
        else
        {
             printf("Stack is empty\n");
        }
	}
	return data;
}

/*Peep function returns pointer to the data at top of the stack*/
void * Peep(STACK *s)
{
	void *data = NULL;
	STACK_NODE *top_node = s->top;
	if(top_node)
	{
		data = top_node->data;
	}
    else
    {
           printf("Stack is empty\n");
    }
	return data;
}

/*print the stack*/
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



