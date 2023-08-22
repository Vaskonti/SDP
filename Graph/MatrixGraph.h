//
// Created by vasilhristov on 21.08.23.
//

#ifndef CAR_CPP_MATRIXGRAPH_H
#define CAR_CPP_MATRIXGRAPH_H

#include <vector>
#include <iostream>
#include <cstddef>

class MatrixGraph {
public:
    using vertex_t = unsigned int;
    using weight_t = unsigned int;
private:
    std::vector<std::vector<weight_t>> data;
public:
    explicit MatrixGraph(size_t);

    void addVertex();
    void removeVertex(vertex_t);
    bool validVertex(vertex_t) const;

    void addEdge(vertex_t, vertex_t, weight_t);
    void removeEdge(vertex_t, vertex_t);

    weight_t getWeight(vertex_t from, vertex_t to);

    bool hasEdge(vertex_t from, vertex_t to) const;

    size_t vertexCount() const;

    bool adjacent(vertex_t from, vertex_t to) const;

    std::vector<vertex_t> getSuccessors(vertex_t) const;
    std::vector<vertex_t> getPredeccessors(vertex_t) const;

    std::vector<vertex_t> adjacent(vertex_t) const;


};

MatrixGraph::MatrixGraph(size_t n) {
    this->data = std::vector<std::vector<weight_t>>(n, std::vector<weight_t>(n, 0));
}

void MatrixGraph::addVertex() {
    for (auto &v: data) {
        v.push_back(0);
    }
    data.push_back(std::vector<weight_t>());
}

void MatrixGraph::removeVertex(MatrixGraph::vertex_t vertex) {
    if (!validVertex(vertex))
        throw std::logic_error("Invalid vertex");

    data.erase(data.begin() + vertex);

    for (auto & v: data) {
        v.erase(v.begin() + vertex);
    }
}

bool MatrixGraph::validVertex(MatrixGraph::vertex_t vertex) const {
    return vertex < this->data.size();
}


#endif //CAR_CPP_MATRIXGRAPH_H
