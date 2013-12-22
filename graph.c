// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <xmmintrin.h>

float **allocate_memory() {
  int i;
  float **graph;

  graph = (float**) _mm_malloc(GRAPHSIZE * sizeof(float *), 16);
  for (i = 0; i < GRAPHSIZE; i++) {
    graph[i] = (float *) _mm_malloc(GRAPHSIZE * sizeof(float), 16);
  }
  
  return graph;
}

void draw_connections(float **graph) {
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

float **create_graph() {
  float **graph;

  graph = allocate_memory();
  draw_connections(graph);

  return graph;
}

print_graph(int **graph) {
  int i, j;
  
  for (i = 0; i < GRAPHSIZE; i++) {
    for (j = 0; j < GRAPHSIZE; j++) {
      printf("%i ", graph[i][j]);
    }
    printf("\n");
  }
}
