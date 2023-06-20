#include<stdio.h>

void array_1d(void);
void array_2d(void);

#define SACK_WEIGHT 11
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


DATACELL * getArray()
{

		DATACELL (*p)[SACK_WEIGHT+1] = malloc(sizeof(DATACELL) * MAX_ITEMS * (SACK_WEIGHT+1));

		int i = 0, j = 0;
		for(i = 0; i<MAX_ITEMS ; i++)
		{
			for(j= 0 ; j<SACK_WEIGHT+1; j++)
			{
				p[i][j].max_benefit = -1;
				p[i][j].total_items = 0;
				memset(p[i][j].selected_items,0x00,MAX_ITEMS * 4);
			}
		}
		return p;
}

void main_knap(int argc, char *argv[])
{

	DATACELL (*p)[SACK_WEIGHT+1];
	p = getArray();
	int i = 0, j = 0;

	int * array = malloc(sizeof(int) * (MAX_ITEMS+1));
	int total_items;
	for(i = 0; i<MAX_ITEMS ; i++)
	{
		for(j= 0 ; j<SACK_WEIGHT+1; j++)
		{

			total_items = 0;
			memset(array, 0x00 , sizeof(int) * (MAX_ITEMS+1));
			if(i == 0 || j == 0)
			{
				p[i][j].max_benefit = 0;
				p[i][j].total_items = 0;
			}
			else
			{
				int b_without_i =  p[i-1][j].max_benefit;
				int b_with_i;


				if(w[i] <= j)
				{
					 total_items =0;
					 b_with_i = b[i] + p[i-1][j-w[i]].max_benefit;

					 //Retrace logic
                     total_items = p[i-1][j-w[i]].total_items + 1;
                     if(p[i-1][j-w[i]].total_items>0)
                     {
                    	 memcpy(array, p[i-1][j-w[i]].selected_items, MAX_ITEMS * 4);
                     }
                     array[total_items] = w[i];

				}
				else
					b_with_i = -1;


				if(b_without_i < b_with_i)
				{
					p[i][j].max_benefit = b_with_i;
					//retrace logic
					p[i][j].total_items = total_items;
					if(p[i][j].total_items > 0)
					memcpy(p[i][j].selected_items,array, 4*(MAX_ITEMS+1));


				}
				else
				{
					p[i][j].max_benefit = b_without_i;
					//retrace logic

					p[i][j].total_items =  p[i-1][j].total_items;
					if(p[i][j].total_items > 0)
						memcpy(p[i][j].selected_items,p[i-1][j].selected_items, 4*(MAX_ITEMS+1));


				}
			}
			printf("%2d[%d]{%d,%d,%d,%d,%d}\t",p[i][j].max_benefit, p[i][j].total_items,
					p[i][j].selected_items[0],
					p[i][j].selected_items[1],
					p[i][j].selected_items[2],
					p[i][j].selected_items[3],
					p[i][j].selected_items[4]
					);
		//	p[i][j].total_items = -1;
		}
		printf("\n");
	}

//	for(i = 0; i<5; i++)
//		printf("%d,", p[4][5].selected_items[i]);


}
