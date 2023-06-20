/*
 * prims_mst.c
 *
 *  Created on: Dec 25, 2016
 *      Author: sankarsa
 */


/*
 * dijkstras_single_source_shortest_path.c
 *
 *  Created on: Dec 25, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<limits.h>

/*Greedy algorithm*/

/* D-S matained
 * 1. unvisitedSet
 * 2. distance vector
 *
 * Algorith
 * 1. Selected starting node and add to unvisited set
 * 2. initialize distance vector to "INFINITY". Assign "0" to distance of first node
 * 3. while all vertex are not available in unvisited set
 * 		3.a. Select a vertex 'u', with minimum distance
 * 		3.b. Add  the selected vertex to unvisited set
 * 		3.c. Update the distance vector for nodes adjacent to  'u'. if dist[v] >  u-v dist. then update
 * 		dist[v]
 * */


int test_prims_algo()
{
	int g1[][9] = {
		   /*0,1,2,3,4,5,6,7,8*/
			{0,4,0,0,0,0,0,8,0},
			{4,0,8,0,0,0,0,11,0},
			{0,8,0,7,0,4,0,0,2},
			{0,0,7,0,9,14,0,0,0},
			{0,1,0,9,0,10,0,0,0},
			{0,0,4,14,10,0,2,0,0},
			{0,0,0,0,0,2,0,1,6},
			{8,11,0,0,0,0,1,0,7},
			{0,1,2,0,0,0,6,7,0}
	};
	prims_algorithm(9,g1,0);
printf("----------------------------------------------\n");
	 int g2[][5]= {{0, 2, 0, 6, 0},
	                      {2, 0, 3, 8, 5},
	                      {0, 3, 0, 0, 7},
	                      {6, 8, 0, 0, 9},
	                      {0, 5, 7, 9, 0}
	                     };
	 prims_algorithm(5,g2,0);


}

//int * get_unvisited_set(int size, int first_node)
//{
//	 int *set =  malloc(size * sizeof(int));
//	 memset(set,0,size*sizeof(int));
//	// set[first_node] = 0;
//	 return set;
//}
//
//int * get_parent_set(int size)
//{
//	 int *set =  malloc(size * sizeof(int));
//	 memset(set,0,size*sizeof(int));
//	 return set;
//}
//int *get_distance_vector(int size, int first_node)
//{
//	  int *dist = malloc(size*sizeof( int));
//	 memset(dist, INT_MAX, sizeof( int) * size);
//	 dist[first_node] = 0;
//	 return dist;
//}

//int get_min_dis_unvisted_node(int *un_visited_set, unsigned int *dist_vector, int size)
//{
//	int i = 0;
//	int min = INT_MAX;
//	int unvisit_node = -1;
//	for(;i<size; i++)
//	{
//		if((un_visited_set[i] == 0) && dist_vector[i] <= min)
//		{
//          //  printf("%u %u",dist_vector[i], min);
//			min = dist_vector[i];
//			unvisit_node = i;
//			//printf("unvi_node = %d \n", unvisit_node);
//		}
//	}
//
////	printf("Ret\n");
//return unvisit_node;
//}

int prims_algorithm(int v, int *G, int start_vertex)
{
	int (*g)[v] = G;

	int *un_visited_set = get_unvisited_set(v,start_vertex);
	unsigned int *dist_vector = get_distance_vector(v, start_vertex);
	int *parent = get_parent_set(v);

	int unvis_node;
	while ((unvis_node = get_min_dis_unvisted_node(un_visited_set, dist_vector, v)) != -1)
	{
		un_visited_set[unvis_node] = 1;
		int i = 0;
		for(; i<v; i++)
		{
			if(!un_visited_set[i]  && g[unvis_node][i] && (dist_vector[i] > g[unvis_node][i]))
			{
				parent[i] = unvis_node;
				dist_vector[i] =  g[unvis_node][i];
			}

		}
		//print_distance_vec(dist_vector, v, start_vertex);
	}

	print_distance_vec(dist_vector, v, start_vertex, parent);
}

//print_distance_vec(int *dist_vector, int v, int start_vertex,int *parent)
//{
//	int i = 0;
//	for(; i <v;i++)
//	{
//		printf("%d-%d    %d\n",parent[i], i, dist_vector[i]);
//	}
//}

