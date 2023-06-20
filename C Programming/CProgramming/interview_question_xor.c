/*
 * interview_question_xor.c
 *
 *  Created on: Dec 9, 2016
 *      Author: sankarsa
 */

#include<stdio.h>

/*
 * x ^ 1  - complements
 * x ^ 0  - same
 * x ^ x - 0
 * x ^ y - 1
 *
*/
int get_odd_occurance(int *input, int n)
{
	int xor = 0;
	 if(input != NULL)
	 {
		 int i = 0;
		 for(;i<n;i++)
		 {
			 xor ^= input[i];

		 }
	 }
	 return xor;
}


int find_missing_number(int *input, int n)
{

	int sum = n * (n+1)/2;
	int i = 0;
	int sum1 = 0;
	for(;i< (n-1); i++)
	{
		sum1 += input[i];
	}

	return sum - sum1;
}

int find_missing_no_xor(int *input, int n)
{
	int i = 0;
	int xor_n = 0;
	int xor_inp = 0;
	for(i = 1; i<= n; i++)
	{
		xor_n ^= i;
	}
	for(i = 0; i< n-1; i++)
	{
	   xor_inp ^= input[i];
	}

	return xor_inp ^ xor_n;
}


int test_opposite_sign(int x, int y)
{
	 if((x ^ y) < 0)
	 {
		 return 1;
	 }
	 else
		 return 0;
}

int test_num_of_bits_tobe_flipped(int from, int to)
{
	 int xor = from ^ to;

	 return countbits(xor);

}


int countbits(int n)
{
	 int count = 0;
	 while(n)
	 {
		count += (n & 1);
		n>>=1;
	 }
	 return count;
}

int find_power_of_2(n)
{
	return !(n & (n-1));
}


int countbits_logn(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n = n & (n-1);
	}
	return count;
}


int countbits_builtin(int n)
{
	return __builtin_popcount(n);
}

/*input is array of number which repeats thrice except one number*/
int find_non_rep_element_other_element_rep_thrice(int *input, int n)
{
	int i = 0, j = 0, sum = 0, mask = 0, non_rep = 0;
	for(i = 0; i <32; i++)
	{
		sum = 0;
		mask = 1 << i;
		for(j = 0 ; j < n; j++)
		{
			if(input[j] & mask)
			{
				sum++;
			}
		}
		if(sum%3 != 0)
		{
			non_rep |= mask;
		}

	}
	return non_rep;
}


int find_non_rep_element_other_element_rep_thrice_xor(int *input, int n)
{
	int ones = 0, twos= 0, not_threes = 0, i = 0, x = 0,common_ones = 0;
	for( i = 0; i<n; i++)
	{
		x = input[i];
		twos |= (ones & x);
		ones ^= x;

		common_ones = ~(ones & twos);
		ones &= common_ones;
		twos &= common_ones;

	}
	return ones;
}


int swaping_n_bits_btw_p1_to_p2(int input, int p1, int p2, int bits)
{

	int set1 = (input >> p1) & ((1U << bits) -1);
	int set2 = (input >> p2) & ((1U << bits) -1);
	int xor = set1 ^ set2;

	xor = (xor << p2 | xor << p1);

	return input ^ xor;
}

int adding_two_number_xor(int x, int y)
{
	int carry = 0;
	while(y)
	{
		carry = x & y; //getting carry
		x = x^y ; //sum
		y = carry << 1; //left shifting carry to be added in next iteration.

	}
	return x;
}

int multiplying_without_mul_operator(int x)
{
	return ((x << 3) + (x << 1));
}

int find_two_non_rep_elements(int *input, int n,int *x, int *y)
{
	int xor = 0;
int i = 0;
	for(i = 0; i<n; i++)
	{
		xor ^= input[i];
	}

	//select a number in xor.. letus set the last "1" in xor
	int last_set_bit = xor & ~(xor-1);

	for( i = 0; i<n; i++)
	{
			if(input[i] & last_set_bit)
			{
				*x ^= input[i];
			}
			else
			{
				*y ^= input[i];
			}
	}


}



