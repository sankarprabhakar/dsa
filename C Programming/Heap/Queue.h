/*
 * Queue.h
 *
 *  Created on: Jun 8, 2016
 *      Author: sankarsa
 */

#ifndef QUEUE_H_
#define QUEUE_H_


typedef struct Qnode
{
	void *data;
	struct Qnode *next;
	struct Qnode *pre;
}QNODE;


typedef struct Queue
{
struct Qnode *front;
struct Qnode *rear;
int size;
}QUEUE;


QUEUE* CreateNewQueue(void);
QNODE * CreateQNode(void *data);
QUEUE * Enqueue(QUEUE *q, void *data);
void * Dequeue(QUEUE *q);
void printQ(QUEUE *q);

#endif /* QUEUE_H_ */
