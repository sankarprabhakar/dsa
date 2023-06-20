/*
 * graph_representation.c
 *
 *  Created on: Dec 15, 2016
 *      Author: sankarsa
 */


/*Adjacency matrix*/

#include<stdio.h>

#include"graph.h"
ADJ_MATRIX * CreateAdjMatrix(int num_nodes, int isdirected)
{

    ADJ_MATRIX *matrix = malloc(sizeof(ADJ_MATRIX));
    matrix->num_nodes = num_nodes;
    matrix->dir = isdirected;


	int *array = (int *)malloc(sizeof(int)*num_nodes*num_nodes);
	if(array != NULL)
	{
		int (*q)[num_nodes] = array;
		int i = 0, j=0;
		for(i = 0; i< num_nodes; i++)
		{
			for(j = 0; j< num_nodes; j++)
			{
				  q[i][j] = 0;
			}

		}
	}
	matrix->matrix = array;
	return matrix;
}


int AddEdge(ADJ_MATRIX *m, int src, int dest, int weight)
{
	if(src >= m->num_nodes ||  dest >= m->num_nodes)
	{
		return 0;
	}
	int (*q)[m->num_nodes] = m->matrix;
	q[src][dest] = weight;

	if(!m->dir)
	{
		q[dest][src] = weight;
	}
	return 1;
}


void printGraph(ADJ_MATRIX *matrix)
{
	    int (*q)[matrix->num_nodes] = matrix->matrix;
		int i = 0, j=0, num_nodes = matrix->num_nodes;
		for(i = 0; i< num_nodes; i++)
		{
			if(i == 0)
			{
				printf("     ");
				for(;j<num_nodes;j++)
				{
					printf("%3d ", j);
				}
				printf("\n");
				for(j=0;j<num_nodes;j++)
				{
				    printf("-----");
				}
				printf("\n");
			}
			for(j = 0; j< num_nodes; j++)
			{
				if(j == 0)
				{
					printf("%3d |",i);
				}
				printf("%3d ",q[i][j]);
			}
			printf("\n");

		}
}
