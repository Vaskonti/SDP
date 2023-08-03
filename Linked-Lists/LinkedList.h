#include "iostream"
//#includе "vector"

#ifndef CAR_CPP_LINKEDLIST_H
#define CAR_CPP_LINKEDLIST_H


template <typename Type>
class LinkedList {
public:
    Type val;

    LinkedList * next;
    LinkedList(Type val): val(val) {}
    LinkedList(Type val, LinkedList<Type> * next): val(val), next(next){}
};


#endif
