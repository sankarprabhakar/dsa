

#include<stdio.h>

typedef struct snode
{
	int d;
	struct snode *l;
}SNODE;

SNODE *top = NULL;
int min = 0x7FFFFFFF;

/*Void */
void test_stack()
{
	push(&top, 5);
	push(&top, 4);
	push(&top, 3);
	push(&top, 2);
	push(&top, 1);




	printStack(top);
	printf("Min = %d \n", getMin());
	//printf("peeped = %d\n",peep(&top));
	pop(&top);
	printf("Min = %d \n", getMin());
	pop(&top);
	printf("Min = %d \n", getMin());
	pop(&top);
	printf("Min = %d \n", getMin());
	pop(&top);
	printf("Min = %d \n", getMin());
	pop(&top);
	printf("Min = %d \n", getMin());
	printStack(top);

}

int getMin()
{
	return min;
}



SNODE *createSnode(int data)
{
	SNODE *s = malloc(sizeof(SNODE));
	if(s!=NULL)
	{
		s->d = data;
		s->l = NULL;
	}
	return s;
}

int pop(SNODE **top)
{
	int poped = -1;
	if(top && *top)
	{
		poped = (*top)->d;
		SNODE *t = *top;
		*top = (*top)->l;
		free(t);
	}
	if(poped < min)
	{
    /*
     *  min , num , num < min;
     *
     *  insNum = 2 * <<num>> - min;
     *  min = num;
     *
     *  poped < min
     *  min = 2 *<<min - will hold actual no>> - insNum<<from stack>>;
     *
     *
     *
     * */


		int ActualNum  = min;
		min = 2 * min - poped;
		poped = ActualNum;
	}


	return poped;
}

void push(SNODE **top, int d)
{
	if(isEmpty(*top))
	{
		min = d;
	}
	else
	{
		if(min > d)
		{
			int newElement = 2 * d - min;
			min = d;
			d = newElement;
		}
	}


	SNODE *snew = createSnode(d);
	snew->l = *top;
	*top = snew;
}

int peep(SNODE **top)
{
	return (top && *top)?(*top)->d:-1;
}

int isEmpty(SNODE *top)
{
	return !(top);
}

void printStack(SNODE *top)
{
	while(top != NULL)
	{
		printf("%d - ", top->d);
		top = top->l;
	}
}
