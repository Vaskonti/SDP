#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
#include <set>
#include <queue>

struct Relation {
    int from;
    std::string relType;
    int to;

    Relation(int from, std::string &rel, int to) : from(from), relType(rel), to(to) {}

    Relation() {
        from = 0;
        relType = "";
        to = 0;
    }
};

std::istream &operator>>(std::istream &istream, Relation &rel) {
    if (istream >> rel.from && istream >> rel.relType && istream >> rel.to)
        return istream;
    else {
        rel = Relation();
        return istream;
    }
}

using Edge = std::pair<int, int>;
using Vertex = int;

class Graph {
private:
    std::map<int, std::set<int>> adjacencyList;
public:

    void addEdgeFromRelation(const Relation &rel);

    std::vector<int> getPath(int from, int to) const;

    void displayEdges() const;
    bool bfs(int start);

    //Find the shortest path that passes through all the interesting nodes
    // where the interesting nodes are not the values kept at the adjacency list but the values kept at the vertexIndices
    // If there is no path that passes through all the interesting nodes return false
    bool shortestPath(std::vector<int> &interestingNodes) {
        std::map<int, bool> visited;
        std::vector<int> path;

        std::stack<int> stack;
        stack.push(interestingNodes[0]);
        interestingNodes.erase(interestingNodes.begin());

        while (!stack.empty()) {
            int start = stack.top();
            stack.pop();
            if (!visited[start]) {
                visited[start] = true;
                std::cout << start << " ";
                path.push_back(start);
            }
            for (const auto &item: this->adjacencyList[start]) {
                if (!visited[item]) {
                    stack.push(item);
                }
            }
        }

        return path.empty();
    }


};


void Graph::addEdgeFromRelation(const Relation &rel) {

    if (rel.relType == "--->") {
        this->adjacencyList[rel.from].insert(rel.to);
    } else if (rel.relType == "<---") {
        this->adjacencyList[rel.to].insert(rel.from);
    } else if (rel.relType == "<-->") {
        this->adjacencyList[rel.from].insert(rel.to);
        this->adjacencyList[rel.to].insert(rel.from);
    } else {
        return;
    }
}

void Graph::displayEdges() const {
    for (const auto &key: this->adjacencyList) {
        std::cout << key.first << " : ";
        for (const auto &value: key.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

// Get the path from one vertex to another
std::vector<int> Graph::getPath(int from, int to) const {
    std::map<int, int> parent;
    std::queue<int> q;
    q.push(from);
    parent[from] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == to) {
            std::vector<int> path;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int neighbor : adjacencyList.at(current)) {
            if (parent.find(neighbor) == parent.end()) {
                q.push(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    return std::vector<int>(); // No path found
}


std::vector<int> explode(std::string &line, char delimiter) {
    std::vector<int> result;
    std::string token;
    std::istringstream tokenStream(line);

    while (std::getline(tokenStream, token, delimiter)) {
        result.push_back(std::stoi(token));
    }
    return result;
}

//make a bfs
bool Graph::bfs(int start) {
    std::map<int, bool> visited;
    std::queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        std::cout << current << " ";
        for (const auto &item: this->adjacencyList[current]) {
            if (!visited[item]) {
                queue.push(item);
                visited[item] = true;
            }
        }
    }
}

bool displayShortestPath(Graph & graph, std::vector<int> & interestingNodes) {
    std::vector<int> path = graph.getPath(interestingNodes[0], interestingNodes[1]);
    if (path.empty())
        return false;
    interestingNodes.erase(interestingNodes.begin(), interestingNodes.begin() + 1);
    for (const auto &item: interestingNodes) {
        std::vector<int> path1 = graph.getPath(path.back(), item);
        if (path1.empty())
            return false;
        path1 = std::vector<int>(path1.begin() + 1, path1.end());
        path.insert(path.end(), path1.begin(), path1.end());
    }
    for (const auto &item: path) {
        std::cout << item << " ";
    }
    return true;
}

int main() {
    std::vector<Relation> relations;
    std::string ver;
    std::getline(std::cin, ver);
    std::vector<int> vertices = explode(ver, ' ');
    Graph graph;

    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        Relation v;
        std::istringstream iss(line);

        if (iss >> v) {
            relations.push_back(v);
        }
        if (v.relType.empty())
            break;
    }
    std::vector<int> interestingNodes;
    std::string interesting;
    std::getline(std::cin, interesting);
    interestingNodes = explode(interesting, ' ');


    for (const auto &relation: relations) {
        graph.addEdgeFromRelation(relation);
    }

    if(!displayShortestPath(graph,interestingNodes)) {
        std::cout << "No such path!" << std::endl;
    }
}