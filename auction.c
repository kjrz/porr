// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"

// is node already in path
int in_path(int *path, int j) {
  int i;

  for (i = 0; i < GRAPHSIZE; i++) {
    if (path[i] == INFINITY)              // end of path reached
      return 0;
    if (path[i] == j)                     // found node in path
      return 1;
  }
  return 0;
}

int *auction_algorithm(float **graph) {
  int j, terminal, arg_min, *path;
  float min, j_dist;

  float prices[GRAPHSIZE] = {0};          // init to zeroes
  path = init_path();                     // init to INFINITIES
	
  path[0]  = 0;                           // start off with the source node
  terminal = 0;                           // points to current end of path
	
  while (path[terminal] != TARGET) {
    min     = INFINITY;
    arg_min = 0;
    for (j = 0; j < GRAPHSIZE; j++) {     // for each neighbour of terminal
      if (in_path(path, j))               // omit if already in path
	continue;

      j_dist                              // calculate 
	= graph[path[terminal]][j]        // distance to neighbour
	+ prices[j];                      // + neighbour price

      if (j_dist < min) {                 // if this is closer than ever,
	min = j_dist;                     // remember the distance
	arg_min = j;                      // and the neighbour index
      }
    }
		                          // choose step

    if (prices[path[terminal]] < min) {   // step 1
      prices[path[terminal]] = min;       // p := min
      if (terminal != 0)		  // contract P
	path[terminal--] = INFINITY;
    } else {                              // step 2
      path[++terminal] = arg_min;         // extend P
    }
  }
  
  return path;
}
