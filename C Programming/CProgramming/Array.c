/*
 * Array.c
 *
 *  Created on: Dec 21, 2016
 *      Author: sankarsa
 */
#include<stdio.h>

void main_array()
{
	//array_test_q1();
	//array_test_q2();
	//array_test_q3();
	//array_test_q4();
	//array_test_q5();

//	array_test_q6();
	//array_test_q7();
	//array_test_q8();
	//array_test_q9();
	char src[] ="hello";
	char dest[100] = "hello my dear";
	//array_test_q10_strcat(dest, src);
	//printf("dest = %s \n",dest);
	char src1[] ="hello my dearA";
	char dest1[] ="hello my dear";
	int same =  array_test_q10_strcmp(dest1, src1);
		printf("diff = %d %d\n",same , strcmp(dest1,src1));
//	array_test_q11();
//	array_test_q12();
	arrary_test_q13();
	array_test_q14();
}

int array_test_q1()
{
	 int arr[10] = {5}; //initializing one will result in setting other elements to 0
	 printf("size of arr = %d \n",sizeof(arr)); //will give <length of array> * <size of element> ;
	 print_array(arr, (sizeof(arr)/sizeof(arr[0])));

}

int array_test_q2()
{
	 int arr[10];// = {5}; //junk values will be displayed
	 printf("size of arr = %d \n",sizeof(arr));//40 bytes
	 print_array(arr, (sizeof(arr)/sizeof(arr[0]))); //40/4 = 10
}



int array_test_q3()
{
	 int a = 89;
	 int arr[1] = {5,4,9}; // in c it compiles but in cpp it wont..
	 printf("size of arr = %d \n",sizeof(arr));
	 printf("a = %d \n", a);
	 print_array(arr, (sizeof(arr)/sizeof(arr[0])));
}

int array_test_q4()
{
	/*Data type for which i cannot create an array*/
//	void a[10]; = This is an error

	/*this works*/
	void *a[10]; //array of 10 void pointer.
}

int array_test_q5()
{
	/*how array is passed to function*/
	int arr[] = {1,2,3,4,5};
	int x=7;
	//arr++; this gives a compilation error; array cannot be incremented
    //arr = &x;// this s compilation error; reassignment in array variable is not allowed
	print_array(arr,5);
	arr_func(arr,5); //passed as reference, changes made are reflected..
	print_array(arr,5);
}


int array_test_q6()
{
	/*
	 * 1. sizeof(array) --> no. of bytes allocated
	 * 2. &array, &array[0] --> address of first element
	 * 3. array = any other pointer --> this is invalid
	 * 4. char array[] = "abc" --> assigning a, b, c, '\0' to index 0,1,2,4 respectively
	 * 5. array++ is illegal
	 * 6 . variable size array cannot be initialized.
	 * */

int zero[0]={1};
print_array(zero,0);
printf("size of zero - %d\n",sizeof(zero));//size will be zero..
//zero[0] = 890;
//printf("zero[0] - %d\n",zero[0]);

int x = 90;
int arr1[x]; //this is valid
//int arr1[x] = {0}; // variable size array cannot be inited..
	int arr[]={1,2,3};
	//int y=2; u cannot write y[3]
	printf("%d,%d,%d",arr[0],1[arr],*(arr+2));//0,1,2nd element

}

int array_test_q7()
{

	char arr[] = "sankar"; // null is automatically inserted ,..size is 7
	printf("sizeof(arr) = %d strlen() = %d \n",sizeof(arr),strlen(arr)); //7 is the size including the null ; stlen will return 6
	char arr1[] = {'a', 'b','c'}; //size is 3;; this is not null termiated
	printf("arr1 = %s \n", arr1);

 }

int array_test_q8()
{
	int a1[][4] = {{1,2,3,4},{5,6,7,8}};
	//int a2[][][4] = {{1,2,3,4},{5,6,7,8}}; //this is a bug, we can have only first left most dimention empty
	printf("sizeof(a) = %d \n", sizeof(a1)); //32 --> 8 * 4
	int a2[][2][2] = {{{1,2},{3,4}}, {{5,6},{7,8}}};



}
/*deep copy of array when structures are assigned to another variable*/
typedef struct t1{

	int a[5];
}t1;

int array_test_q9()
{
	t1 s1 = {{1,2,3,4,5}};
	t1 s2;
	s2 = s1;
	s1.a[1] = 500;
	printf("s1.a = %d  %d\n", s1.a[1], s2.a[1]);// 500 , 2

}

/*strcat using one line...*/

int array_test_q10_strcat(char *dest, char *src)
{
	return (*dest)?array_test_q10_strcat(++dest,src):(*dest = *src)?array_test_q10_strcat(++dest, ++src):0;
}

int array_test_q10_strcmp(char *dest, char *src)
{
	return ((*dest == *src) && *src != '\0')?array_test_q10_strcmp(++dest, ++src):(*src == '\0')?0:*dest-*src;
}
int array_test_q10_strcmp_modified(char *dest, char *src)
{
	return (*dest && *src && (*dest == *src))?array_test_q10_strcmp(++dest, ++src):*dest-*src;
}

int mystrcmp_s(char *dst, char *src)
{
	while(*dst && *src && *dst == *src)
	{
		dst++;src++;
	}
	return (unsigned char)*dst - (unsigned char)*src;
}
int array_test_q11()
{
	/*diff between char s[] and char *s
	 *
	 * s[] - is an array.. we can change characters at index using s[i] = 'x';
	 * but if s1 is char * pointer. then s1[i] = j; this will cause a seg fault.
	 * */
	char s[] = "Hellosankar";
	char *s1 = "Hellosir";
	s[1] = 'A';
	//s1[2] = 'c'; // this will cause a segmentation fault; modifying a read only
	printf("%s ", s);
}

int array_test_q12()
{
	/*
	 * using fgets instead of gets
	 *
	 * */
	char str[5];
	fgets(str, 5, stdin);
	printf("Str = %s \n", str);

}
int swap_test_a(char **S);

int arrary_test_q13()
{
	char *s1 = "Hi";
	char *s2 = "Hello";

	char s3[100] = "Hello da";
	char s4[100] = "Hello sa";

//	s4 = s3;

	swap_string_a(&s3, &s4);

	swap_string(&s1, &s2); // only pointers can be swapped this way

	//swap_test_a(&s2);
	printf("%s & %s\n", s1,s2);
	printf("%s & %s\n", s3,s4);

}

int array_test_q14()
{
	char *test_ch[] = {"hello", "world"};
	char *t = "Wonderful";
	printf("1 : %s %p\n", *test_ch, &test_ch);//prints Hello
	printf("2 : %s %p\n", *(test_ch + 1), (test_ch + 1)); // print world

	printf("3 : %s %p\n", (t), &t); // Wonderful

	printf("3 : %s %p\n", (t+ 1),(char*)&t+1); // onderful


	char *x = 0; //incrementing the x, wil increase by size of the char
	char *x1[] = {44,45}; // incrementing array of pointer will increase by 4 irrespective of type of array
	int *ip = 0; //incrementing the ip, will increase by size of int
	printf("C : %p\n", ++x);
	printf("C* : %p\n", (x1 + 1)); //increments by 4
	printf("IP : %p\n", ++ip);

	//difference in pointers
	int *x2 = 45;
	int *x3 = 53;
	printf("Difference : %d \n", x3-x2);


}
int swap_test_a(char **S)
{
}
int swap_string(char **src, char **dest)
{
	char *temp = *src;
	*src = *dest;
	*dest = temp;
}

int swap_string_a(char *src, char *dest)
{
	char *temp = malloc(strlen(src));
	strcpy(temp, src);
	strcpy(src, dest);
	strcpy(dest,temp);

}


arr_func(int arr[], int n)
{
	/*arr is actually a pointer - changes made here reflects in caller*/
    int arr1[] = {1,2,4};
	int *ptr;
	ptr = arr; //this is valid..
	int c;
	ptr = arr1;
//	arr1 = &c; // this is invalid;
//arr = &c; // this is valid but it will
	printf("sizeof(arr) = %d\n",sizeof(arr));//result will be 4; sizeof int*;
	//this is the reason why we pass no of element in array

	arr[n-1] = 500;
}




int print_array(int *a, int n)
{
	int i = 0;
	for(;i<n;i++)
		printf("%d, ",a[i]);
	printf("\n");
}
