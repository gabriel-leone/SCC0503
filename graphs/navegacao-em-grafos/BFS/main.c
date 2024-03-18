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

void LiberaGrafo(Grafo *grafo) {
  for (int i = 0; i < grafo->vertices; i++) {
    free(grafo->matriz[i]);
  }
  free(grafo->matriz);
  free(grafo);
}

// Nessa função, iremos implementar a busca por BFS (breadth-first-search), ou seja, você acessa o elemento, então acessa seus filhos e depois os filhos dos filhos e assim por diante
void BFS(Grafo *grafo, int vertice, int *visitados) {
  int *fila = (int *)malloc(grafo->vertices * sizeof(int));
  int inicio = 0, fim = 0;

  fila[fim++] = vertice;
  visitados[vertice] = 1;

  while (inicio != fim) {
    int verticeAtual = fila[inicio++];
    printf("visited %d\n", verticeAtual);
    for (int i = 0; i < grafo->vertices; i++) {
      if (grafo->matriz[verticeAtual][i] == 1 && !visitados[i]) {
        fila[fim++] = i;
        visitados[i] = 1;
      }
    }
  }

  free(fila);
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
      BFS(grafo, i, visitados);
    }
  }

  LiberaGrafo(grafo);
  return 0;
}