/*
 * sizeof_types.c
 *
 *  Created on: Oct 15, 2017
 *      Author: prabhaka
 */

#include<stdint.h>
#include<error.h>





void print_sizeof()
{
	//static_assert(sizeof(void*) == 4);
	printf("siseof(int) = %d \n", sizeof(int));
	printf("siseof(*int) = %d \n", sizeof(int *));//pointer to interget is 8bytes. <<64bits>>
	printf("siseof(unsigned int) = %d \n", sizeof(unsigned int));
	printf("siseof(long int) = %d \n", sizeof(long int));
	printf("siseof(long long int) = %d \n", sizeof(long long int));
	printf("siseof(short int) = %d \n", sizeof(short int));
	printf("siseof(char ) = %d \n", sizeof(char));
	printf("siseof(float) = %d \n", sizeof(float));
	printf("siseof(double) = %d \n", sizeof(double));
	printf("siseof(long double) = %d \n", sizeof(long double));
	printf("siseof(56) = %d \n", sizeof(56));
	printf("siseof(-56) = %d \n", sizeof(-56));
	printf("siseof(8.88) = %d \n", sizeof(8.88));
	int x = 99;
	printf("siseof(x+8) = %d \n", sizeof(x+8));
	printf("siseof(8.88F) = %d \n", sizeof(8.88F));
	printf("siseof(int64_t) = %d \n", sizeof(int64_t)); //64bits


	//printf("typeof(78) %s\n", typeof(78));
}
