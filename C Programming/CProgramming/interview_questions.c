/*
 * interview_questions.c
 *
 *  Created on: Dec 8, 2016
 *      Author: sankarsa
 */

/*scope of static variable...
 *
 * output  - 0 0 0 0
 * */



main_intv_q()
{
//printf("Value returned = %d \n",	fun_intv());
//printf("Value returned = %d \n",	fun_intv());
//printf("Value returned = %d \n",	fun_intv());
//	temp_test1();
	temp_test2();
	temp_test11();
}
void temp_test1()
{
	int static a = 5;
	if(--a)
	{
		temp_test1();
		printf("%d ", a);
	}
}
/*output - 4,3,2,1*/
void temp_test2()
{
	int static a = 5;
	if(--a)
	{

		printf("%d ", a);
		temp_test2();
	}
//printf("%d ",5++);
}


/*output of below program*/

temp_test3()
{
//	typedef static int *i; -- compilation error, typedef is also a storage class. multiple
	//storage class in a statement gives error
	int j = 90;
//	i a = &j;

}

temp_test4()
{
	typedef int *i;
	i *a;
	int j =10;
	a = &j; //some compilers failes here..
	printf("%d ", **a);//Crash is expected

}

/*output of below program*/
int fun_intv()
{
	static int num = 16;
	return num--;/*return 16 and then reduces the number.. on next call static value will be 15*/
	//return num=num-1;
}

//int fun()
//{
//	static int num = 16;
//	return num--;/*return 16 and then reduces the number.. on next call static value will be 15*/
//	//return num=num-1;
//}

temp_test5()
{
	for(fun();fun();fun())
	{
		printf("%d ",fun());
	}
}
/*can i declare function parameter as static*/
#if 0
temp_test6(static int x)
{

}
/*static cannot be applied to function parameter*/
#endif


temp_test6()
{
	typedef int INT, *INTPTR; //this mean typedef int INT; typedef int * INTPRT..so on..
	//common typedef is shared by all variable definitions
	INTPTR y;
}

/*wil below functions give compilation error*/
//No - register is the only storage specifier allowed for function parameter
temp_test7(register int a)
{
}

/*wil below functions give compilation error*/
//No - we can call functions with comma separed way as below
int foo()
{
}
int baa()
{
}
int temp_test8()
{
	foo(),baa();
}


/*can we use volatile and const together*/
//Yes - see below, it wont give compilation error
temp_test9()
{
	const volatile int a = 8;
}


/*test 10*/

temp_test10()
{
	printf("%d \n", printf("Hello\n"));
	int a;
	printf("Scanned = %d \n",scanf("%d %d",&a, &a));//2 items scanf is reading. so output wil be two
}
/*what is the output of below program
 *
 * -1 will be promoted to unsigned it; which is much larger number than 4,and NO will be printed
 * */
temp_test11()
{
	if(5U > -1) //5U is unsigned, so -1 will convert to unsigned before comparison
	{
		printf("5>-1");
	}
	else
	{
		printf("Crazy 5<-1");
	}
	if(sizeof(int) > -1) // sizeof(int) gives unsigned int
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	}


/*scansets*/

temp_test12()
{

	char str[128];
	scanf("%[A-Z]",str); //it stops reading if it encounter other than A to Z
	printf("%s",str);

	scanf("%[^A-Z]",str); //it takes all other than A-Z; i.e it Hellstops reaading if it encouters a captial leeter
	printf("%s",str);
	/*how to read a complete line using scanf*/

	scanf("%[^\n]",str);
		printf("%s",str);
}


/*puts vs printf*/

temp_test13()
{
//   puts("Hello"); prints "Hello" +  "\n"
  // puts("world");
   //printf("Hello %s world");  //possible prints junk or  crashes..
	puts("Hello %s world");  //puts prints what ever strings
	//getchar();
}


/*number of characters printed by printf*/

temp_test14()
{
	int n1= 0,n2=0;
	printf("Hel %n lo\n",&n1);
	printf("%d -- %d \n", n1,n2);
}

/*printing percentage*/

temp_test15()
{
	int n1= 0,n2=0;
	printf("%% print percentage symbol\n");
	printf(5 +"hello world"); // print from 5th caracter of string

}
/*test with modulo*/
temp_test16()
{
	//printf("5%0 = %d\n", 5%0); This crashes
	printf("0/5 is %d \n",0%5);
	printf("1/5 is %d \n",1%5);
	printf("-7/5 is %d \n",-7%5); //-2 is answer
	printf("7/-5 is %d \n",7%-5);//only numerator's sign is consider for answer... this give 2
	//printf("7/5.0 is %d \n",7%5.0); Double gives compilation error
	//printf("7/5.0 is %d \n",7.0%5); float operator gives compilation error

}

temp_test17()
{
	printf("4<<-1 = %d\n",4<<-1);//Undefined behavior- but here it is right shifting
	printf("-2<<1 = %d\n",-2<<1); // left shifting with retaining the sign bit..
	printf("-4<<-1 = %d\n",-4<<-1);
}

