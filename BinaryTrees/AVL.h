//
// Created by vasilhristov on 20.08.23.
//

#ifndef CAR_CPP_AVL_H
#define CAR_CPP_AVL_H


template <typename T>
struct Node {
    T val;
    Node<T> * left;
    Node<T> * right;
    int height;

    Node(T val, Node<T> * left = nullptr, Node<T> * right = nullptr, int h = 1): val(val), left(left), right(right), height(h){}
};



#endif //CAR_CPP_AVL_H
