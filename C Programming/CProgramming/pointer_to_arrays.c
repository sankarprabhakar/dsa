#include<stdio.h>

void array_1d(void);
void array_2d(void);

#define SACK_WEIGHT 5
#define MAX_ITEMS 5
#define MAX(A, B) (A)>=(B)?(A):(B)

int w[MAX_ITEMS] = {0,2,3,4,5}; //weights
int b[MAX_ITEMS] = {0,3,4,5,6}; // benefits


typedef struct DataCell
{
	int max_benefit;
	int total_items;
	int selected_items[MAX_ITEMS];
}DATACELL;
#if 1
void p_to_arr_main(int argc, char *argv[])
{


	array_1d();
	array_2d();

}

#endif


void array_1d(void)
{

	int a[5];
	int i = 0, j = 0;
	int *p = a;
	for(i = 0 ; i<5; i++)
	{
		printf("%d %d\n", a+i, p+i);
	}

}


void array_2d(void)
{
	int k=90;
	int z[k];

	int a[2][3] = {{8,9,0},{1,2,3}};
	//printf("sizeof[a] = %d \n",sizeof(a)/4);
	int i = 0, j = 0;
	int *p = a;
	int (*q)[3] = a; // q is pointer to 2 dimentional array of 3 elements.

	printf("a = %lu  a[0] = %lu *(a[0]+1) =%lu a[1] = %lu\n",a,a[0],*(a[0]+1),a[1]);

	printf("*a = %lu *a+1 = %lu  (a+1) = %lu *(a+1) =%lu %d\n",*a,*a+1,a+1,*(a+1), **(a+1));

	printf("*(*a+1) = %lu \n",*(*a+1));

	for(i = 0 ; i<2; i++)
	{
		printf("%d %d %d\n", a+i, p+i, q+i);
	}
//int j = 0;
	for(i = 0 ; i<2; i++)
	{
		for(j = 0; j<3; j++)
		printf("%d %d %d %d\n", a+i, p+i,q+i ,*(*(q+i)+j));
	}
	// p + (i * /*number of columns*/) + j
}
