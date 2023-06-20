/*
 * stack_parathesis.c
 *
 *  Created on: Jan 9, 2017
 *      Author: sankarsa
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 *
 * A bracket is considered to be any one of the following characters:
(,),{,},[, or].Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {)
occurs to theleft of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of
matched pairsof brackets: [], {}d ().A matching pair of brackets is not balanced if the set of brackets it
encloses are not matched. Forexample, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of
square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single,
 unbalanced closing square bracket, ].By this logic, we say a sequence of brackets is considered to be balanced
 if the following conditions are met:
1It contains no unmatched brackets.
2The subset of brackets enclosed within the confines of a matched pair of brackets
is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is
balanced, print
YES
 on a new line; otherwise, print
NO
 on a new line

 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack_node
{
    char character;
    struct struct_node *link;

}STACK_NODE;

typedef struct stack
{
     STACK_NODE *top;
}STACK;


STACK_NODE  * createStackNode(char character)
{

        STACK_NODE *s = malloc(sizeof(STACK_NODE));
        s->character = character ;
        s->link = NULL;
        return s;

}

char push(STACK *s, char c)
{
    if(s!= NULL)
    {
         STACK_NODE *t = createStackNode(c);
         if(t)
         {
            t->link = s->top;
             s->top = t;
         }
    }
    return 0;
}

char pop(STACK *s)
{
    if(s!= NULL)
    {
         STACK_NODE *t = s->top;
         char c = t->character;
         s->top = t->link;
         free(t);
         return c;
    }
    return 0;
}

void emptyStack(STACK *s)
{
	if(s)
	{
		while(s->top)
		{
			STACK_NODE *t = s->top;
			s->top = t->link;
			free(t);
		}
	}

}


bool is_balanced(char expression[]) {

    STACK s;
    s.top = NULL;
    char c = '\0';
    int i = 0;
    while((c = expression[i]) != '\0')
    {
        i++;
        if(c == '{' || c == '[' || c == '(')
        {
        	printf("pushing = %c \n", c);
            push(&s, c);
        }
        else if(c == '}' || c == ']' || c == ')')
        {
            char poped = pop(&s);
            printf("poping = %c \n", poped);
            printf("input = %c \n", c);
            if(!((poped == '(' && c == ')') || (poped == '[' && c == ']')  || (poped == '{' && c == '}') ))
            {
            	emptyStack(&s);
                return false;

            }
        }

    }
    return true;
}

int main_brackets(){
    int t;
    int a0 = 0;
    scanf("%d",&t);
    for( a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
         bool answer = is_balanced(expression);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
        free(expression);
    }
    return 0;
}
