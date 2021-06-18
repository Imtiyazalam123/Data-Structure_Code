#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Graph {

          int vertice;
          int edge;
          int **Adj;
};

struct Graph* createGraph(int V, int E) {
          int i,j,k, v = 0, edge = -1;
          struct Graph *G;
          G = (struct Graph*) malloc(sizeof(struct Graph));
          G->vertice = V;
          G->edge = E;
          G->Adj = (int**) malloc((G->vertice) * sizeof(int*));
          // I wrote this code myself
       /*   for(i = 0; i < V; i ++)
                    *(G->Adj + i) = (int*) malloc((G->vertice)* sizeof(int));

          for(j = 0; j < V; j++ ) {
                    for(k = 0; k < V; k++) {
                              printf("is there direct edeges b/w v%d to v%d if yes then press 1 otherwise 0 \n", v + 1, k+1);
                              scanf("%d", &edge);
                              if(edge == 1)
                                        G->Adj[j][k] = edge;
                              else
                                        G->Adj[j][k] = edge;
                              edge = -1;
                    }
                    v += 1;
          }
          return G; */

          // this code written by sir
         for(i = 0; i < V; i ++) {
                    *(G->Adj + i) = (int*) malloc(sizeof(int) * G->vertice);
                    for(j = 0; j < V; j++)
                              G->Adj[i][j] = 0;
          }
          for(k = 1; k <= E; k++) {
                    printf(" Enter Vertex no connected by this edge  \n");
                    scanf("%d%d", &i, &j);
                    G->Adj[i-1][j-1] = 1;
                    G->Adj[j-1][i-1] = 1;
          }
          return G;
}

void printMatrix(struct Graph *G) {
          int i, j;
          printf("\n Your Ajdacents Matrix are : \n");
          for(i = 0; i < G->vertice; i++) {
                    for(j = 0; j < G->vertice; j++)
                              printf("%d ",G->Adj[i][j]);
                    printf("\n'");
          }
}
int main()  {
          struct Graph *g = NULL;
          g = createGraph(5, 6);
          printMatrix(g);
          return 0;
}
