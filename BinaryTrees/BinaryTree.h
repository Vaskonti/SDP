//
// Created by vasilhristov on 19.08.23.
//

#ifndef CAR_CPP_BINARYTREE_H
#define CAR_CPP_BINARYTREE_H

template <typename T>
struct Node {
    T val;
    Node * left;
    Node * right;
    Node(T data, Node<T> * l = nullptr, Node<T> * r = nullptr): val(data), left(l), right(r) {}
};



#endif //CAR_CPP_BINARYTREE_H
