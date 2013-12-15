// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#define INFINITY  999999

#define GRAPHSIZE 10000
#define MAXWEIGHT 100
#define MINWEIGHT 50

#define TARGET    7777

int **create_graph();
int *init_path();

int *dijkstra_algorithm(int **graph);
int *auction_algorithm (int **graph);
