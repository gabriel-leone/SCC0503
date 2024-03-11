#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"

int main() {
  Arc a1 = createArc(1, 2);
  Arc a2 = createArc(2, 1);
  Arc b1 = createArc(3, 4);
  Arc b2 = createArc(4, 3);
  Graph g = initGraph();
  insertEdge(g, a1, a2);
  insertEdge(g, b1, b2);
  printGraph(g);
  printf("\n\n\n\n\n");
  removeArc(g, a1);
  printGraph(g);
  removeEdge(g, b1, b2);
  printf("\n\n\n\n\n");
  printGraph(g);
  return 0;
}