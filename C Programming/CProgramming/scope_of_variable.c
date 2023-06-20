/*
 * scope_of_variable.c
 *
 *  Created on: Dec 6, 2016
 *      Author: sankarsa
 */




int a = 90;
int a;

void main_scope()
{
	scope_test();
}

scope_test()
{
	//int a;
	//int a = a;
	int a = 99;
	{
	extern int a;
	printf("Value of global a = %d \n",a);
	}
	printf("Value of local a = %d \n",a);
	int b = 90;
	{
		{
			// a and b is acessible here..
			// Not the global a
		printf("Value of a= %d b = %d \n",a,b);
		}
	}
}
//int c = 123456;

extern int aa = 90;
int scope_test_2()
{
	//int c = c;
	//printf("\nC = %d \n",c);

	printf("\nAA = %d \n",aa);
	//printf("\nd = %d \n",d);
  int x = 1, y = 2, z = 3;

  printf(" x = %d, y = %d, z = %d \n", x, y, z); //1, 2 ,3
  {
       int x = 10;
       float y = 20;
       printf(" x = %d, y = %f, z = %d \n", x, y, z); //10,20.0,3
       {
             int z = 100;
             printf(" x = %d, y = %f, z = %d \n", x, y, z); //10,20.0,100
       }
  }
  return 0;
}

//int d;
