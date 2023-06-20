/*
 * macro.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */


#include <stdio.h>





#if 1
int main_macro()
{
//	test_question_no1();
	//test_question_no2();
//	test_question_no3();
//	test_question_no4();
	//test_question_no5();
//	test_question_no6();
//	test_question_no7();
//	test_question_no8();
//	test_question_no9();
	//test_question_no10();
//	test_qeustion_no11();

	//test_question_no12();
	//test_question_no13();
	//test_question_no14();
//	test_question_no15();
	//test_question_no16();
}
#endif


/*******************************************************************************/
#define CUBE(x) (x)*(x)*(x)

#define PRINT(i, limit) do \
                        { \
                            if (i++ < limit) \
                            { \
                                printf("GeeksQuiz %d\n",j); \
                            } \
                        }while(1)

/*numbers cannot be incremented in a macro*/
/*in a statement a variable cannot be changed more than once*/
test_question_no1()
{
	// PRINT(0, 3);
	 int i = 6;
int j = 6;
	 int y = (++i) * (++i) ;//* (++i);
	 int z = (j++) * (j++);// * (j++);

	 printf("Cube of i=%d cube = %d square = %d\n", i, CUBE(++i),y); //i = 8 and y is 64.
	    return 0;
}
/*********************************************************************************/

#if X == 5
#define A 5
#else
#define A 10
#endif
test_question_no2()
{
	printf("Value of A = %d \n", A);
}

/***********************************************************************************/
#if 0
#define macro(i,a,n,m) m##a##i##n
#define MAIN macro(i,a,n,m)
#define MAKETOKEN(A,B) A##B

#define STRING(A) #A


void MAIN()
{
 int main = 6;
 int val12 = 67;


	printf("Hello  %d  val12 = %d String = %s\n",macro(0,2,3,4), MAKETOKEN(val,12), STRING(1234));

	macro(i,a,n,m) = 7;
	printf("Main = %d \n", main);


	 char array[] = STRING(1234567);
	printf("%s", array);
}
#endif

/*************************************************************************************/

#define ISEQUAL(X,Y) X==Y

test_question_no3()
{
#if ISEQUAL(X,0)
	{
		printf("X is equal to 0");
	}
#else
	printf("X is not equal to 0");
#endif
}

/**************************************************************************************/

#define square(x) x*x
#define square_c(x) ((x) * (x))

test_question_no4()
{
	int y = 36/square(6);

	printf("y = %d\n",y);
	y = 36/square_c(6);
	printf("y corrected = %d\n",y);

	printf("Square of 6-4 = %d\n",square(6-4));
	printf("correct Square of 6-4 = %d\n",square_c(6-4));
}


/************************************************************************************/

#define scanf "%s Geek"

test_question_no5()
{
	printf(scanf,scanf);
}

/***********************************************************************************/

#define a 10

test_question_no6()
{
	printf("A = %d \n",a);
#define a 20
	printf("A = %d \n",a);
}

/**********************************************************************************/

#define f(g1,g2) g1##g2

test_question_no7()
{
	int val12 = 100;
	printf("Value of val12 = %d", f(val,12));
}
/*******************************************************************************/


#define abc 45
// #define abc max //this results in a error
#define max abc
test_question_no8()
{
	printf("Value of max is = %d\n", max);
}
/********************************************************************************/
#define gets(s) #s

#define PRINT(s) ("s")
test_question_no9()
{
	int x=99;
	printf("Value of gets is %s \n",gets(sankar));
	//printf("Value of gets is %s \n",PRINT(sankar));
}
/*******************************************************************************/

//#define MYNC (a) (a+1)
test_question_no10()
{
	int b;
	//MYNC;
	printf("heyy \n");
}
/******************************************************************************/

#define A -B
#define B -C
#define C 5

#define X +Y
#define Y +Z
#define Z 5



test_qeustion_no11()
{
	printf("value of A --> %d \n", A);
	int x = A;
	int y = X;
	printf("Value of x is %d  %d\n", x,y);
}



#define VAR_ARG(...) printf(\
		"Hello %s\n"\
		,##__VA_ARGS__);
test_question_no12()
{
	VAR_ARG();
	VAR_ARG("h");

}

#define CRASH() do{((void (*)())0)();}while(0);
test_question_no13()
{
//CRASH(); invoking a function at 0-virtual address location... this will lead to a crash
}
#undef a
typedef struct test_struct
{
	int a;
char b;
int c;
}test_struct;

#define OFFSET(ELEMENT, TYPE) ((size_t)&(((TYPE *)0)->ELEMENT))

test_question_no14()
{
	int x = OFFSET(c, test_struct);
	printf("offset = %d \n", x);
}

test_question_no15()
{
	test_struct *p = 0;
	p++;
	printf("size of struct is %d\n", p);
}

/*defining brach prediction macro's*/
#define likely(x) __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)

test_question_no16()
{
	int x = 5;
	x++;
	if(likely(x == 6))
	{
		printf("likely is printed\n");
	}else
	{
		printf("unlikely is printed");
	}
}
