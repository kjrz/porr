// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>
#include <malloc.h>

int in_path(int *path, int j) {           // is node already in path
  int i;

  for (i = 0; i < GRAPHSIZE; i++) {
    if (path[i] == INFINITY)
      return 0;
    if (path[i] == j)
      return 1;
  }
  return 0;
}

int *auction_algorithm(int **graph) {
  int terminal,				  // points to current end of path
      arg_min, min, j, j_dist;            // utils for finding min in algorithm

  int prices[GRAPHSIZE] = {0};            // from source to each node - unknown
  int *path             = init_path();    // from source to target - unknown

	
  path[0]  = 0;				  // start off with the source node
  terminal = 0;                           // points to current end of path
	
  while (path[terminal] != TARGET) {
    min     = INFINITY;                   // finding min in algorithm
    arg_min = 0;
    for (j = 0; j < GRAPHSIZE; j++) {
      if (in_path(path, j))
	continue;
      j_dist = graph[path[terminal]][j] + prices[j];
      if (j_dist < min) {
	min = j_dist;
	arg_min = j;
      }
    }
		                          // choose step

    if (prices[path[terminal]] < min) {   // step 1
      prices[path[terminal]] = min;	  // p := min
      if (terminal != 0)		  // contract P
	path[terminal--] = INFINITY;
    } else {                              // step 2
      path[++terminal] = arg_min;	  // extend P
    }
  }
  
  return path;
}

