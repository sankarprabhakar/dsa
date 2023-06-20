/*
 * Stack.h
 *
 *  Created on: Jun 8, 2016
 *      Author: sankarsa
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct stack_node{
	void *data;
	struct node *next;
	struct node *prev;
}STACK_NODE;

typedef struct stack
{
	STACK_NODE *top;

}STACK;

STACK_NODE *CreateStackNode(void *data);
STACK *CreateStack();
STACK * Push(STACK *s, void *data);
void * Pop(STACK *s);
void * Peep(STACK *s);
void  PrintStack(STACK *s);


#endif /* STACK_H_ */
