#include <stdio.h>
#include "queue_adt.h"
int myQ[5] = {0};
int front = -1, rear=-1;
int size =5;
void main(void)
{
//printf("Hello world\n");
   enqueue(1);
   enqueue(2);
   enqueue(3);
   printQ();
   printf("DeQueue element = %d \n" ,dequeue());
   printf("DeQueue element = %d \n" ,dequeue());
   printQ();
}

int enqueue(int data)
{
    //check if q is full
    if ((rear+1) % size == front)
    {
        printf("Q is full\n");
        return -1;
    }
    // Check if empty
    if (front ==-1 && rear == -1)
    {
        front = 0; 
        rear = 0;
        myQ[rear] = data;
        return 1;
    }
    else{
        rear = (rear+1) % size;
        myQ[rear] = data;

    }
}
int dequeue()
{
    //check if emptry
    if (front == -1 && rear == -1)
    {
        printf("Q is empty \n");
        return -1;
    }
    else if (front == rear) // only element
    {
        int data = myQ[front];
        front = rear = -1;
        return data;
    
    }
    else
    {
        int data = myQ[front];
        front = (front + 1) % size;
        return data;
    }
}

void printQ(void)
{
    if (front == -1 && rear == -1)
    {
        printf("Q is empty");
    }
    else if (front <= rear) {
        for (size_t i = front; i <= rear; i++)
        {
            printf("%d - ", myQ[i]);
        }
    }
    else if (front > rear)
    {
        for (size_t i = front; i < size; i++)
        {
            printf("%d - ", myQ[i]);
        }
        for (size_t i = 0; i <= rear; i++)
        {
            printf("%d - ", myQ[i]);
        }
    }
        
}