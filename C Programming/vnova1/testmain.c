/*
 * testmain.c
 *
 *  Created on: Nov 15, 2016
 *      Author: sankarsa
 */


#include<stdio.h>


#if 0
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


main()
{
	printf("Hello world");
	solution("13+62*7+*");
	//solution("13+");
}
int solution(char *str)
{
	int len = strlen(str);
	int i = 0;
	int *data = NULL;
	int *op1 = NULL, *op2 = NULL;
	char conv[2] = "";
	printf("len = %d", len);

	STACK *s = CreateStack();


    for(i = 0 ; i < len ; i++)
    {
    	if(!( str[i] == '*' || str[i] == '+' ||  (str[i] >= '0' && str[i] <= '9' )))
    	{
    		printf("Contains illegal items\n");
    		return -1;

    	}

    	if((str[i] >='0' && str[i] <= '9' ))
    	{
    		data = (int *)malloc(sizeof(int));
    		conv[0] = str[i];
    		conv[1] = '\0';

    		*data = atoi(conv);
    		Push(s, (void *)data);
    	}
    	if(str[i] == '+')
    	{
    		 op1 = (int *)Pop(s);
    		 op2 = (int *)Pop(s);

    		 if(op1 == NULL || op2 == NULL)
    		 {
    			 printf("Operator 1 or operator 2 is null");
    			 return -1;
    		 }

    		 data = (int *)malloc(sizeof(int));
    		 *data = (*op1) + (*op2);
    		 Push(s, (void *)data);
    		 free(op1);
    		 free(op2);
    	}
    	if(str[i] == '*')
    	{
    	    		 op1 = (int *)Pop(s);
    	    		 op2 = (int *)Pop(s);

    	    		 if(op1 == NULL || op2 == NULL)
    	    		 {
    	    			 printf("Operator 1 or operator 2 is null");
    	    			 return -1;
    	    		 }

    	    		 data = (int *)malloc(sizeof(int));
    	    		 *data = (*op1) * (*op2);
    	    		 Push(s, (void *)data);
    	    		 free(op1);
    	    		 free(op2);
    	}
    }/*End of for*/

    op1 = (int *)Pop(s);
    printf("op1  = %d \n", *op1);

}
#endif

void main()
{
	int A[] = {1,1,3,3,3,4,5,5,5,5};
	int sol = solution(A,10,2);
	printf("sol = %d \n", sol);
}

int solution(int *A, int A_length, int K) {
    int n = A_length;
    int best = 0;
    int lastbest = 0;
    int count = 1;
    int i;
    for (i = 0; i < n - 2; i++) {
        if (A[i] == A[i + 1] && A[i] > K)
        {
        	count = count + 1;
        }

        else
        {
            count = 1;
        }
        if ((best - lastbest + count) > best)
        {
        	lastbest = best - lastbest;
            best = lastbest + count;
        }
        if(lastbest + count > best)
        {
        	//lastbest = ;
        	best +=count;
        }

    }
    int result = best;

    return result;
}
