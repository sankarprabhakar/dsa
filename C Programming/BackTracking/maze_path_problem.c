/*
 * maze_path_problem.c
 *
 *  Created on: Jan 12, 2017
 *      Author: sankarsa
 */


#include<stdbool.h>
#include<stdio.h>

bool SolveMaze(int n, int mat[][n], int i, int j, int sol[][n]);

bool SolveMazelu(int n, int mat[][n], int i, int j, int pi, int pj, int sol[][n]);
main_maze()
{
	int mat[][4] = {
			{1,0,0,0},
			{1,1,0,0},
			{1,1,1,0},
			{0,1,1,1}
	};
	int sol[][4] = {
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
	};

	//printSolution(4,mat);
	//printSolution(4,sol);
	bool x = SolveMazelu(4,mat,0,0,-1,-1,sol);
}


bool isSafe(int i, int j, int n, int mat[][n])
{

	if(i >= 0 && i<n && j>=0 && j<n && mat[i][j] == 1)
	{
	//	printf("(%d,%d %d) is safe\n", i,j, mat[i][j]);
		return true;
	}
	else
	{
		//printf("(%d,%d %d) is not safe\n", i,j, mat[i][j]);
		return false;
	}
}

bool SolveMaze(int n, int mat[][n], int i, int j, int sol[][n])
{

//	printSolution(n,mat);
	if(isSafe(i,j,n,mat))
	{

		sol[i][j] = 1; // it is a safe path to sit..
		if(i == n-1 && j == n-1)
		{
			printSolution( n, sol);
		}
		//SolveMaze(n,mat,i,i,sol);
		/*now check neighbours*/
		if(SolveMaze(n,mat,i+1,j,sol)) return true; //down
		if(SolveMaze(n,mat,i,j+1,sol)) return true; //right
		//if(SolveMaze(n,mat,i-1,j,sol)) return true; //left
		//if(SolveMaze(n,mat,i-1,j,sol)) return true; // up

		/*it reaches here if it cannot go any where*/
		sol[i][j] = 0;
		return false;
	}
	return false;
}



bool SolveMazelu(int n, int mat[][n], int i, int j, int pi, int pj,int sol[][n])
{

//	printSolution(n,mat);
	if(isSafe(i,j,n,mat))
	{

		sol[i][j] = 1; // it is a safe path to sit..
		if(i == n-1 && j == n-1)
		{
			printSolution( n, sol);
		}
		//SolveMaze(n,mat,i,i,sol);
		/*now check neighbors*/
		if( (i+1) >= 0 && (i+1) < n && !sol[i+1][j] && SolveMazelu(n,mat,i+1,j,i,j,sol)) return true; //down
		if((j+1) >= 0 && (j+1) < n && !sol[i][j+1] && SolveMazelu(n,mat,i,j+1,i,j,sol)) return true; //right

		if((i-1) >= 0 && (i-1) < n && !sol[i-1][j] && SolveMazelu(n,mat,i-1,j,i,j,sol)) return true; //up
		if((j-1) >= 0 && (j-1) < n && !sol[i][j-1] && SolveMazelu(n,mat,i,j-1,i,j,sol)) return true; // left

		/*it reaches here if it cannot go any where*/
		sol[i][j] = 0;
		return false;
	}
	return false;
}

printSolution(int n, int sol[][n])
{
	int i = 0, j = 0;
	for(i = 0;i<n; i++)
	{
		for(j = 0;j<n; j++)
		{
				printf("%d   ",sol[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}
