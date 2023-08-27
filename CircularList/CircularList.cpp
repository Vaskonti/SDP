//
// Created by vasilhristov on 19.08.23.
//

#include "CircularList.h"
#include <iostream>

template <class T>
struct cir_list_elem {
    T val;
    cir_list_elem<T> *next;
    cir_list_elem<T> *prev;

    cir_list_elem(const T & val, cir_list_elem<T> * next = nullptr, cir_list_elem<T> * prev = nullptr): val(val), next(next), prev(prev) {}
};

// O(n)
template <class T>
bool isValid(cir_list_elem<T> *& head) {
    if (!head)
        return true;
    cir_list_elem<T> * first = head;
    if (first->val == first->prev->val + first->next->val)
        return false;
    head = head->next;
    while (head != first) {
        if (head->val == head->next->val + head->prev->val) {
            return false;
        }
        head = head->next;
    }
    return true;
}

// О(1)
template <class T>
void remove(cir_list_elem<T> *& head) {
    if (head == nullptr) {
        return;
    }
    if (head == head->next) {
        cir_list_elem<T> * node = head;
        head = head->next = head->prev = nullptr;
        delete node;
        return;
    }
    cir_list_elem<T> * remove = head;
    cir_list_elem<T> * prev = remove->prev;
    cir_list_elem<T> * next = remove->next;
    // 1 -> 2 -> 3
    prev->next = next;
    next->prev = prev;
    head = head->next;
    delete remove;
}

// О(n^2)
template <class T>
void removeElEqualToAdjacentSum(cir_list_elem<T> *& head) {
    while (!isValid(head)) {
        remove(head);
    }
}

// O(n)
template <typename T>
void push_back(cir_list_elem<T> *& head, const T & elem) {
    if (head == nullptr) {
        head = new cir_list_elem<T>(elem);
        head->prev = head->next = head;
        return;
    }

    if (head->next == head && head->prev == head) {
        cir_list_elem<T> * node = new cir_list_elem<T>(elem, head, head);
        head->next = node;
        return;
    }

    cir_list_elem<T> * first = head;
    first = first->next;
    while (first->next != head) {
        first = first->next;
    }
    cir_list_elem<T> * node = new cir_list_elem<T>(elem, head, first);
    first->next = node;
    head->prev = node;
}

template <typename T>
void printList(cir_list_elem<T> * list) {
    if (!list)
        return;

    cir_list_elem<T> * first = list;
    std::cout << list->val << " ";
    list = list->next;

    while (first != list) {
        std::cout << list->val << " ";
        list = list->next;
    }
}


int main() {
   cir_list_elem<int> * list = nullptr;
//   list->next = new cir_list_elem<int>(7);
//   list->next->next = new cir_list_elem<int>(4);
//   list->next->next->next = new cir_list_elem<int>(2);
//   list->next->next->next->next = new cir_list_elem<int>(5);
//   list->next->next->next->next->next = new cir_list_elem<int>(3);
//   list->next->next->next->next->next->next = list;
//   list->prev = list->next->next->next->next->next;
    push_back(list,5);
    push_back(list,2);
    push_back(list,4);
    push_back(list,7);
    push_back(list,1);
    push_back(list,3);
    removeElEqualToAdjacentSum(list);
    printList(list);
}
