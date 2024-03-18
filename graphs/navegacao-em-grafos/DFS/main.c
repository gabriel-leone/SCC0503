#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
  int vertices;
  int arestas;
  int **matriz;
} Grafo;

Grafo* CriaGrafo(int vertices) {
  Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
  grafo->vertices = vertices;
  grafo->arestas = 0;

  // Aloca memória para cada linha da matriz
  grafo->matriz = (int**)malloc(vertices * sizeof(int*));
  for (int i = 0; i < vertices; i++) {
    // Aloca memória para cada coluna da linha i
    grafo->matriz[i] = (int*)malloc(vertices * sizeof(int));
  }

  return grafo;
}

void AdicionaAresta(Grafo *grafo, int origem, int destino) {
  // Verifique se os vértices são válidos
  if (origem < 0 || origem >= grafo->vertices || destino < 0 || destino >= grafo->vertices) {
    return;
  }

  grafo->matriz[origem][destino] = 1;
  grafo->matriz[destino][origem] = 1;
  grafo->arestas++;
}

void DFS(Grafo *grafo, int vertice, int *visitados) {
  visitados[vertice] = 1;
  printf("visited %d\n", vertice);
  for (int i = 0; i < grafo->vertices; i++) {
    if (i != vertice && grafo->matriz[vertice][i] == 1 && !visitados[i]) {
      DFS(grafo, i, visitados);
    }
  }
}

void LiberaGrafo(Grafo *grafo) {
  for (int i = 0; i < grafo->vertices; i++) {
    free(grafo->matriz[i]);
  }
  free(grafo->matriz);
  free(grafo);
}


// Nesse programa, iremos implementar um gráfo com representação em matriz de adjacências e iremos realizar a navegação nele por DPS (depht-first-search)
int main(int argc, char *argv[]) {
  int vertices;
  scanf("%d", &vertices);
  Grafo *grafo = CriaGrafo(vertices);

  int origem, destino;
  while (scanf("%d %d", &origem, &destino) != EOF)
  {
    AdicionaAresta(grafo, origem, destino);
  }

  int *visitados = (int *)calloc(vertices, sizeof(int));
  for (int i = 0; i < vertices; i++) {
    visitados[i] = 0;
  }

  for (int i = 0; i < vertices; i++) {
    if (!visitados[i]) {
      DFS(grafo, i, visitados);
    }
  }

  LiberaGrafo(grafo);
  return 0;
}