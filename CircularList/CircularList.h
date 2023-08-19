#ifndef CAR_CPP_CIRCULARLIST_H
#define CAR_CPP_CIRCULARLIST_H

#include <iostream>
struct Node {
    int val;
    Node * next;
    Node(int val, Node * next = nullptr):val(val), next(next){}
};
class CircularList {
private:
    Node * head;
    Node * tail;
    size_t size;
    void copy(const CircularList & other);
    void free();
public:
    class Iterator {
    private:
        Node * current;
        Iterator(Node * current): current(current) {}
    public:
        Iterator & operator++();
        Iterator operator++(int);

        const int & operator*();

        bool operator==(const Iterator & other) const{}

        bool operator!=(const Iterator & other) const {}

        friend class CircularList;
    };
public:
    CircularList();
    CircularList(const CircularList & other);
    CircularList & operator=(const CircularList & other);

    CircularList(CircularList && other);
    CircularList & operator=(CircularList && other);

    void pushBack(const int & element);
    void pushFront(const int & element);

    void popFront();

    bool empty() const;
    size_t getSize() const;
    size_t getArthurEscape();

    const int & front() const;
    const int & back() const;

    CircularList::Iterator removeAfter(Iterator &it);

    Iterator begin();
    Iterator end();

    ~CircularList();
};


CircularList::Iterator &CircularList::Iterator::operator++() {
    if (this->current) {
        this->current = this->current->next;
    }
    return *this;
}

CircularList::Iterator CircularList::Iterator::operator++(int) {
    if (this->current) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }
    return *this;
}

const int &CircularList::Iterator::operator*() {
    if (this->current) {
        return this->current->val;
    }
    throw std::logic_error("Invalid element!");
}

CircularList::CircularList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

CircularList::CircularList(const CircularList &other) {
    this->copy(other);
}

void CircularList::free() {
    while (!this->empty()) {
        this->popFront();
    }

}

void CircularList::copy(const CircularList &other) {
    if (this != &other) {
        free();
        this->head = other.head;
        this->tail = other.tail;
        this->size = other.size;
    }
}

CircularList::Iterator CircularList::begin() {
    return Iterator(this->head);
}

CircularList::Iterator CircularList::end() {
    return this->begin();
}

bool CircularList::empty() const {
    return this->size == 0;
}

const int &CircularList::front() const {
    if (this->empty())
        throw std::logic_error("Called front() on empty list!");
    return this->head->val;
}

const int &CircularList::back() const {
    if (this->empty())
        throw std::logic_error("Called back() on empty list!");
    return this->tail->val;
}

CircularList::~CircularList() {
    free();
}

void CircularList::pushBack(const int &element) {
    if (this->empty()) {
        pushFront(element);
        return;
    }
    Node * node = new Node (element, this->head);
    this->tail->next = node;
    this->tail = this->tail->next;
    this->size++;
}

void CircularList::popFront() {
    if (this->empty()) {
        throw std::logic_error("Called popFront() on an empty list!");
    }
    Node * node = this->head;
    this->head = this->head->next;
    delete node;
    this->size--;
    if (size == 0) {
        this->head = this->tail = nullptr;
    } else {
        this->tail->next = this->head;
    }
}
CircularList removeAfter(Node *& node) {

}

size_t CircularList::getSize() const {
    return this->size;
}

void CircularList::pushFront(const int &element) {
    if (this->empty()) {
        Node * node = new Node(element);
        this->head = this->tail = node;
        this->tail->next = node;
        size++;
        return;
    }
    Node * node = new Node(element, this->head);
    this->head = node;
    this->tail->next = this->head;
    size++;

}

CircularList &CircularList::operator=(const CircularList &other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

CircularList::CircularList(CircularList &&other) {
    this->head = other.head;
    this->tail = other.tail;
    this->size = other.size;

    other.head = other.tail = nullptr;
    other.size = 0;
}

CircularList &CircularList::operator=(CircularList &&other) {
    if (this != &other) {
        free();
        this->head = other.head;
        this->tail = other.tail;
        this->size = other.size;

        other.head = other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

size_t CircularList::getArthurEscape() {
    auto it = this->begin();
    for ( ; this->size != 1 ; ) {
        it = removeAfter(it);
    }
    return *it;
}

CircularList::Iterator CircularList::removeAfter(Iterator &iterator) {
    if (this->empty())
        throw std::logic_error("Cannot remove an element from an empty list!");

    if (this->size == 1) {
        delete iterator.current;
        return nullptr;
    }
    Node * removed = iterator.current->next;

    if (removed == this->tail) {
        tail = iterator.current;
    }

    if (removed == this->head) {
        head = this->head->next;
    }

    iterator.current->next = removed->next;

    delete removed;
    size--;
    if (size == 1) {
        return head ? head : tail;
    }
    return iterator.current->next;

}


#endif //CAR_CPP_CIRCULARLIST_H
