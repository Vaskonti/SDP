//
// Created by vasilhristov on 19.08.23.
//

#include "CircularList.h"
#include <iostream>




int main() {
    CircularList list;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n ; ++i) {
        list.pushBack(i);
    }
    std::cout << list.getArthurEscape();
}
