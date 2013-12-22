// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>
#include <xmmintrin.h>

#define SSE_FOUR 4

float *init_prices() {
  int i;

  float *prices = (float *) _mm_malloc(GRAPHSIZE * sizeof(float), 16);
  for (i = 0; i < GRAPHSIZE; i++) {
    prices[i] = 0;
  }

  return prices;
}

int in_path_sse(int *path, int j) {
  int i;

  for (i = 0; i < GRAPHSIZE; i++) {
    if (path[i] == INFINITY)              // end of path reached
      return 0;
    if (path[i] == j)                     // found node in path
      return 1;
  }

  return 0;
}

void dist_price_sse(float *dist, float *prices, float *dist_price) {
  __m128 asse, bsse, csse;
  int i;

  for (i = 0; i < GRAPHSIZE; i += SSE_FOUR) {
    asse = _mm_load_ps(&dist[i]);
    bsse = _mm_load_ps(&prices[i]);
    csse = _mm_add_ps (asse, bsse);
    _mm_store_ps(&dist_price[i], csse);
  }
}

void find_min(float *dist_price, int *path, int *arg_min, float *min) {
  int i;

  *min     = INFINITY;
  *arg_min = 0;

  for (i = 0; i < GRAPHSIZE; i++) {
    if (dist_price[i] < *min && !in_path_sse(path, i)) {
      *min = dist_price[i];
      *arg_min = i;
    }
  }  
}

int *auction_algorithm_sse(float **graph) {
  int   j, terminal, arg_min, *path;
  float min, j_dist, *prices, *dist_price;

  path       = init_path();               // init to INFINITIES
  prices     = init_prices();             // init to zeroes

  dist_price = (float *)                  // to hold distance to neighbour
    _mm_malloc(GRAPHSIZE                  // + neighbour price
	       * sizeof(float), 16);      // and be used with sse

  path[0]  = 0;                           // start off with the source node
  terminal = 0;                           // point to current end of path
	
  while (path[terminal] != TARGET) {
    dist_price_sse(graph[path[terminal]], // calculate all dist_price values
	     prices, dist_price);        
    find_min(dist_price, path,            // find the minimum in there
	     &arg_min, &min);
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
