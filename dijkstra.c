// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"

int not_empty(int *Q) {
  int i;
  for (i = 0; i < GRAPHSIZE; i++) {
    if (Q[i] == 1)
      return 1;
  }
  return 0;
}

// find node in queue with smallest distance
// and not yet visited
int find_u(int *Q, float *dist, int *visited) {
  int i, u, smallest_dist;
	
  smallest_dist = INFINITY;
  for (i = 0; i < GRAPHSIZE; i++) {
    if (Q[i] == 1 && dist[i] < smallest_dist) {
      smallest_dist = dist[i];
      u = i;
    }
  }

  return u;
}

int *read_path(int *previous) {
  int i, u, *path;
  
  path = init_path();
		
  i = GRAPHSIZE - 1;
  u = TARGET;
  path[i] = u;
  while (u != 0) {
    i--;
    u = previous[u];
    path[i] = u;
  }

  return path;
}

int *dijkstra_algorithm(float **graph) {
  int i, u, v, alt;                      // utility variables
  int Q[GRAPHSIZE] = {0};                // empty Q

  float dist[GRAPHSIZE];
  for (i = 0; i < GRAPHSIZE; i++)
    dist[i] = INFINITY;
	
  int visited [GRAPHSIZE] = {0};         // mark all nodes as unvisited
  int previous[GRAPHSIZE] = {0};         // previous node in optimal path 
                                         // from source

  dist[0] = 0;                           // distance from source to itself is zero
  Q   [0] = 1;                           // start off with the source node

  while (not_empty(Q)) {
    u = find_u(Q, dist, visited);        // see function desc
    if (u == TARGET)                     // terminate once target is reached
      break;

    Q[u]       = 0;                      // remove this node from Q
    visited[u] = 1;                      // mark it as visited

    for (v = 0; v < GRAPHSIZE; v++) {
      if (!graph[u][v] == INFINITY)      // neighbours only
	continue;

      alt = dist[u] + graph[u][v];       // accumulate shortest distance 
                                         // from source
      if (alt < dist[v]) {
	dist[v] = alt;                   // keep the shortest distance
                                         // from source to v
	previous[v]  = u;

	if (!visited[v])	         // add unvisited v to Q
          Q[v] = 1;                      // to be processed
      }
    }
  }
	
  return read_path(previous);
}
