/*
 * Stack.h
 *
 *  Created on: Feb 26, 2023
 *      Author: sankar 
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct stack_node{
	void *data;
	struct stack_node *next;
	struct stack_node *prev;
}STACK_NODE;

typedef struct stack
{
	STACK_NODE *top;
	//int stack_len; // stack length

}STACK;

STACK_NODE *CreateStackNode(void *data);
STACK *CreateStack();
STACK * Push(STACK *s, void *data);
void * Pop(STACK *s);
void * Peep(STACK *s);
void  PrintStack(STACK *s);


#endif /* STACK_H_ */
