/*
 * interview_question_switch.c
 *
 *  Created on: Jan 5, 2017
 *      Author: sankarsa
 */
main_switch()
{
//test_switch_q1();
//test_switch_q2();
	test_switch_q3();
//test_while_q3();
}
test_switch_q1()
{
	const int i = 99; //normal integer will give compilation error.. const works
	int s = 4;
	int y = 4;
	switch(s + y)
	{
//	case i: //Error
	//	printf("Value of i is asked\n");
		//break;

//	case "hello": //Error only intergers or chars which reduce to integer can be used here
//		break;

//	case s+y:
	//	break;
	case 8:
		printf("Value is 8\n");
		break;
	}
}


test_switch_q2()
{
	const int i = 99; //normal integer will give compilation error.. const works
	float s = 4.06;
	int y = 4;
	switch((int)s) /*1. we cannot use float here in switch statement
	2. we can use expression which reduce to integers*/
	{
	//case i:
		//printf("Value of i is asked\n");
		//break;

	case (int)4.06: //only integer is permitted here
		printf("Value is4.068");
		break;
	//case 4:
		//printf("Valueis 4");
	}
}



test_switch_q3()
{
	int x = 1;
	const int y = 99;
	switch(x)
	{
	x = x+1;//This line is not evaluated. X will remail 1 only
	default: printf("default\n");
	case 1: printf("one \n");
	case 2: printf("two \n");
	case 3: printf("three\n");
	//case y: printf("Y\n");
	//x=x+1; //this lise will be evaluated
	}
	printf("Value of x = %d \n", x);
}

/*effect of continue on while statement
 * below program run to infinity -  should be taken care
 * */

test_while_q3()
{
	int i = 0;
	while(i < 3)
	{
		printf("value of = %d \n",i);
		continue;
		i++;//this will never executed
	}
}
