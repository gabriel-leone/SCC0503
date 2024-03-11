#ifndef GRAPHS_H
#define GRAPHS_H

#define Vertex int
#define Edge Arc

typedef struct
{
  Vertex v;
  Vertex w;
} Arc;

struct ArcList
{
  int size;
  Arc *arcs;
};

typedef struct ArcList *Graph;

Arc createArc(Vertex v, Vertex w);
Graph initGraph();
void destroyGraph(Graph g);
void insertArc(Graph g, Arc a);
void insertEdge(Graph g, Arc a, Arc b);
void removeArc(Graph g, Arc a);
void printGraph(Graph g);
void removeEdge(Graph g, Arc a, Arc b);

#endif