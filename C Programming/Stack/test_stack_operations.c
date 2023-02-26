#include<stdio.h>
#include "stack.h"
int test_count = 1;
void test_separator();
void test_separator()
{
    printf("\n------------------------ %d -------------------\n", test_count++);
}
void main (void)
{
    STACK *s = CreateStack();
    /*Try to print a empty stack*/
    PrintStack(s);

    test_separator();
    
    //Peep the empty stack
    Peep(s);
    
    test_separator();
    // Push 5 4 3 2 1 to stack.
    int var[] = {5,4,3,2,1 };
    for (int i = 0 ; i < sizeof(var)/sizeof(int); i++)
    { 
           Push(s,&var[i]); 
    }
    printf("Print the stack:\n");
    //output expected is 1 ,2,3,4,5
    PrintStack(s);

    test_separator();
    // Peep the stack
    
    printf("Peep data = %d\n", *((int *)Peep(s)));
    test_separator();
    int value = *((int *)Pop(s));
    printf("Popped value from stack = %d \n", value);
    test_separator();
    printf("Print stack \n");
    PrintStack(s);
    test_separator();
    printf("push 27 and print the stack\n");
    int data = 27;
    Push(s,&data);
    PrintStack(s);


}