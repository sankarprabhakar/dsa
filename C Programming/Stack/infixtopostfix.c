/*
 * infixtopostfix.c
 *
 *  Created on: Feb 4, 2017
 *      Author: sankarsa
 */

#include<stdio.h>
#include "Stack.h"
#include "Queue.h"

int getoppriority(char op);
int isOperator(char op);
int evaluate_postfix(char *inp, int n);
/*
 * store the operator till a lower priority is found...
 * when lower priority is found pop and print till next priority is found
 *
 * */
void test_infix()
{
//	char input[] = "a*b+(c-d*(e+f*g))";
//	infixtopostfix(input, 10);
//	printf("Post fix = %s \n", input);
	char input[] = "5*6";
	infixtopostfix(input, 4);
	printf("Value of sum = %d \n",evaluate_postfix(input,4));
}

int infixtopostfix(char *inp ,int n)
{
	STACK *s = CreateStack();
	char operator[n];
	int i = 0, j = 0;
	while(inp[i] != '\0')
	{
		if(!isOperator(inp[i]))
		{
			inp[j] = inp[i];
			j++;
		}else
		{

			if(inp[i] == '(')
			{
				operator[i] = inp[i] ;
				Push(s, &operator[i]);
				i++;
				continue;
			}
			if(inp[i] == ')')
			{
				char *data = NULL;
				while((*(data = Pop(s)) != '('))
				{
					inp[j] = *data;
					j++;
				}
				i++;
				continue;
			}

			char *pOp = Peep(s); operator[i] = inp[i];
			char peepprio = pOp?getoppriority(*pOp):-1;
			char currprio = getoppriority(operator[i]);
			while(peepprio != -1 && currprio <  peepprio)
			{
				char *poped = Pop(s);
				inp[j] = *poped;
				j++;
				pOp = Peep(s);
				peepprio = pOp?getoppriority(*pOp):-1;
			}
			Push(s, &operator[i]);
		}
		i++;
	}

	char *data = NULL;
	while((data = Pop(s)) != NULL)
	{
		inp[j] = *data;
		j++;
	}

	inp[j] = '\0';/*if "()" is included in input, it wont be included in the output, so terminate only all elements of input is processed*/
}

int getoppriority(char op)
{
	switch(op)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '(':
				return -1;
//		case '{':
//		case '}':
//		case '(':
//		case ')':
		default:
			return 0;
		}
}

int isOperator(char op)
{
	switch(op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '{':
	case '}':
	case '(':
	case ')':
	case '%':
		return 1;
		break;
	default:
		return 0;
	}
}


int evaluate_postfix(char *inp, int n)
{
	int i = 0;
	STACK *s = CreateStack();
	while(inp[i] != '\0')
	{

		if(!isOperator(inp[i]))
		{
			Push(s, &inp[i]);

		}else
		{
			char *op1 = Pop(s);
			char *op2 = Pop(s);

			doOperation(op1, op2, &inp[i]);
			Push(s, op2);
		}
		i++;
	}
	return (*(char *)(Pop(s)));
}


int doOperation(char *op1, char *op2, char *op)
{
	switch(*op)
	{
	case '+':
		*op2 = (*op1 - '0') + (*op2 - '0');
	break;
	case '-':
		*op2 = (*op1 - '0') - (*op2 - '0');
		break;
	case '*':
		*op2 = (*op1 - '0') * (*op2 - '0');
		break;
	case '/':
		*op2 = (*op1 - '0') / (*op2 - '0');
		break;
	}
}
