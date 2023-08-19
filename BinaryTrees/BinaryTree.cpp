#include "BinaryTree.h"

#include <iostream>
#include <string>

template<typename T>
bool contains(Node<T> *&tree, T element) {
    if (tree == nullptr)
        return false;
    if (tree->val == element)
        return true;
    if (!tree->right && !tree->left)
        return false;
    return contains(tree->left, element) || contains(tree->right, element);
}

template<typename T>
T biggest(Node<T> *&tree, T biggestEl) {
    if (tree == nullptr)
        return biggestEl;
    if (biggestEl < tree->val)
        biggestEl = tree->val;
    if (!tree->left && !tree->right)
        return biggestEl;
    int biggestLeft = biggest(tree->left, biggestEl);
    int biggestRight = biggest(tree->right, biggestEl);
    return biggestLeft > biggestRight ? biggestLeft : biggestRight;
}

template<typename T>
T smallest(Node<T> *&tree, T smallestEl) {
    if (tree == nullptr)
        return smallestEl;
    if (smallestEl > tree->val)
        smallestEl = tree->val;
    if (!tree->left && !tree->right)
        return smallestEl;

    int smallestRight = smallest(tree->right, smallestEl);
    int smallestLeft = smallest(tree->left, smallestEl);

    return smallestRight > smallestLeft ? smallestLeft : smallestRight;
}

template<typename T>
size_t height(Node<T> *&tree) {
    if (tree == nullptr)
        return 0;
    if (!tree->left && !tree->right)
        return 1;
    size_t leftHeight = height(tree->left);
    size_t rightHeight = height(tree->right);

    return 1 + (leftHeight >= rightHeight ? leftHeight : rightHeight);
}

template <typename T>
void displayTree(Node<T> *root, int level = 0, char branch = 'R') {
    if (root == nullptr) {
        return;
    }

    // Print right branch
    displayTree(root->right, level + 1, '/');

    // Print current node with indentation
    for (int i = 0; i < level; ++i) {
        std::cout << "    ";
    }
    std::cout << branch << "-- " << root->val << std::endl;

    // Print left branch
    displayTree(root->left, level + 1, '\\');
}

template<typename Type>
void cleanTree(Node<Type> *&tree) {
    if (tree == nullptr) {
        return;
    }
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
}

void leftRootRight(Node<int> *&tree) {
    if (tree == nullptr) {
        return;
    }

//    std::cout << tree->val << " ";
    leftRootRight(tree->left);
//    std::cout << std::endl;

    std::cout << tree->val << std::endl;

    leftRootRight(tree->right);

}

bool containsBST(Node<int> *&root, int element) {
    if (root == nullptr)
        return false;
    if (root->val == element)
        return true;
    if (root->val < element)
        return containsBST(root->right, element);
    if (root->val > element)
        return containsBST(root->left, element);
}

void insertToBST(Node<int> *&root, int element) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        Node<int> *node = new Node<int>(element);
        if (root->val < element)
            root->right = node;
        else
            root->left = node;
        return;
    }
    if (root->val < element) {
        insertToBST(root->right, element);
    }
    if (root->val > element) {
        insertToBST(root->left, element);
    }
}

template <typename T>
bool isValidBST(Node<T> *& root) {
    if (root == nullptr)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && root->left->val > root->val)
        return false;
    if (root->right && root->right->val < root->val)
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

bool canReadWord(Node<char> *&tree, std::string &word) {
    if (word.empty())
        return true;

    if (tree == nullptr)
        return false;

    if (tree->val == word[0]) {
        word = word.substr(1);
        return canReadWord(tree, word);
    }
    if (tree->val > word[0])
        return canReadWord(tree->left, word);
    else
        return canReadWord(tree->right, word);
}

template<typename T>
void rootLeftRight(Node<T> *&root) {
    if (root == nullptr)
        return;

    std::cout << root->val << " ";
    rootLeftRight(root->left);
    rootLeftRight(root->right);
}

template <typename T>
void leftRightRoot(Node<T> *& root) {
    if (root == nullptr)
        return;

    leftRightRoot(root->left);
    leftRightRoot(root->right);
    std::cout << root->val << " ";
}

void solution(Node<char> *&root, std::string &word) {

    if (word.empty())
        throw std::logic_error("Word is empty");
    std::string word1 = word.substr(word.size() / 2);
    word = word.substr(0, word.size() / 2);
    if (word.size() >= 2 && word1.size() >= 2)
        std::cout << (canReadWord(root->right, word) && canReadWord(root->left, word1)) << std::endl;
    else
        throw std::logic_error("Word is too short");

}
template <typename T, class Lambda>
void treeMap(Node<T> *&root, Lambda f) {
    if (root == nullptr)
        return;
    f(root->val);
    treeMap(root->left, f);
    treeMap(root->right, f);
}

template<typename T, class Predicate>
void filter(Node<T> *& root, Predicate pred) {
    if (root == nullptr)
        return;
    filter(root->left, pred);
    filter(root->right, pred);

    if (!pred(root->val)) {
        Node<T> * removed = root;
        if (root->left) {
            root = root->left;
        } else {
            root = root->right;
        }
        delete removed;
    }
}
template <typename T>
size_t countLeaves(Node<T> *& root) {
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
template <typename T>
bool alwaysTrue(T arg) {
    return true;
}
template <typename T>
size_t countChildrenInInterval(Node<T> *& root, int x, int y) {
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        return x <= root->val && root->val <= y;
    else
        return ( x <= root->val && root->val <= y) + countChildrenInInterval(root->left, x, y) + countChildrenInInterval(root->right, x, y);
}
int sumOddNumberSuccessors(Node<int> *& root, int x, int y) {
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right) {
        return 0;
    }
    int children = countChildrenInInterval(root, x, y) - 1;
    children = children < 0 ? 0 : children;
    std::cout << "root: " << root->val << " children: " << children << std::endl;
    if ( children % 2 != 0) {
        return root->val + sumOddNumberSuccessors(root->left, x, y) + sumOddNumberSuccessors(root->right, x, y);
    } else {
        return sumOddNumberSuccessors(root->left, x, y) + sumOddNumberSuccessors(root->right, x ,y);
    }
}

int main() {
   Node <int> *root = new Node<int>(5, new Node<int>(3, new Node<int>(2), new Node<int>(4)), new Node<int>(7, new Node<int>(6), new Node<int>(8)));


//    filter(root, [] (int i) { return i % 2 == 0; });
    displayTree(root);

    std::cout << sumOddNumberSuccessors(root, 1, 5) << std::endl;
    cleanTree(root);

}