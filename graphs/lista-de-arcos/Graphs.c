#include "Graphs.h"
#include <stdlib.h>
#include <stdio.h>

Arc createArc(Vertex v, Vertex w)
{
  Arc a;
  a.v = v;
  a.w = w;
  return a;
}

Graph initGraph()
{
  Graph g = (Graph)malloc(sizeof(*g));
  g->size = 0;
  g->arcs = NULL;
  return g;
}

void destroyGraph(Graph g)
{
  free(g->arcs);
  g->size = 0;
}

void insertArc(Graph g, Arc a)
{
  g->size++;
  g->arcs = (Arc *)realloc(g->arcs, sizeof(Arc) * g->size);
  g->arcs[g->size - 1] = a;
}

void insertEdge(Graph g, Arc a, Arc b)
{
  insertArc(g, a);
  insertArc(g, b);
}

void removeArc(Graph g, Arc a)
{
  for (int i = 0; i < g->size; i++)
  {
    if (g->arcs[i].v == a.v && g->arcs[i].w == a.w)
    {
      for (int j = i; j < g->size - 1; j++)
      {
        g->arcs[j] = g->arcs[j + 1];
      }
      g->size--;
      g->arcs = (Arc *)realloc(g->arcs, sizeof(Arc) * g->size);
      break;
    }
  }
}

void printGraph(Graph g)
{
  for (int i = 0; i < g->size; i++)
  {
    printf("Arc: %d -> %d\n", g->arcs[i].v, g->arcs[i].w);
  }
}

void removeEdge(Graph g, Arc a, Arc b)
{
  removeArc(g, a);
  removeArc(g, b);
}