#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int vertice;
  struct no *proximo;
} No;

typedef struct grafo
{
  int vertices;
  int arestas;
  No **lista;
} Grafo;

Grafo *criaGrafo(int vertices)
{
  Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
  grafo->vertices = vertices;
  grafo->lista = (No **)malloc(vertices * sizeof(No *));
  grafo->arestas = 0;
  for (int i = 0; i < vertices; i++)
  {
    grafo->lista[i] = NULL;
  }
  return grafo;
}

No *criaNo(int vertice)
{
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->vertice = vertice;
  novoNo->proximo = NULL;
  return novoNo;
}

void adicionaAresta1(Grafo *grafo, int origem, int destino)
{
  No *novoNo = criaNo(destino);
  novoNo->proximo = grafo->lista[origem];
  grafo->lista[origem] = novoNo;

  novoNo = criaNo(origem);
  novoNo->proximo = grafo->lista[destino];
  grafo->lista[destino] = novoNo;
  grafo->arestas++;
}

void adicionaAresta(Grafo *grafo, int origem, int destino)
{
  No *novoNo = criaNo(destino);
  if (grafo->lista[origem] == NULL)
  {
    grafo->lista[origem] = novoNo;
  }
  else
  {
    No *temp = grafo->lista[origem];
    while (temp->proximo != NULL)
    {
      temp = temp->proximo;
    }
    temp->proximo = novoNo;
  }

  novoNo = criaNo(origem);
  if (grafo->lista[destino] == NULL)
  {
    grafo->lista[destino] = novoNo;
  }
  else
  {
    No *temp = grafo->lista[destino];
    while (temp->proximo != NULL)
    {
      temp = temp->proximo;
    }
    temp->proximo = novoNo;
  }

  grafo->arestas++;
}

void imprimeGrafo(Grafo *grafo)
{
  printf("Total of vertices: %d, total of arcs: %d\n", grafo->vertices, grafo->arestas);
  for (int i = 0; i < grafo->vertices; i++)
  {
    No *no = grafo->lista[i];
    printf("Vertex %d, arcs: ", i);
    while (no)
    {
      printf("%d", no->vertice);
      no = no->proximo;
      if (no)
      {
        printf(", ");
      }
    }
    printf("\n");
  }
}

void destroiGrafo(Grafo *grafo)
{
  for (int i = 0; i < grafo->vertices; i++)
  {
    No *no = grafo->lista[i];
    while (no)
    {
      No *temp = no;
      no = no->proximo;
      free(temp);
    }
  }
  free(grafo->lista);
  free(grafo);
}

int main(int argc, char *argv[])
{
  int vertices;
  scanf("%d", &vertices);
  Grafo *grafo = criaGrafo(vertices);

  int origem, destino;
  while (scanf("%d %d", &origem, &destino) != EOF)
  {
    adicionaAresta(grafo, origem, destino);
  }

  imprimeGrafo(grafo);

  return 0;
}
