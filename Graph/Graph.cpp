//
// Created by vasilhristov on 23.08.23.
//

#include "Graph.h"

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);

    g.dfs(1);
}