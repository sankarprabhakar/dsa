
#include<stdio.h>
void array_of_pointers();
#if 0
void main()
{
array_of_pointers();
}
#endif
void array_of_pointers()
{
  	int *a[10];
  	int j =10, b=15,c=20,d=25,e=30,f=35,g=40,h=45;
  	a[0] = &j;
  	a[1] = &b;
  	a[2] = &c;
  	a[3] = &d;
  	a[4] = &e;
  	a[5] = &f;
  	a[6] = &g;
  	a[7] = &h;
  	int i = 0;
  	for(i = 0;i <= 7; i++)
  	printf("Value =  %d\n",*a[i]);
  	
 
}