//#include "LinkedList.h"
#include <iostream>

struct Node {
    int val;
    Node * next;
    explicit Node(int val, Node * next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

void reverse(Node *& head) {
    if (!head || !head->next) {
        return;
    }

    Node * prev = nullptr;
    Node * current = head;
    Node * next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


bool contains(Node *& head, const int & el) {
    Node * iterator = head;
    while (iterator) {
        if (iterator->val == el) {
            return true;
        }
        iterator = iterator->next;
    }
    return false;
}

void removeElement(Node *& node, const int & el) {

    if (!node) {
        return;
    }
    if (node->val == el) {
        Node * remove = node;
        node = node->next;
        delete remove;
        return;
    }
    Node * iterator = node;

    while (iterator->next) {
        if (iterator->next->val == el) {
            Node * remove = iterator->next;
            iterator->next = remove->next;
            delete remove;
        } else {
            iterator = iterator->next;
        }
    }
}

void removeDuplicates(Node *& head) {
    Node * iterator = head;

    while(iterator) {
        if (contains(iterator->next, iterator->val)) {
            removeElement(iterator->next, iterator->val);
        }
        iterator = iterator->next;
    }
}

int main() {
    Node * head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(5, new Node(4, new Node(3, new Node(2, new Node(1))))))))));
    reverse(head);
    removeDuplicates(head);
    while (head) {
        Node * temp = head;
        std::cout << head->val << " ";
        head = head->next;
        delete temp;
    }
    std::cout << std::endl;
    return 0;
//    LinkedList list;
//    list.pushBack(1);
//    list.pushBack(1);
//    list.pushBack(2);
//    list.pushBack(2);
//    list.pushBack(3);
//    list.pushBack(3);
//    list.pushBack(1);
//
//    LinkedList list1;
//    list1.pushBack(4);
//    list1.pushBack(5);
//    list1.pushBack(6);

//    list.print();
//    list.removeDuplicates();
//    list.print();
//    list.unique();
//    list.print();
//    list.append(list1);
//     isEven = [](int num) { return num % 2 == 0; };
//    bool (*isEven)(int) = [](int num) { return num % 2 == 0; };
//    list.filter(isEven).print();
//    list.map([](int & num) { return num * num; }).filter([] (int num) {return num > 10; }).print();
//    list.divide([](int num) { return num % 2 == 0; }).print();
}