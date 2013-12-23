// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#define INFINITY  999999

#define GRAPHSIZE 1000
#define MAXWEIGHT 10
#define MINWEIGHT 5
#define SURROUND  50

#define TARGET    999

#define RUNS_NO   5

float **create_graph();
int *init_path();

int *dijkstra_algorithm(float **graph);
int *auction_algorithm(float **graph);
int *auction_algorithm_sse(float **graph);
