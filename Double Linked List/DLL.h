//
// Created by vasilhristov on 18.08.23.
//

#ifndef CAR_CPP_DLL_H
#define CAR_CPP_DLL_H
#include <iostream>

template <class Type>
class DoublyLinkedList {
private:
    struct Node {
        Type val;
        Node * next;
        Node * prev;
        Node(Type val, Node * next = nullptr, Node * prev = nullptr):val(val), next(next), prev(prev){}
    };
    Node * head;
    Node * tail;

    void copy(const DoublyLinkedList<Type> & other);
    void free();
    class Iterator {
    private:
        Node * current;
        Iterator(Node * current): current(current) {}
    public:
        Iterator & operator++();
        Iterator operator++(int);

        Iterator & operator--();
        Iterator operator--(int);

        const Type & operator*();

        bool operator==(const Iterator & other) const{}

        bool operator!=(const Iterator & other) const {}

        friend class DoublyLinkedList;
    };

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<Type> & other);
    DoublyLinkedList & operator=(const DoublyLinkedList<Type> & other);

    DoublyLinkedList(DoublyLinkedList<Type> && other);
    DoublyLinkedList & operator=(DoublyLinkedList<Type> && other);

    void pushBack(const Type & element);
    void popBack();

    void pushFront(const Type & element);
    void popFront();

    bool empty() const;

    const Type & front() const;
    const Type & back() const;

    Iterator begin();
    Iterator end();

    void insert(Iterator at, const Type & element);

    ~DoublyLinkedList();
};

template<class Type>
void DoublyLinkedList<Type>::insert(DoublyLinkedList::Iterator at, const Type &element) {
    if (at.current == nullptr) {
        tail->next = new Node(element, nullptr, this->tail);
        tail = tail->next;
        return;
    }
    Node * toInsert = new Node(element, at.current, at.current->prev);

    if (at.current->prev != nullptr) {
        at.current->prev->next = toInsert;
    }
    at.current->prev = toInsert;

    if (at.current == this->head)
        head = toInsert;

    if (at.current == this->tail)
        tail = toInsert;

    at.current = toInsert;
}

template<class Type>
const Type &DoublyLinkedList<Type>::back() const {
    if (this->empty())
        throw std::runtime_error("Tried to call back() on an empty list!");

    return this->tail->val;
}

template<class Type>
const Type &DoublyLinkedList<Type>::front() const {
    if (this->empty())
       throw std::runtime_error("Tried to call front() on an empty list!");

    return this->head->val;
}

template<class Type>
bool DoublyLinkedList<Type>::empty() const {
    return this->head == nullptr;
}

template<class Type>
void DoublyLinkedList<Type>::popFront() {
    if (this->empty())
        throw std::runtime_error("Tried to popFront on empty list!");

    Node * node = this->head;
    this->head = this->head->next;
    delete node;

}

template<class Type>
void DoublyLinkedList<Type>::pushFront(const Type &element) {
    if (this->empty()) {
        Node * node = new Node(element, nullptr, nullptr);
        this->head = this->tail = node;
        return;
    }
    Node * node = new Node(element, this->head, nullptr);
    this->head = node;
}

template<class Type>
void DoublyLinkedList<Type>::pushBack(const Type &element) {
    if (this->empty()) {
        Node * node = new Node(element, nullptr, nullptr);
        this->head = this->tail = node;
        return;
    }

    Node * node = new Node(element, nullptr, this->tail->prev);
    this->tail = node;
}

template<class Type>
DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::end() {
    return Iterator(nullptr);
}

template<class Type>
void DoublyLinkedList<Type>::popBack() {
    if (this->empty())
        throw std::runtime_error("Tried to popBack() on empty list!");

    Node * remove = this->tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete remove;
}

template<class Type>
DoublyLinkedList<Type> &DoublyLinkedList<Type>::operator=(DoublyLinkedList<Type> &&other) {
    if (this != &other) {
        free();

        this->head = other.head;
        this->tail = other.tail;

        other.head = other.tail = nullptr;
    }
    return *this;
}

template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList(DoublyLinkedList<Type> &&other) {
    this->head = other.head;
    this->tail = other.tail;

    other.head = other.tail = nullptr;
}

template<class Type>
DoublyLinkedList<Type> &DoublyLinkedList<Type>::operator=(const DoublyLinkedList<Type> &other) {
    copy(other);
    return *this;
}

template<class Type>
void DoublyLinkedList<Type>::copy(const DoublyLinkedList<Type> &other) {
    if (this != &other) {
        free(this);
        this->head = other.head;
        this->tail = other.tail;
    }
}

template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type> &other) {
    copy(other);
}

template<class Type>
DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::begin() {
    return Iterator(this->head);
}

template<class Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {
    this->free();
}

template<class Type>
void DoublyLinkedList<Type>::free() {
    while (this->head) {
        Node * removed = this->head;
        this->head = this->head->next;
        delete removed;
    }
}

template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList() {
    this->head = this->tail = nullptr;
}

#endif //CAR_CPP_DLL_H
