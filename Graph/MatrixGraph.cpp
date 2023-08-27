#include "MatrixGraph.h"

#include <iostream>
#include <stack>
#include <queue>
#include <map>

void validPath(std::vector<std::vector<int>> &graph, int start, int end) {
    std::stack<int> stack;
    std::vector<int> visited(graph.size(), false);

    stack.push(start);

    while(!stack.empty()) {
        int currentNode = stack.top();
        stack.pop();

        if (!visited[currentNode]) {
            std::cout << currentNode << " ";
            visited[currentNode] = true;
        }
        for (auto item: graph[currentNode]) {
            if (!visited[item]) {
                stack.push(item);
            }
        }
    }


}
int main() {
    std::vector<std::vector<int>> graph;
    graph.push_back({0,1});
    graph.push_back({1,2});
    graph.push_back({2,3});
    graph.push_back({3,4});
    graph.push_back({4,1});

 validPath(graph, 1, 6);
}