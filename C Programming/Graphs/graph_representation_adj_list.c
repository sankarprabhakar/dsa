/*
 * graph_representation_adj_list.c
 *
 *  Created on: Dec 15, 2016
 *      Author: sankarsa
 */

#include <stdio.h>

#include "graph.h"


ADJ_LIST_GRAPH * CreateAdjListGraph(int num_nodes, int isDirected)
{
	ADJ_LIST_GRAPH *adjlist = (ADJ_LIST_GRAPH *)malloc(sizeof(ADJ_LIST_GRAPH));
	adjlist->num_vertices = num_nodes;
	adjlist->arr = (ADJ_LIST *)malloc(num_nodes * sizeof(ADJ_LIST));
	memset(adjlist->arr, '\0', num_nodes * sizeof(ADJ_LIST));
	adjlist->dir = isDirected;
	return adjlist;
}


ADJ_NODE *CreateAdjNode(int dest, int weight)
{

	ADJ_NODE *adjnode = (ADJ_NODE *)malloc(sizeof(ADJ_NODE));
    adjnode->dest = dest;
    adjnode->next = NULL;
    adjnode->weight = weight;

}

int AddEdge_am(ADJ_LIST_GRAPH *g, int src, int dest, int weight)
{
	if(src >= g->num_vertices ||  dest >= g->num_vertices)
	{
			return 0;
	}
	ADJ_NODE *adjnode = CreateAdjNode(dest,weight);

	adjnode->next = g->arr[src].head;
	g->arr[src].head = adjnode;

	if(!g->dir)
	{
		ADJ_NODE *adjnode = CreateAdjNode(src,weight);
		adjnode->next = g->arr[dest].head;
		g->arr[dest].head = adjnode;

	}
}

void printAdjListMatrix(ADJ_LIST_GRAPH *g)
{
	int i = 0;
	ADJ_NODE *t;
    for(;i< g->num_vertices;i++)
    {
    	printf("%3d", i);
    	t= g->arr[i].head;
    	while(t)
    	{
    		printf(" --> %3d<%d>", t->dest,t->weight);
    		t = t->next;
    	}
    	printf("\n");
    }

}
