// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"

#include <stdio.h>
#include <time.h>
#include <malloc.h>

int *init_path() {
  int i, *path;

  path = (int *) malloc(GRAPHSIZE * sizeof(int *));
  for (i = 0; i < GRAPHSIZE; i++) {
    path[i] = INFINITY;
  }
  
  return path;
}

void print_path(int *path) {
  int i;

  printf("path: ");
  for (i = 0; i < GRAPHSIZE; i++) {
    if (path[i] != INFINITY)
      printf("%d ", path[i]);
  }
  printf("\n"); 
}

float read_exec_time(int tic, int toc) {
  float answer;
  answer = (float) (toc - tic) / CLOCKS_PER_SEC * 1000;
  return answer;
}

void print_average_exec_time(float *exec_times) {
  int i;
  float sum, avg;
  
  sum = 0;
  for (i = 0; i < RUNS_NO; i++) {
    sum += exec_times[i];
  }
  avg = sum / RUNS_NO;
  printf("time: %.2f ms\n\n", avg);
}

void print_cost(int *path, float **graph) {
  int i;
  float cost;

  for (i = 0; i < GRAPHSIZE-1; i++) {
    if (path[i] != INFINITY && path[i+1] != INFINITY) {
      cost += graph[path[i]][path[i+1]];
    }
  }
  printf("cost: %.0f\n", cost);
}

int main() {
  clock_t tic, toc;
  float **graph, *exec_times;
  int i, *path;

  graph = create_graph();

  exec_times =
    (float *) malloc(RUNS_NO * sizeof(float));

  printf("\n::dijkstra::\n");                     // run RUNS_NO times
  for (i = 0; i < RUNS_NO; i++) {                 // to get average exec time
    tic = clock();                                // start timer
    path = dijkstra_algorithm(graph);             // run algorithm
    toc = clock();                                // stop timer
    exec_times[i] = read_exec_time(tic, toc);     // remember exec time
  }
  print_path(path);                               // print result
  print_cost(path, graph);                        // print result
  print_average_exec_time(exec_times);            // print average time

  printf("::auction::\n");                        // same for next algorithm
  for (i = 0; i < RUNS_NO; i++) {
    tic = clock();
    path = auction_algorithm(graph);
    toc = clock();
    exec_times[i] = read_exec_time(tic, toc);
  }
  print_path(path);
  print_cost(path, graph);
  print_average_exec_time(exec_times);

  printf("::auction sse::\n");
  for (i = 0; i < RUNS_NO; i++) {
    tic = clock();
    path = auction_algorithm_sse(graph);
    toc = clock();
    exec_times[i] = read_exec_time(tic, toc);
  }
  print_path(path);
  print_cost(path, graph);
  print_average_exec_time(exec_times);

  return 0;
}
