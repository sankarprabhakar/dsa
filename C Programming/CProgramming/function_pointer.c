/*
 * function_pointer.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */



int myextern;
//typedef int * (*f)(int *,int *);
/*function takes two int points and return an int pointer*/
int * (*f)(int *,int *);




int * takes_2pointers_returns_1pointer(int *a,int *b);
void test_takes_2pointers_returns_1pointer();
int *take_int_returns_pointer(int);
void test_take_int_returns_pointer();


#if 1
void fp_main()
{
	//test_takes_2pointers_returns_1pointer();
	//test_take_int_returns_pointer();
	test_return_fp();

//	testing_arry_of_function_pointers();
}
#endif
void test_takes_2pointers_returns_1pointer()
{
	f = takes_2pointers_returns_1pointer;
	int a = 5, b = 5;
	int *c = f(&a, &b);
	printf("C = %d \n",*c);

}

int * takes_2pointers_returns_1pointer(int *a,int *b)
{
	static c = 0;
	c = *a+*b;
	return &c;
}


/*making function pointer variables*/
typedef int * (*f1)(int); //Function which takes a int and returns and int pointer.. After
//typedef we can use f as a variable type to define function pointers



void test_take_int_returns_pointer()
{
	f1 myf;
	myf = take_int_returns_pointer;
	int *c = myf(4);
	printf("Value of C = %d \n",*c);
}

int *take_int_returns_pointer(int a)
{
	static d = 0;
	d = a;
	return &d;
}


/*A function returning function pointer*/


int *(*return_fp(void))(int *);

/*
 * return_fp is a function which takes void and returns a function pointer whose return
 * value is interger pointer and argument is another integer pointer
 *
 * */


int *fun_fun_takes_1pointer_return1pointer(int *a);


/*fucntion pointer to a funciton which returns a function pointer*/
int (*fp_holder)(int *a);

//(*(*fp())()

int *(*(*fptr)(void))(int *);

int test_return_fp(void)
{
	int a = 6;
	fptr = return_fp;
	fp_holder = fptr();//return_fp();
	fp_holder(&a);

}


int *(*return_fp(void))(int *)
{

	return fun_fun_takes_1pointer_return1pointer;
}

int *fun_fun_takes_1pointer_return1pointer(int *a)
{
	printf("Print from fun_takes_1pointer_return1pointer\n");
}



/****************fumction pointer array******************************/

int * (*fp[5])(int);

typedef int * (*fp_prototype)(int);

fp_prototype fp_array[5];





int *fa1(int a);
int *fa2(int a);
int *fa3(int a);
int *fa4(int a);
int *fa5(int a);

int *fa1(int a)
{
	static b = 0;
	printf("%s\n",__FUNCTION__);
	return &b;
}
int *fa2(int a)
{
	static b = 0;
	printf("%s\n",__FUNCTION__);
	return &b;
}
int *fa3(int a)
{
	static b = 0;
	printf("%s\n",__FUNCTION__);
	return &b;
}
int *fa4(int a)
{
	static b = 0;
	printf("%s\n",__FUNCTION__);
	return &b;
}
int *fa5(int a)
{
	static b = 0;
	printf("%s\n",__FUNCTION__);
	return &b;
}


testing_arry_of_function_pointers()
{
	fp[0]  = fa1;
	fp[1]  = fa2;
	fp[2]  = fa3;
	fp[3]  = fa4;
	fp[4]  = fa5;

	fp_array[0] = fa1;
	fp_array[1] = fa2;
	fp_array[2] = fa3;
	fp_array[3] = fa4;
	fp_array[4] = fa5;



	fp[0](1);
	fp[1](1);
	fp[2](1);
	fp[3](1);
	fp[4](1);

	fp_array[0](1);
	fp_array[1](1);
	fp_array[2](1);
	fp_array[3](1);
	fp_array[4](1);


}
