// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>
#include <time.h>

void print_path(int *path) {
  int i;

  printf("path: ");
  for (i = 0; i < GRAPHSIZE; i++) {
    if (path[i] != INFINITY)
      printf("%i ", path[i]);
  }
  printf("\n"); 
}

void print_exec_time(int tic, int toc) {
  printf("time: %.2f ms\n\n",
	 (double)(toc - tic) / CLOCKS_PER_SEC * 1000);
}

void print_cost(int *path, int **graph) {
  int cost, i;

  for (i = 0; i < GRAPHSIZE-1; i++) {
    if (path[i] != INFINITY && path[i+1] != INFINITY) {
      cost += graph[path[i]][path[i+1]];
    }
  }
  printf("cost: %i\n", cost);
}

int main() {
  clock_t tic, toc;
  int **graph, *path;

  graph = create_graph();

  printf("\n::dijkstra::\n");
  tic = clock();
  path  = dijkstra_algorithm(graph);
  toc = clock();
  print_path(path);
  print_cost(path, graph);
  print_exec_time(tic, toc);

  printf("::auction::\n");
  tic = clock();
  path  = auction_algorithm(graph);
  toc = clock();
  print_path(path);
  print_cost(path, graph);
  print_exec_time(tic, toc);

  return 0;
}

