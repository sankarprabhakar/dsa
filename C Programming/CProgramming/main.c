/*
 * main.c
 *
 *  Created on: Jun 22, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
extern  long int *end, *edata, *etext;

#if 1
void main(int argc, char *argv[])
{
	int i = 0;
	//test_cheg1();
	int array[] = {0,1};

	/*difference between two pointers --> number of elements that can be stored between these values*/
    int *val = (&i) + 1;
    printf("Hello world\n");

	//printf("array diff  = %p   %p\n",&array[1] - &array[0], val - &i); //Value will be one.
	//print_string();
	//printf("Text = %lu\n", *etext);
//	printf("Text = %lu\n", *edata);
//	printf("Text = %lu\n", *end);
	if(argc ==  1)
	{
		//printf("We just have the name of the program :: %s",argv[0]);
	}
	else
	{
		for(i = 0; i < argc; i++)
		{
		//	printf("Parameters i[%d] = %s",i,argv[i]);
		}

	}



	//main_macro();
   // main_array();
	//p_to_arr_main();
	//print_sizeof();
//	main_test_bool();
    //	endian_main();

	//enum_main();
	//funarg_main();
	//fp_main();
	//precedence_of_operators();
//	main_operators();
	//main_switch();
	//main_intv_q();
//	main_vararg();
	//main_gcd();
	main_struct();
	//inputoutput();
	//test_pass_return__assign_structure();
//	main_scope();
	//union_main();
	//string_main();
//	int test[10];
//	int *t = &test;
//	int *p = malloc(sizeof(int)*10);
//	for(int i = 0; i< 10; i++)
//	{
//		printf("Test = %lu p = %lu \n",t++,p++);
//	}

//	pointer_main();


// static int *ptr;
 // int j = 99;
  //ptr = &j;
 // printf("v = %d", *ptr);



}
#endif
