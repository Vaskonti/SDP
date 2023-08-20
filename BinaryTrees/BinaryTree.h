#ifndef CAR_CPP_BINARYTREE_H
#define CAR_CPP_BINARYTREE_H

#include <optional>
#include <iostream>

template<typename T>
struct Node {
    T val;
    Node *left;
    Node *right;

    Node(T data, Node<T> *l = nullptr, Node<T> *r = nullptr) : val(data), left(l), right(r) {}
};

template<typename T>
class BST {
private:
    Node<T> root;
public:
    using opt_const_ref = std::optional<std::reference_wrapper<const T>>;
public:
    BST();

    BST(const BST &other);

    BST(BST &&other) noexcept;

    ~BST();

    BST &operator=(const BST &other);

    BST &operator=(BST &&other);

public:
    void insert(const T &element);

    bool tryInsert(const T &element);

    opt_const_ref find(const T &element);

    bool erase(const T &element);

    void print(std::ostream &out = std::cout) const;

    T min() const;

    T max() const;

private:
    void deleteBranch(Node<T> *&node) noexcept;

    void copyBranch(Node<T> *&node, const Node<T> *otherNode);

    void insertRec(Node<T> *&node, const T &element);

    bool tryInsertRec(Node<T> *&node, const T &element);

    opt_const_ref findRec(const Node<T> *node, const T &element) const;

    bool eraseRec(Node<T> *&node, const T &element);

    void printRec(const Node<T> *&node, std::ostream &out = std::cout) const;

    Node<T>* &minRec(Node<T> *&node);

    const Node<T> *maxRec(const Node<T> *node) const;
};

template<typename T>
T BST<T>::max() const {
    return this->maxRec(this->root)->val;
}

template<typename T>
const Node<T> *BST<T>::maxRec(const Node<T> *node) const {
    if (node == nullptr)
        throw std::logic_error("BST max() of an empty BST!");

    if (node->right)
        return this->maxRec(node->right);
    return node;
}

template<typename T>
Node<T> *&BST<T>::minRec(Node<T> *&node) {
    if (node->left)
        return this->minRec(node->left);

    return node;
}

template<typename T>
T BST<T>::min() const {
    if (this->root == nullptr)
        throw std::logic_error("BST min() on an empty BST!");

    Node<T> * curr = this->root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr->val;
}

template<typename T>
void BST<T>::printRec(const Node<T> *&node, std::ostream &out) const {
    if (!node)
        return;

    this->printRec(node->left);
    out << node->val << " ";
    this->printRec(node->right);
}

template<typename T>
void BST<T>::print(std::ostream &out) const {
    this->printRec(this->root, out);
}

template<typename T>
bool BST<T>::eraseRec(Node<T> *&node, const T &element) {
    if (!node)
        return false;

    if (node->val == element) {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        } else if ((node->left && !node->right) || (!node->left && node->right)) {
            Node<T> * onlyChild = node->left ? node->left : node->right;
            Node<T> * toRemove = node;
            node = onlyChild;
            delete toRemove;
        } else {
            Node<T> *& min = this->minRec(node->right);
            std::swap(node->val, min->val);
            this->eraseRec(min, element);
        }
        return true;
    } else if (element < node->val) {
        return this->eraseRec(node->left, element);
    } else {
        return this->eraseRec(node->right, element);
    }
}

template<typename T>
bool BST<T>::erase(const T &element) {
    this->eraseRec(this->root, element);
}

template<typename T>
BST<T>::opt_const_ref BST<T>::findRec(const Node<T> *node, const T &element) const {
    if (!node)
        return std::nullopt;

    if (element == node->val)
        return node->val;

    if (element < node->val)
        return findRec(node->right, element);
    if (element > node->val)
        return findRec(node->left, element);
}

template<typename T>
BST<T>::opt_const_ref BST<T>::find(const T &element) {
    return this->findRec(this->root, element);
}

template<typename T>
bool BST<T>::tryInsertRec(Node<T> *&node, const T &element) {
    if (node == nullptr) {
        node = new Node<T> (element);
        return true;
    }

    if (element < node->val) {
        return this->tryInsertRec(node->left, element);
    }

    if (element > node->val) {
        return this->tryInsertRec(node->right, element);
    }

    return false;
}

template<typename T>
bool BST<T>::tryInsert(const T &element) {
   return this->tryInsertRec(this->root, element);
}

template<typename T>
void BST<T>::insertRec(Node<T> *&node, const T &element) {
    if (!this->tryInsertRec(node, element)) {
        throw std::logic_error("BST cannot store duplicate elements!");
    }
}

template<typename T>
void BST<T>::insert(const T &element) {
    this->insertRec(this->root, element);
}

template<typename T>
BST<T> &BST<T>::operator=(BST &&other) {
    if (this != &other) {
        this->deleteBranch(this->root);
        this->root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template<typename T>
BST<T> &BST<T>::operator=(const BST &other) {
    std::swap(this->root, other.root);
    return *this;
}

template<typename T>
BST<T>::~BST() {
    this->deleteBranch(this->root);
}

template<typename T>
BST<T>::BST(BST &&other) noexcept {
    this->root = other.root;
    other.root = nullptr;
}

template<typename T>
void BST<T>::deleteBranch(Node<T> *&node) noexcept {
    if (!node)
        return;
    deleteBranch(node->left);
    deleteBranch(node->right);

    delete node;
    node = nullptr;
}

template<typename T>
void BST<T>::copyBranch(Node<T> *&node, const Node<T> *otherNode) {
    if (!otherNode)
        return;
    node = new Node<T>(otherNode->val);
    this->copyBranch(node->left, otherNode->left);
    this->copyBranch(node->right, otherNode->right);
}

template<typename T>
BST<T>::BST(const BST &other) {
    copyBranch(this->root, other.root);
}

template<typename T>
BST<T>::BST() {
    this->root = nullptr;
}


#endif //CAR_CPP_BINARYTREE_H
