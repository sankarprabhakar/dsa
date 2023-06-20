/*
 * main.c
 *
 *  Created on: Dec 15, 2016
 *      Author: sankarsa
 */

#include"graph.h"


int main()
{
//	int x = 9;
//	int array[x];
//
//	array[0] = 89;

//	printf("%d %d", array[0], sizeof(array)/sizeof(array[0]));

	//ADJ_MATRIX *matrix = CreateAdjMatrix(8,1);
//	printf("Num element = %d \n", matrix->num_nodes);




	//AddEdge(matrix, 0,1,55);
//	AddEdge(matrix, 1,4,56);

	//AddEdge(matrix, 0,0,56);

	//printGraph(matrix);

//	ADJ_LIST_GRAPH *g = CreateAdjListGraph(5,1);
//
//	AddEdge_am(g, 0,1,5);
//	AddEdge_am(g, 1,2,7);
//	AddEdge_am(g, 3,4,9);
//
//	printAdjListMatrix(g);

//	test_dijkstra_algo();
	test_prims_algo();

}
