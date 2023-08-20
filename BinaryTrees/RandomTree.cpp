//
// Created by vasilhristov on 20.08.23.
//

#include "RandomTree.h"


int main () {
    RandomTree<int> tree;
    RandomTree<int>::Node * node1 = tree.addNode(5);
    RandomTree<int>::Node * node2 = tree.addNode(3, node1);
    RandomTree<int>::Node * node3 = tree.addNode(7, node1);
    RandomTree<int>::Node * node4 = tree.addNode(2, node2);
    RandomTree<int>::Node * node5 = tree.addNode(4, node2);
    RandomTree<int>::Node * node6 = tree.addNode(6, node3);
    RandomTree<int>::Node * node7 = tree.addNode(8, node3);


    tree.printTree();


}