/*
 * fibnocci_using_dp.c
 *
 *  Created on: Aug 26, 2016
 *      Author: sankarsa
 */


#include<stdio.h>

int main_fib(int argc, char*argv[])
{
	fibanocci(5);
}


int factorial(int n)
{
	printf("%d\n", n);
	if(n==1)
		return 1;
	else
		return n * factorial(n-1);
}


int fibanocci(int n)
{
	int y;
	static int  x= 0;
	x++;
	printf("%d \n",x);
	if(n==1 || n==2)
	{
		return 1;
	}
	else
	{
	 y = fibanocci(n-1);
	// printf("*");
	 y+= fibanocci(n-2);
	// printf("-**-");
	}
	return y;

}

int fib[100] = {0,0};
int fibanocci_dp(int n)
{
	int y;
	static int  x= 0;
	x++;
	printf("%d \n",x);
	if(n==1 || n==2)
	{
		return 1;
	}
	else if(fib[n] != 0)
	{
		printf("stored\n");
	    return fib[n];
	}
	else
	{
	 y = fibanocci_dp(n-1);
	// fib[n-1] = y;
	 // printf("*");
	 y+= fibanocci_dp(n-2);
	 //fib[n-1] = y-fib[n-1];
	 fib[n] = y;
	// printf("-**-");
	}
	return y;

}



int fibanocci_dp_bottom_up(int n)
{
	int fibnocci[n];
	int i = 0;
	for(i = 0; i < n ; i++)
	{
		if(i == 0 || i==1)
		{
			fibnocci[i] = 1;
		}
		else
		fibnocci[i] = fibnocci[i-1] + fibnocci[i-2];

	}
	return fibnocci[n-1];

}
