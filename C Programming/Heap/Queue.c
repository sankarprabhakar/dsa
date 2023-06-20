/*
 * Queue
 *
 *  Created on: Jun 8, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"



QUEUE* CreateNewQueue()
{
	QUEUE *q = malloc(sizeof(QUEUE));
	q->front = NULL;
	q->rear = NULL;
	q->size =0;
	return q;
}

QNODE * CreateQNode(void *data)
{
	QNODE *tmp_node = malloc(sizeof(QNODE));
	tmp_node->data = data;
	tmp_node->next = NULL;
	tmp_node->pre = NULL;
	return tmp_node;
}

QUEUE * Enqueue(QUEUE *q, void *data)
{
	 QNODE * temp = CreateQNode(data);
	 if(q->rear == NULL && q->front == NULL)
	 {
		 //first element
		 q->rear = q->front = temp;
	 }
	 else
	 {
		 QNODE *rear_node = q->rear;
		 rear_node->next = temp;
		 temp->pre = rear_node;
		 q->rear = temp;

	 }
	 q->size++;
	 return q;
}
//check if front and rear are same if yes, set both to null
//return the data pointer from the front
// adjust the front..
// remove the node from freeing it
void * Dequeue(QUEUE *q)
{
	void * data = NULL;
	 //QNODE * temp = GetQNode(data);
	 if(q->rear ==  q->front)
	 {
		 //only element...
		 QNODE *front_node = q->front;
		 data = front_node->data;
		 free(front_node);
		 q->rear = q->front = NULL;
	 }
	 else
	 {
		 QNODE *front_node = q->front;
		 data = front_node->data;
		 q->front = front_node->next;
		 free(front_node);
		 q->front->pre = NULL;

	 }
	 q->size--;
	 return data;
}


void printQ(QUEUE *q)
{
	QNODE *front_node;
	if(q->front)
	{
		front_node = q->front;
	}
	while(front_node)
	{
		printf("%d->",*(int *)(front_node->data));
		front_node = front_node->next;
	}

}
