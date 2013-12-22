// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#define INFINITY  999999

#define GRAPHSIZE 10000
#define MAXWEIGHT 100
#define MINWEIGHT 50

#define TARGET    7777

float **create_graph();
int *init_path();

int *dijkstra_algorithm(float **graph);
int *auction_algorithm(float **graph);
int *auction_algorithm_sse(float **graph);
