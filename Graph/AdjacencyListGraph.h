//
// Created by vasilhristov on 21.08.23.
//

#ifndef CAR_CPP_ADJACENCYLISTGRAPH_H
#define CAR_CPP_ADJACENCYLISTGRAPH_H

#include <vector>
#include <list>
#include <algorithm>


class AdjacencyListGraph {
public:
    using vertex_t = unsigned int;
    using weight_t = unsigned int;
private:
    struct Edge {
        vertex_t to;
        weight_t weight;
    };

    std::vector<std::list<Edge>> data;

public:
    explicit AdjacencyListGraph(size_t n);

    void addVertex();
    void removeVertex(vertex_t);
    bool validVertex(vertex_t) const;

    void addEdge(vertex_t, vertex_t, weight_t);
    void removeEdge(vertex_t, vertex_t);

    weight_t getWeight(vertex_t, vertex_t);
    bool hasEdge(vertex_t, vertex_t) const;

    size_t vertexCount() const;

    std::vector<Edge> adjacent(vertex_t) const;
};

AdjacencyListGraph::AdjacencyListGraph(size_t n) {
    this->data = std::vector<std::list<Edge>>(n, std::list<Edge>());
}

void AdjacencyListGraph::addVertex() {
    this->data.push_back(std::list<Edge>());
}

void
AdjacencyListGraph::addEdge(AdjacencyListGraph::vertex_t from, AdjacencyListGraph::vertex_t to, AdjacencyListGraph::weight_t weight) {
    if (!validVertex(from) || !validVertex(to)) {
        throw std::logic_error("Invalid vertex");
    }
    data[from].push_back({to, weight});
    data[to].push_back({from, weight});
}

void AdjacencyListGraph::removeEdge(AdjacencyListGraph::vertex_t from, AdjacencyListGraph::vertex_t to) {
    if (!validVertex(from) || !validVertex(to)) {
        throw std::logic_error("Invalid vertex!");
    }
    this->data[from].remove_if([&to](Edge e) {return e.to == to;});
    this->data[to].remove_if([&from](Edge e) {return e.to == from;});
}

AdjacencyListGraph::weight_t AdjacencyListGraph::getWeight(AdjacencyListGraph::vertex_t from, AdjacencyListGraph::vertex_t to) {
   if (!validVertex(from) || !validVertex(to)) {
       throw std::logic_error("Invalid vertex");
   }
    for (const auto &edge: this->data[from]) {
            if (edge.to == to)
                return edge.weight;
    }
    return 0;
}

bool AdjacencyListGraph::hasEdge(AdjacencyListGraph::vertex_t from, AdjacencyListGraph::vertex_t to) const {
    if (!validVertex(from) || !validVertex(to)) {
        throw std::logic_error("Invalid vertex!");
    }

    for (const auto &edge: data[from]) {
        if (edge.to == to)
            return true;
    }
    return false;
}

std::vector<AdjacencyListGraph::Edge> AdjacencyListGraph::adjacent(AdjacencyListGraph::vertex_t from) const {
    return {data[from].begin(), data[from].end()};
}

size_t AdjacencyListGraph::vertexCount() const {
    return this->data.size();
}

void AdjacencyListGraph::removeVertex(AdjacencyListGraph::vertex_t vertex) {
    if (!validVertex(vertex)) {
        throw std::logic_error("Invalid vertex");
    }

    data.erase(vertex + data.begin());
    for (auto &list: data) {
        list.remove_if([&] (Edge e) {return e.to == vertex;});

        for (auto &edge: list) {
            if (edge.to == vertex)
                edge.to--;
        }
    }
}

bool AdjacencyListGraph::validVertex(AdjacencyListGraph::vertex_t vertex) const {
    return vertex < this->data.size();
}


#endif //CAR_CPP_ADJACENCYLISTGRAPH_H
