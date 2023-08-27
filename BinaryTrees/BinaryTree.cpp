#include "BinaryTree.h"

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

// Check if the tree contains an element
// Not a BST
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

// Get the biggest element in the tree
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

// Get the smallest element in the tree
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

// Get the height/depth of the tree
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

template<typename T>
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

// delete the tree
template<typename Type>
void cleanTree(Node<Type> *&tree) {
    if (tree == nullptr) {
        return;
    }
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
}

// Print the tree in the following order: left, root, right
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

// Check if the element is in the tree
// O(log(n)) time complexity
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

// Check where to insert the element
// If the element is bigger than the root, insert it to the right
// If the element is smaller than the root, insert it to the left
// If the element is equal to the root, do nothing
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
    else if (root->val > element) {
        insertToBST(root->left, element);
    } else {
        return;
    }
}
template <typename T>
bool isValidBSTHelper(Node<T> *& root, T *& prevValue) {
    if (root == nullptr)
        return true;

    if (!isValidBSTHelper(root->left, prevValue))
        return false;

    if (prevValue != nullptr && root->val <= *prevValue)
        return false;

    prevValue = &root->val;

    return isValidBSTHelper(root->right, prevValue);
}

template<typename T>
bool isValidBST(Node<T> *&root) {
    T * prevValue = nullptr;
    return isValidBSTHelper(root, prevValue);
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

template<typename T>
void leftRightRoot(Node<T> *&root) {
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

template<typename T, class Lambda>
void treeMap(Node<T> *&root, Lambda f) {
    if (root == nullptr)
        return;
    f(root->val);
    treeMap(root->left, f);
    treeMap(root->right, f);
}

template<typename T, class Predicate>
void filter(Node<T> *&root, Predicate pred) {
    if (root == nullptr)
        return;
    filter(root->left, pred);
    filter(root->right, pred);

    if (!pred(root->val)) {
        Node<T> *removed = root;
        if (root->left) {
            root = root->left;
        } else {
            root = root->right;
        }
        delete removed;
    }
}

template<typename T>
size_t countLeaves(Node<T> *&root) {
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

template<typename T>
bool alwaysTrue(T arg) {
    return true;
}

template<typename T>
size_t countChildrenInInterval(Node<T> *&root, int x, int y) {
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        return x <= root->val && root->val <= y;
    else
        return (x <= root->val && root->val <= y) + countChildrenInInterval(root->left, x, y) +
               countChildrenInInterval(root->right, x, y);
}

int sumOddNumberSuccessors(Node<int> *&root, int x, int y) {
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right) {
        return 0;
    }
    int children = countChildrenInInterval(root, x, y) - 1;
    children = children < 0 ? 0 : children;
    std::cout << "root: " << root->val << " children: " << children << std::endl;
    if (children % 2 != 0) {
        return root->val + sumOddNumberSuccessors(root->left, x, y) + sumOddNumberSuccessors(root->right, x, y);
    } else {
        return sumOddNumberSuccessors(root->left, x, y) + sumOddNumberSuccessors(root->right, x, y);
    }
}

int getDepth(Node<int> *root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right)
        return 1;

    int left = 1 + getDepth(root->left);
    int right = 1 + getDepth(root->right);

    return std::max(left, right);
}

int isBalanced(Node<int> *root) {
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    int left = getDepth(root->left);
    int right = getDepth(root->right);


    return right - left;
}

//int maxPathSum(Node<int>* root)
//{
//    int maxSum = INT_MIN;
//    DFS(root, maxSum);
//    return maxSum;
//}
//
//int DFS(Node<int>* root, int& maxSum){
//
//    if(!root)
//        return 0;
//    int left =std::max(0, DFS(root->left, maxSum));
//    int right = std::max(0, DFS(root->right, maxSum));
//    maxSum = std::max(maxSum, left + right + root->val);
//    return std::max(left, right) + root->val;
//}

// Time complexity O(n)
size_t toArray(Node<int> * tree, int * output) {
    if (!tree)
        return 0;
    size_t size = 0;
    size += toArray(tree->left, output);
    output[size++] = tree->val;
    size += toArray(tree->right, output + size);
    return size;

}

template <typename T>
void release(Node<T> * root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        delete root;
        return;
    }

    release(root->left);
    release(root->right);
    delete root;
}
//      5
//    3   7
//   2 4 6 8

Node<int> * toTree(const int * array, int size) {
    if (size == 0)
        return nullptr;
    int middle = size / 2;
    Node<int> * root = new Node<int> (array[middle]);
    root->left = toTree(array, middle);
    root->right = toTree(array + middle + 1, size - middle - 1);
    return root;
}

void rightLeftRoot(Node<int> * root) {
    if (!root) {
        return;
    }

    rightLeftRoot(root->right);
    rightLeftRoot(root->left);

    std::cout << root->val << " ";
}
// При нормална имплементация
/*
 * Pos {
 *  T data;
 *  Pos left;
 *  Pos right;
 *  };
 *  Pos * rootPosition() {
 *      return tree;
 *  }
 */
Node<int> * tree = new Node<int> (5, new Node<int> (3, new Node<int> (2), new Node<int> (4)), new Node<int> (7, new Node<int> (12), new Node<int> (8)));
Node<int> * rootPosition() {
    return tree;
}
template <typename T>
Node<int> *  search(T const& x) {
    Node<int> * pos = rootPosition();
    while (pos->val != x && pos) {
        if (pos->val > x) pos = pos->left;
        if (pos->val < x) pos = pos->right;
    }
    return pos;
}

int main() {

    int element = 6;
    Node<int> * node = search(element);
//    int * output = new int[7];
//    std::cout << toArray(root, output) << std::endl;
//    for (int i = 0; i < 7; ++i) {
//      output[i] = i;
//    }
//    Node<int> * root = toTree(output, 7);
    displayTree(node);
//    rightLeftRoot(root);
//    delete [] output;
    release(tree);
}