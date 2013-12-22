porr: porr.c graph.c dijkstra.c auction.c auction-sse.c
	gcc -msse -o porr.o porr.c graph.c dijkstra.c auction.c auction-sse.c -I.
