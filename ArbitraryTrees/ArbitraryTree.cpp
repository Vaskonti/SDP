//
// Created by vasilhristov on 27.08.23.
//

#include "ArbitraryTree.h"
#include <iostream>
#include <vector>
#include <queue>

int absDistance(int a, int b) {
    if (a >= b)
        return a - b;
    else return b - a;
}

void getAllDistances(ArbitraryNode * root, std::vector<int> & distances) {
    if (!root) {
        return;
    }
    if (root->parent) {
        distances.push_back(absDistance(root->val, root->parent->val));
    }
    if (root->children.empty()) {
        return;
    }

    for (const auto &item: root->children) {
        getAllDistances(item, distances);
    }
}
template <typename T>
bool unique(std::vector<T> & vector) {
    for (int i = 0; i < vector.size() ; ++i) {
        for (int j = i + 1; j < vector.size(); ++j) {
            if (vector[i] == vector[j])
                return false;
        }
    }
    return true;
}

size_t countElementsInATree(ArbitraryNode * root) {
    if (!root)
        return 0;
    if (root->children.empty())
        return 1;

    int count = 1;
    for (const auto &item: root->children) {
        count += countElementsInATree(item);
    }
    return count;
}

std::vector<int> getFirstNOdd(int n) {
    if (n == 0)
        return std::vector<int>();

    std::vector<int> odds;

    for (int i = 1; n > 0; i+=2) {
        odds.push_back(i);
        n--;
    }
    return odds;
}

template <typename T>
std::vector<int>::iterator contains(std::vector<T> & vector, const T & val) {
    for (auto it = vector.begin(); it != vector.end(); ++it) {
        if (*it == val)
            return it;
    }
    return vector.end();
}

bool isNElementOddTree(ArbitraryNode * root, std::vector<int> & odds) {
    if (!root)
        return true;
    if (root->children.empty()) {
        std::vector<int>::iterator it = contains(odds, root->val);
        if (it != odds.end() && !odds.empty()) {
            odds.erase(it);
            return true;
        } else {
            return false;
        }
    }
    bool isOdd = true;
   std::vector<int>::iterator it = contains(odds, root->val);
    if (it != odds.end() && !odds.empty()) {
        odds.erase(it);
        for (const auto &item: root->children) {
            isOdd = isOdd && isNElementOddTree(item, odds);
        }
    } else {
        return false;
    }

    return odds.empty() && isOdd;
}

bool isGracious(ArbitraryNode * root) {
    int n = countElementsInATree(root);
    std::vector<int> odds = getFirstNOdd(n);
    if (!isNElementOddTree(root,odds)) {
        return false;
    }
    std::vector<int> distances;
    getAllDistances(root, distances);

    if (unique(distances)) {
        return true;
    } else {
        return false;
    }
}


void freeTree(ArbitraryNode * root) {
    if (!root)
        return;
    for (const auto &item: root->children) {
        freeTree(item);
    }
    delete root;
}





int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    std::cout << q.back() << std::endl;
    // odd numbers only for values
//    ArbitraryNode * root = new ArbitraryNode(7);
//    ArbitraryNode * child = new ArbitraryNode(3, root);
//    root->children.push_back(child);
//    ArbitraryNode * child1 = new ArbitraryNode(9, child);
//    child->children.push_back(child1);
//    ArbitraryNode * child2 = new ArbitraryNode(5, child1);
//    child1->children.push_back(child2);
//    ArbitraryNode * child3 = new ArbitraryNode(1, child1);
//    child1->children.push_back(child3);
//
//    std::cout << isGracious(root) << std::endl;
//
//    freeTree(root);
    return 0;
}