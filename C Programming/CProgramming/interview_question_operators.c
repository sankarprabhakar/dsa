/*
 * interview_question_operators.c
 *
 *  Created on: Dec 14, 2016
 *      Author: sankarsa
 */
static int fun1();
static int fun2();

void main_operators()
{
	//comma_operator();
//	chaining_of_rel_op();
	//size_of_struct_without_sizeof();
   size_of_operator();
result_of_comparison();
	//precedence_of_operators();


}

int comma_operator()
{
	//int a=1,2,3;// -- This gives compilation error as "," is used as operator.
	int a;
	int x = 10;
//	int y = (x++, x++);// value of y  will be 11 and x  will be 12. why?. Last x++ is just evaluated not updated to y.
	// The following is equavalent to y = x++
   int  y = (x++, printf("x = %d\n", x), ++x, printf("x = %d\n", x), x++);

	    // Note that last expression is evaluated
	    // but side effect is not updated to y
	    printf("y = %d\n", y);
	    printf("x = %d\n", x);


	a = 1,2,3; // evaluated as (a=1),2,3;
	printf("Value of a = %d \n",a);//prints 1
	a = (1,2,3); // evaluate to 3
	printf("Value of a = %d \n",a);//prints 3


	a = (fun1(), fun2());//fun1() will be called and value is ignored..
	printf("Value of a = %d \n",a);//prints 15
	printf("Value of y = %d \n",y);
	int b;
//	(a,b) = 56; // error in c but valid in cpp

}
static int fun1()
{
	return 5;
}
static int fun2()
{
	return 15;
}
/*
 * postfix > prefix
 *
 * Ass(postfix) -- Left to right
 * Ass(prefix) -- Right to left ( * , &, (typecast),sizeof)..
 *
 * Right to left:
 * 1. prefix, *, &, (typecast), sizeof,
 * 2. Assignment
 * 3. Ternary
 *
 * */
int precedence_of_operators()
{
	int arr[] = {10,20};
	int *p = arr;
	*++p; //right to left ,.. ++p --> p points to 20; and value of 20.
	printf("%d %d %d\n",arr[0],arr[1], *p);// 10,20,20

	p= arr;

	++*p; //value of p--10 incremented by 1
	printf("%d %d %d\n",arr[0],arr[1], *p);// 11,20,11

	arr[0] = 10;
	p= arr;
	printf("p = %lu\n",p);
	printf("*p++ = %d \n", *p++);  // print value of *p and p is incremented
	printf("p = %lu\n",p);
	printf("%d %d %d\n",arr[0],arr[1], *p);// 11,20,20
}




int chaining_of_rel_op()
{
	int a =3,b=2,c=1;

	int f = a>b;
	printf("F = %d \b", f);
	if(a>b>c)
	{
		printf("A>B>C\n");
	}
	else
	{
		printf("!!A>B>C\n");
	}
}

struct mys
{
	int a;
int b;
};


#define MYSIZEOF(x) ((int)(&x+1) - (int)&x)
int size_of_struct_without_sizeof()
{

	struct mys *s = 0;
	s++;
	int a[] = {5,6};

	void *a1 = &a[0];
	void *b1 = &a[1];//b1-a1 in void gives total number of bytes between them
	printf("size of struct %u\n",s);
	struct mys s1[2];
	printf("size of struct %d\n",(void*)&s1[1] - (void *)&s1[0]); //type cast to void gives the diff in bytes.

	printf("Size of int = %d void diff = %d \n", MYSIZEOF(a), b1-a1);

	//printf("size of struct %d\n",&s1[0].a);

	//when int addresses are subtracted the return value will be no. of integers between
	//these pointer

	//when address of two elements in array is subtracted, result is difference of indexes..
	//&a[1] - &a[0] will be 1 irrespective of type of a..

	int c;
	float d;
	//printf("size of struct %u %u %d\n",&c,&d, &c-&d);// float pointer cannot be subtracted from
	//int pointer

}

int size_of_operator()
{
	int i = 9;
	int size = sizeof(i++);//expresson inside sizeof is not evalueated....

    printf("i = %d size = %d \n", i, size);
    float f = sizeof(6+8.99); // only size of expression is returned..
    printf("size = %f \n", f);
/*Finding number of elements in array using sizeoff*/
    int array[] = {3,4,6};
    printf("size of array = %d \n", sizeof(array)/sizeof(array[0]));
}


int increment_lval()
{
	int i =99;
//	printf("%d \n", ++(-i));//gives compilation error - operand for ++/-- should be lval
}


int preinc_as_lval()
{
	int a = 9;
	//++a  = 20;// in cpp this is valid
	//a++ = 20; is not valid in c or cpp
	printf("a = %d \n",a);
}


int ternery_operator()
{
	int test = 1;
	printf("%d\n", test?"Hi":89);//It is good idea to have same return type for both
	//the expressions of ternary operator
}
int result_of_comparison()
{
	int x = 9;
	int y =10;
	printf("size of result =  %d\n",sizeof(x==y));// 4 bytes in c
	//1 bool in cpp
	//int d = 0b11;
	//printf("Binary rep d = %d \n",d);
}

int add_using_printf(int x, int y)
{
	return printf("%*c%*c",x,'\r',y,'\r');


}


