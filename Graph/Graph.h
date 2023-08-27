//
// Created by vasilhristov on 23.08.23.
//

#ifndef CAR_CPP_GRAPH_H
#define CAR_CPP_GRAPH_H
#include <vector>
#include <stack>
#include <iostream>

using Edge = int;
using Vertex = std::vector<Edge>;


class Graph {
    int V;

    std::vector<Vertex> adj;
public:
    explicit Graph(int V): V(V) {
        for (int i = 0; i < V ; ++i) {
            adj.push_back(Vertex());
        }
    }

    void addEdge(int u, int v);
    void dfs(Edge start);
};
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::dfs(Edge start) {
    std::vector<bool> visited(this->adj.size(), false);
    std::stack<Edge> stack;

    stack.push(start);

    while (!stack.empty()) {
        Edge currentEdge = stack.top();
        stack.pop();

        if (!visited[currentEdge]) {
            std::cout << currentEdge << " ";
            visited[currentEdge] = true;
        }

        for ( auto item: this->adj[currentEdge]) {
            if (!visited[item]) {
                stack.push(item);
            }
        }
    }
}


#endif //CAR_CPP_GRAPH_H
