#ifndef CAR_CPP_RANDOMTREE_H
#define CAR_CPP_RANDOMTREE_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

#define ENABLE_BFS

template<class T>
class RandomTree {
public:
    struct Node {
        T val;
        std::vector<Node *> adjacencyList;
        bool isVisited;

        Node(const T &newValue) : val(newValue), isVisited(false) {}
    };

    RandomTree();

    RandomTree(const RandomTree &) = delete;

    RandomTree &operator=(const RandomTree &) = delete;

    ~RandomTree();

    Node *addNode(const T &newElement, Node *adj = nullptr);

    void removeNode(const T &removedElement);

    void printTree() const;

    Node *find(const T &searchedElement) const;

private:
    Node *bfs(Node *start, const T &searchedElement) const;

    Node *dfs(Node *start, const T &searchedElement) const;

private:
    std::list<Node *> tree;

};

template<class T>
RandomTree<T>::Node *RandomTree<T>::dfs(RandomTree::Node *start, const T &searchedElement) const {
    Node * result = nullptr;
    std::stack<Node *> order;

    order.push(start);

    while (! order.empty()) {
        Node * currentNode = order.top();
        order.pop();

        if (currentNode->val == searchedElement) {
            result = currentNode;
            break;
        }
        std::cout << currentNode->val << " ";
        currentNode->isVisited = true;
        for(Node * adj : currentNode->adjacencyList) {
            if (!adj->isVisited) {
                order.push(adj);
            }
        }
    }
    std::cout << std::endl;
    return result;
}

template<class T>
RandomTree<T>::Node *RandomTree<T>::bfs(RandomTree::Node *start, const T &searchedElement) const {
    Node * result = nullptr;
    std::queue<Node *> wave;
    wave.push(start);

    while (!wave.empty()) {
        Node * currentNode = wave.front();
        wave.pop();
        if (currentNode->val == searchedElement) {
            result = currentNode;
            break;
        }
        std::cout << currentNode->val << " ";
        currentNode->isVisited = tree;
        for (Node * node : currentNode->adjacencyList) {
            if (!node->isVisited) {
                wave.push(node);
            }
        }
    }
    std::cout<<std::endl;
    return result;
}



template<class T>
inline RandomTree<T>::Node *RandomTree<T>::find(const T &searchedElement) const {
    Node *result = nullptr;
    if (!tree.empty()) {
#ifdef ENABLE_BFS
        result = this->bfs(tree.front(), searchedElement);
#else
        result = this->dfs(tree.front(), searchedElement);
#endif // ENABLE_BFS
        for (Node *node: tree) {
            node->isVisited = true;
        }
    }
    return result;
}

template<class T>
void RandomTree<T>::printTree() const {
    for (const Node *node: this->tree) {
        std::cout << node->val << " : adjacency -> ";
        for (const Node *adj: node->adjacencyList) {
            std::cout << adj->val << " ";
        }
        std::cout << std::endl;
    }
}

template<class T>
void RandomTree<T>::removeNode(const T &removedElement) {
    for (Node *node: this->tree) {
        if (node->val == removedElement) {
            tree.remove(node->val);
            delete node;
            break;
        }
    }
}

template<class T>
RandomTree<T>::Node *RandomTree<T>::addNode(const T &newElement, RandomTree::Node *adj) {
    Node *newNode = new Node(newElement);

    if (adj) {
        adj->adjacencyList.push_back(newNode);
        newNode->adjacencyList.push_back(adj);
    }
    tree.push_back(newNode);

    return newNode;
}

template<class T>
RandomTree<T>::RandomTree() {

}

template<class T>
RandomTree<T>::~RandomTree() {
    for (const Node *node: this->tree) {
        delete node;
    }
}


#endif //CAR_CPP_RANDOMTREE_H
