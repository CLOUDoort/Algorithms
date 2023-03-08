#include <stdio.h>
#include "ALGraphDFS.h"
#include "ALGraphDFS.c"
#include "../Chapter 03, 04, 05/DLinkedList.c"
#include "../Chapter 06/ArrayBaseStack.c"

int main(void) {
    ALGraph graph;
    GraphInit(&graph, 7);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    DFShowGraphVertex(&graph, A); printf("\n");
    DFShowGraphVertex(&graph, C); printf("\n");
    DFShowGraphVertex(&graph, E); printf("\n");
    DFShowGraphVertex(&graph, G); printf("\n");

    GraphDestroy(&graph);
    return 0;
}