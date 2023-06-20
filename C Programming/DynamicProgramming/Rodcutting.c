#include<stdio.h>

#define MAX(A, B) (A)>=(B)?(A):(B)

int len = 8;
int price[] = {0,1,5,8,9,20,17,17,20};
int B[11] = {0};
int Cut[11] = {0};
int most_profit_cut = -1;
#if 1
void main_cur_rod()
{
	int i = 1;
	int max_val = -1;
	// printf("Hello world \n");
	for(;i<=8; i++)
	{
		int best = find_best(i, price);
		max_val = MAX(max_val, best);
		if(max_val == best)
		{
			most_profit_cut = i;
		}

	}
	printf("PSS best price is = %d\n", max_val);
	/*Back tracking to the cuts*/
	i = most_profit_cut;
	while(i > 0)
	{
		printf("Cuts are = %d\n", Cut[i]);
		if(i - Cut[i] > 0)
		{
			i = i - Cut[i];
		}
		else
		{
			i = 0;
		}
	}

}



//B(i) = max [vk + B(i-k)]

int  find_best(int len, int price[])
{

	int i = 0;
	int best = -1;
	for(i = 1; i<=len; i++)
	{
		int next_best = price[i] + B[len - i];
		best  = MAX(best, next_best);
		if(best == next_best)
		{
			Cut[len] = i;
		}

	}
	B[len] = best;
	printf("Best[%d]= %d \n",len, best);
	return best;

}


#endif
