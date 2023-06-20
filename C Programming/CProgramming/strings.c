/*
 * strings.c
 *
 *  Created on: Dec 5, 2016
 *      Author: sankarsa
 */

#include<stdio.h>

char * reverse(char *input);
void printbinary(unsigned long  num);
char * reverse_vowel(char *input);
int mystrcmp(char *src1 , char *src2 );
//void main(){}
#if 1
void string_main()
{

	int i = 1;
	printf("%d %d %d\n", i++, i++, i);

	char output[1024];

	reverse_string("Hello world",output);
	printf("Out put = %s \n", output);
	printf("this is my %s \n",reverse(output));
	char asciinum[] = {'1','2','7','\0'};
 	int num = myatoi(asciinum);
 	printf("numbr = %d \n",num);

 	myitoa(1512344,output,2);
 	printf("Out put 45 = %s \n", output);

 	printbinary(15LL);
 	//test_enum_qno2_1();
 	//print_string();
 	//scope_test();
 	//scope_test_2();

 	output[0] = 'a';
 	output[1] = 'e';output[2] = 'i';output[3] = 'o';output[4] = 'u';output[5] = '\0';
 	strcpy(output,"helaloo worelid");
 	printf("\n%s \n",reverse_vowel(output));
 	//test_bool();
 	//test_char_arithmetic();
 	//compare_two_floats();
 	//print_char_in_string("Hello worldAABBCCDD");
 	//int numop[] =  {2, 5, 3, 5, 4, 4, 2, 3};
 	int numop[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
 	//int dist = get_minimum_dist(numop,8,3,2);
 	//int dist = get_minimum_dist(numop,12,3,6);
 	//int dist = get_minimum_dist1(numop,12,3,6);
 	//printf("min dist = %d \n", dist);
 	//test_main();
 //	temp_test1();
 	//temp_test2();
 	//temp_test4();
 //	temp_test5(),temp_test7();
 //	temp_test10();
 	//temp_test11();
 	//temp_test12();
 	//temp_test13();
 	//temp_test14();
 //	temp_test17();
// 	int xorinput[] = {1,2,3,4,5,5,3,2,1};
// 	int odd = get_odd_occurance(xorinput,9);
// 	printf("Odd occurance = %d \n", odd);


// 	int missing[] = {1,2,3,5,6};
// 	int missed_num = find_missing_number(missing, 6);
// 	printf("Missed num = %d \n", missed_num);


// 	 	int missing[] = {1,2,4,5,6};
// 	 	int missed_num = find_missing_no_xor(missing, 6);
// 	 	printf("Missed num = %d \n", missed_num);

 	//printf("Diff val = %d \n",test_opposite_sign(5,-5));
 	//printf("Diff(same) val = %d \n",test_opposite_sign(5,5));

 //	printf("Bits to be flipped = %d \n" ,test_num_of_bits_tobe_flipped(7,8));

// printf("8 is power of 2 = %d \n",	find_power_of_2(8));
// printf("7 is power of 2 = %d \n",	find_power_of_2(7));

// printf("8 is power of 2 = %d \n",	countbits_logn(8));
// printf("7 is power of 2 = %d \n",	countbits_logn(7));
//
// 	 printf("8 is power of 2 = %d \n",	countbits_builtin(8));
// 	 printf("7 is power of 2 = %d \n",	countbits_builtin(7));
//
// 	int missing[] = {1,1,1,2,2,2,7,5,5,5,6,6,6};
// 	int non_rep = find_non_rep_element_other_element_rep_thrice_xor(missing,13);
// 	printf("Non repeating is - %d \n", non_rep);

 	//int swapped = swaping_n_bits_btw_p1_to_p2(28,0,3,2);
 //	int swapped = swaping_n_bits_btw_p1_to_p2(47,1,5,3);
 	//printf("Value of swapped = %d \n", swapped);

// 	int sum1 = adding_two_number_xor(7,9);
// 	printf("Sum = %d \n", sum1);


 	//printf("5*10 = %d \n",multiplying_without_mul_operator(5));

// 	int two_unique[] = {1,1,2,2,4,5,6,6,7,7};
// 	int x = 0, y = 0;
// 	find_two_non_rep_elements(two_unique,10,&x,&y);
// 	printf("X = %d Y = %d \n",x,y);

 	//comma_operator();
 	//precedence_of_operators();

 	//chaining_of_rel_op();
// 	size_of_struct_without_sizeof();
 //	size_of_operator();
 	//ternery_operator();
 	printf("sume = %d \n",add_using_printf(5,7));

 	printf("Strcmp = %d \n",mystrcmp("A","B"));
 	printf("Strcmp = %d \n",mystrcmp("B","A"));
 	printf("Strcmp = %d \n",mystrcmp("AAAA","AAAAB"));


}
#endif
/*reversing string*/
int reverse_string(char const *input, char *output)
{
	 int len = 0, i = 0, j = 0;
     if(input != NULL && output != NULL)
     {
    	 len = strlen(input);
    	 j = len-1;
    	 while(j >= 0)
    	 {
    		// input[i] = 'c';
    		 output[i] = input[j];
    		 i++;
    		 j--;
    	 }
    	 output[i] = '\0';
     }
}


char * reverse(char *input)
{
	int j = 0, i = 0;
	char temp;
	if(input != NULL)
	{
		j = strlen(input) - 1; // strlen to index conversion; strlen will return length without null character
		while(j > i)
		{
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			j--;i++;
		}
	}
	return input;
}


/*a to i*/

int myatoi(char *ascii)
{
	int num = 0; int i = 0;
	//int len = strlen(ascii) - 1;
	while(ascii[i] != '\0')
	{
		num = num * 10 + (ascii[i] - '0');
	    i = i +1;
	}
	return num;
}

/*i to ascii*/

int myitoa(int num, char *output, int base)
{
	int rem = 0, i = 0;
	switch(base)
	{
	case 10:
	case 8:
	case 2:
	case 16:
		while(num != 0)
		{
			rem = num%base;
//			if(base != 16)
//			{
//				output[i] = rem + '0';
//			}
//			else
//			{
				output[i] = "0123456789ABCDEF"[rem];
//			}

			num /=base;
			i++;
		}
		output[i] = '\0';
		reverse(output);
		break;
	//case 2:



	}
return 1;
}

void printbinary(unsigned long num)
{
int n;
//	printf("size of long = %d \n",sizeof(long));
	//printf("size of long long = %d \n",sizeof(long long));
	printf("BIN VaL :");
	while(num!=0)
	{
		printf("%s", (num & 0x80000000) == 0?"0":"1");
		num = num << 1;
	}

//	float x = 8.9;
//	x++;
//	printf("value of x = %f\n",x);

}

extern int myextern;

void print_string()
{
char const *test = "HelloWorld\n";
const int x; // constant should be initialized..
//x=5; // constant cannot be re-assigned with value
test++;
printf("\nINC = %s",test);
printf("\nINC = %d",myextern);

}

#define CHECK_VOWEL(x) if(!(x == 'a' || x == 'e' || x == 'i' || x == 'o'  || x == 'u' ))



char * reverse_vowel(char *input)
{
	int len = 0, j = 0 ,i = 0;
	if(input != NULL)
	{
		len = strlen(input);
		j = len-1;
		while(j > i)
		{
			CHECK_VOWEL(input[i])
			{
				i++;
				continue;
			}
			CHECK_VOWEL(input[j])
			{
				j--;
				continue;
			}

			char temp =input[i];
			input[i] = input[j];
			input[j] = temp;

			i++;
			j--;

		}
	}
return input;
}
int mystrcmp(char *src1 , char *src2 )
{

	while(*src1 == *src2)
	{
		if(*src1 == '\0')
		{
			return 0;
		}
		src1++;
		src2++;
	}
	return (*src1 - *src2);
}
