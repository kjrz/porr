#define GRAPHSIZE 20
#define MAX_LENGTH 10
#define MIN_LENGTH 5
#define PERCENT_EDGES 60
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
    {
    srand(time(NULL));

    int graph[GRAPHSIZE][GRAPHSIZE];
    int i,j,pom;

    for (i=0;i<GRAPHSIZE;i++)
    {
        for (j=0;j<=i;j++)
        {
            if (j==i) {graph[i][j]=0;}
            else if((rand()%100)>PERCENT_EDGES)
            {
            graph[i][j]=0;
            graph[j][i]=0;
            }
            else
            {
            pom =(rand()%(MAX_LENGTH-MIN_LENGTH)+MIN_LENGTH);
            graph[i][j]=pom;
            graph[j][i]=pom;
            }
        }
   }

   for(i=0;i<GRAPHSIZE;i++){
   for(j=0;j<GRAPHSIZE;j++){
   printf("%d ",graph[i][j]);
   }
   printf("\n");
   }


       return 0;
   }
