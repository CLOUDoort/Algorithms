#include <stdio.h>
#include "ALGraph.h"
#include "ALGraph.c"
#include "../Chapter 03, 04, 05/DLinkedList.c"


int main(void) {
    ALGraph graph;
    GraphInit(&graph, 5);

    AddEdge(&graph, A, B); // A와 B를 연결
    AddEdge(&graph, A, D); // A와 D를 연결
    AddEdge(&graph, B, C); // B와 C를 연결
    AddEdge(&graph, C, D); // C와 D를 연결
    AddEdge(&graph, D, E); // D와 E를 연결
    AddEdge(&graph, E, A); // E와 A를 연결

    ShowGraphEdgeInfo(&graph);
    GraphDestroy(&graph);
    return 0;
}