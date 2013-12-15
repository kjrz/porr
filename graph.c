#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "porr.h"

int **allocate_memory() {
  int i,j, **graph;

  graph = (int**) malloc(GRAPHSIZE * sizeof(int *));
  for (i = 0; i < GRAPHSIZE; i++) {
    graph[i] = (int *) malloc(GRAPHSIZE * sizeof(int));
  }
  
  return graph;
}

void draw_connections(int **graph) {
  int i, j, val;

  srand(time(NULL));
  for (i = 0; i < GRAPHSIZE; i++) {
    for (j = 0; j <= i; j++) {
      if (i == j) {
	graph[i][j] = INFINITY;
	graph[j][i] = INFINITY;
      } else {
	val = rand()%MAXWEIGHT;
	if (val < MINWEIGHT) {
	  graph[i][j] = INFINITY;
	  graph[j][i] = INFINITY;
	} else {
	  graph[i][j] = val;
	  graph[j][i] = val;
	}
      }
    }
  }
}

int **create_graph() {
  int **graph;

  graph = allocate_memory();
  draw_connections(graph);

  return graph;
}

void print_graph(int **graph) {
  int i, j;

  for (i = 0; i < GRAPHSIZE; i++) {
    for (j = 0; j < GRAPHSIZE; j++) {
      printf("%i ", graph[i][j]);
    }
    printf("\n");
  }
}

