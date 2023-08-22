#include "AdjacencyListGraph.h"
#include <iostream>

int main() {
    AdjacencyListGraph graph(5);
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(0, 3, 2);
    graph.addEdge(0, 4, 1);
    graph.addEdge(1, 2, 2);

    std::cout << graph.getWeight(0, 1) << std::endl;
}