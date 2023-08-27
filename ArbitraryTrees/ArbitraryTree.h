//
// Created by vasilhristov on 27.08.23.
//

#ifndef CAR_CPP_ARBITRARYTREE_H
#define CAR_CPP_ARBITRARYTREE_H
#include <iostream>
#include <vector>

struct ArbitraryNode {
    int val;
    ArbitraryNode * parent;
    std::vector<ArbitraryNode*> children;
};


#endif //CAR_CPP_ARBITRARYTREE_H
