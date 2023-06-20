/*
 * interview_mathametics.c
 *
 *  Created on: Jan 5, 2017
 *      Author: sankarsa
 */


double square_root(int n);
main_gcd()
{
	test_gcd_q1();
	//test_sqrt();
}
int test_gcd_q1()
{
	int gcd1 = gcd(98,56);
	printf("Gcd of 98,56 = %d\n",gcd1);

	int gcd2 = gcd_iterative(98,56);
	printf("Gcd of 98,56 = %d\n",gcd2);
}

int test_sqrt()
{
	double x = square_root(5);
	printf("sqrt of 2 = %f\n", x);
	}

/*recursive gcd function*/
int gcd(int x, int y)
{
	if(x == 0 || y == 0)
	{
		return 0;
	}
	else if(x == y)
	{
		return x;
	}

	if(x > y)
		return gcd(x-y, y);
	return gcd(x, y-x);
}

int gcd_iterative(int a,int b)
{
	if(a == 0 || b==0)
	{
		return 0;
	}
	else if(a == b)
	{
		return a;
	}

	while(a!=b)
	{
		if(a > b)
			a = a-b;
		else
			b = b -a;
	}
	return a;

}


double square_root(int n)
{
	double start = 1;
	double end = n;
	double error = 0.0001;

	while(end - start > error)
	{
		end = (start + end)/2;
		start = n/end;

	}


return start;
}
double calcErrFactor(double m, double n)
{
	if( m*m*m > n)
	{
		return m*m*m - n;
	}
	else
	{
		return n - m*m*m;
	}
}


double cube_root(int n)
{
	double error = 0.000001;
	double start = 0;
	double end = n;
	double mid = 0;
	double err = 0;
	while(1)
	{
		mid = (start + end)/2;
		err = calcErrFactor(mid , n);

		if(err < error)
			return mid;

		if(mid * mid * mid > n)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}

	}
}
