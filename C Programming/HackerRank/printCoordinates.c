

void print_coordinates()
{
	int i = 0;
	int j = 0;
	for(i = 1 ; i<3 ; i++)
	{
		for(j = 1 ; j<10 ; j++)
		{
			if(i%2 == 0 && j%3 == 0)
				printf("(%d %d)\n", i,j);
		}
	}
}
