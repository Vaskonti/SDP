//
// Created by vasilhristov on 20.08.23.
//

#include "AVL.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

template <typename T>
int getHeight(Node<T> *& root) {
    if (root == nullptr)
        return 0;
    return root->height;
}
template <typename T>
int getBF(Node<T> *& root) {
    if (root == nullptr)
        return 0;
    return getHeight(root->right) - getHeight(root->left);
}

template <typename T>
void updateHeight(Node<T> *& root) {
    if (root == nullptr)
        return;
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
}
template<typename T>
void balanceLeft(Node<T> *& root) {
    if (root == nullptr)
        return;

    int rootBalance = getBF(root);
    int leftBalance = getBF(root->left);

    if (rootBalance == -2) {
        if (leftBalance == 1) {
            rotateLeft(root->left);
            updateHeight(root->left->left);
            updateHeight(root->left);
        }
        rotateRight(root);
        updateHeight(root->right);
        updateHeight(root);
    }
}

template <typename T>
void balanceRight(Node<T> *& root) {
    if (root == nullptr)
        return;

    int rootBalance = getBF(root);
    int balanceRight = getBF(root->right);

    if (rootBalance == -2) {
        if (balanceRight == 1) {
            rotateRight(root->right);
            updateHeight(root->right->right);
            updateHeight(root->right);
        }
        rotateLeft(root);
        updateHeight(root->left);
        updateHeight(root);
    }
}
template <typename T>
void rotateRight(Node<T> *& root) {
    if (root->left == nullptr)
        return;
    Node<T> * originalLeft = root->left;
    root->left = originalLeft->right;
    originalLeft->right = root;
    root = originalLeft;
}

template <typename T>
void rotateLeft(Node<T> *& root) {
    if (root->right == nullptr)
        return;
    Node<T> * originalRight = root->right;
    root->right = originalRight->left;
    originalRight->left = root;
    root = originalRight;
}

template <typename T>
void addElement(Node<T> *& root, const T & element) {
    if (root == nullptr) {
        root = new Node<T>(element, nullptr, nullptr, 1);
        return;
    } else if(root->val < element) {
        addElement(root->right, element);

        balanceRight(root);

        updateHeight(root);
    } else if (root->val > element) {
        addElement(root->left, element);

        balanceLeft(root);

        updateHeight(root);
    }
}

Node<int> * toTree(const int * arr, int size) {

}

int main() {
    int * arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    Node<int> * root = toTree(arr,10);

}