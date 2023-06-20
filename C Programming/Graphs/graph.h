/*
 * graph.h
 *
 *  Created on: Dec 15, 2016
 *      Author: sankarsa
 */

#ifndef GRAPH_H_
#define GRAPH_H_


typedef struct adjmatrix{

	int num_nodes;
	int dir;
	int *matrix;
}ADJ_MATRIX;



typedef struct adjlistnode
{
	int dest; //destination node
	int weight; //weitage of path
	struct adjlistnode *next;
}ADJ_NODE;

typedef struct adjlist
{
	ADJ_NODE *head;

}ADJ_LIST;

typedef struct adjlistgraph
{
	int num_vertices;
	int dir;
	ADJ_LIST *arr;
}ADJ_LIST_GRAPH;


#endif /* GRAPH_H_ */
