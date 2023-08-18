#include "iostream"

#ifndef CAR_CPP_LINKEDLIST_H
#define CAR_CPP_LINKEDLIST_H

template<typename Type>
struct Node {
    Type val;
    Node *next;

    Node(const Type &val, Node *node = nullptr) : val(val), next(node) {}
};

template<typename Type>
class LinkedList {
private:
    struct Node {
        Type val;
        Node *next;

        Node(const Type &val, Node *node = nullptr) : val(val), next(node) {}
    };

    Node *head;
    Node *tail;
    size_t sizeOfList;

    void free();

    void copy(const LinkedList<Type> &other);

public:
    class Iterator {
    private:
        Node *currentNode;

        explicit Iterator(Node *node) : currentNode(node) {}

    public:
        Iterator &operator++() {
            if (!currentNode) {
                return *this;
            }
            currentNode = currentNode->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Type &operator*() {
            return currentNode->val;
        }

        bool operator==(const Iterator &other) const {
            return this->currentNode == other.currentNode;
        }

        bool operator!=(const Iterator &other) const {
            return !(*this == other);
        }

        friend class LinkedList;
    };

    class ConstIterator {
    private:
        const Node *currentNode;

        ConstIterator(const Node *node) : currentNode(node) {}

    public:
        ConstIterator &operator++() {
            if (!this->currentNode) {
                return *this;
            }
            this->currentNode = this->currentNode->next;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }

        const Type &operator*() {
            return this->currentNode->val;
        }

        bool operator==(const ConstIterator &other) const {
            return this->currentNode == other.currentNode;
        }

        bool operator!=(const ConstIterator &other) const {
            return !(*this == other);
        }

        friend class LinkedList;
    };

    LinkedList();

    LinkedList(const LinkedList<Type> &other);

    LinkedList(LinkedList<Type> &&other);

    LinkedList &operator=(const LinkedList<Type> &other);

    LinkedList &operator=(LinkedList<Type> &&other);

    Iterator begin() {
        return Iterator(this->head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ConstIterator begin() const {
        return ConstIterator(this->head);
    }

    ConstIterator end() const {
        return ConstIterator(nullptr);
    }

    ConstIterator cbegin() const {
        return ConstIterator(this->head);
    }

    ConstIterator cend() const {
        return ConstIterator(nullptr);
    }

    void pushBack(const Type &el);

    void popBack();

    void pushFront(const Type &el);

    void popFront();

    LinkedList<Type> &append(LinkedList<int> &list);

    const Type &front() const;

    const Type &back() const;

    Type &front();

    Type &back();

    bool empty() const;

    size_t size() const;

    void reverse();

    LinkedList<Type> &removeDuplicates();

    void unique();

    void eraseAfter(Node *node);

    bool contains(const Type &el);

    void print() const;

    ~LinkedList();

    template<class Predicate>
    LinkedList<Type> &divide(Predicate pred);

    template<class Predicate>
    LinkedList<Type> &filter(Predicate pred);

    LinkedList<Type> &map(Type (*func)(Type &));
};

template<typename Type>
template<class Predicate>
LinkedList<Type> &LinkedList<Type>::divide(Predicate pred) {
    if (this->empty() || !this->head->next) {
        return *this;
    }

    size_t elemCnt = 1;
    Node *last = this->head;
    while (last->next) {
        elemCnt++;
        last = last->next;
    }

    Node *curr = this->head;
    Node *prev = nullptr;

    for (int i = 0; i < elemCnt ; ++i) {
        if (pred(curr->val)) {
            if (curr == this->head) {
                this->head = this->head->next;
                last->next = curr;
                last = last->next;
                curr = this->head;
            } else if (curr != last) {
                prev->next = curr->next;
                last->next = curr;
                last = last->next;
                curr = prev->next;
            }
            last->next = nullptr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return *this;
}

template<typename Type>
LinkedList<Type> &LinkedList<Type>::map(Type (*func)(Type &)) {
    if (this->empty())
        return *this;
    Node *curr = this->head;
    while (curr) {
        curr->val = func(curr->val);
        curr = curr->next;
    }

    return *this;
}

template<typename Type>
template<class Predicate>
LinkedList<Type> &LinkedList<Type>::filter(Predicate pred) {
    if (this->empty())
        return *this;

    Node *current = this->head;
    Node *prev = nullptr;

    while (current) {
        if (!pred(current->val)) {
            if (prev) {
                prev->next = current->next;
            } else {
                this->head = current->next;
            }
            Node *temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return *this;
}


template<typename Type>
LinkedList<Type> &LinkedList<Type>::append(LinkedList<int> &list) {
    if (this->empty())
        this->head = list.head;
    else {
        Node *curr = this->head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = list.head;
    }
    list.head = nullptr;

    return *this;
}

template<typename Type>
void LinkedList<Type>::unique() {

    Node *curr = this->head;

    while (curr) {
        Node *eraser = curr;
        while (eraser->next) {
            if (curr->val == eraser->next->val) {
                eraseAfter(eraser);
            } else
                eraser = eraser->next;
        }
        curr = curr->next;
    }
}

template<typename Type>
void LinkedList<Type>::eraseAfter(LinkedList::Node *node) {
    if (!node || !node->next) {
        return;
    }
    Node *temp = node->next;
    node->next = temp->next;
    delete temp;
    --this->sizeOfList;

}

template<typename Type>
bool LinkedList<Type>::contains(const Type &el) {
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (*it == el) {
            return true;
        }
    }
    return false;
}

template<typename Type>
LinkedList<Type> &LinkedList<Type>::removeDuplicates() {
    if (this->empty())
        return *this;
    Node *temp = this->head;
    while (temp->next) {
        if (temp->val == temp->next->val) {
            eraseAfter(temp);
        } else {
            temp = temp->next;
        }
    }

    return *this;

}


template<typename Type>
void LinkedList<Type>::print() const {
    for (auto it = this->begin(); it != this->end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << "null" << std::endl;
}

template<typename Type>
void LinkedList<Type>::reverse() {
    if (!this->head || !this->head->next) {
        return;
    }

    Node *prev = nullptr;
    Node *current = this->head;
    Node *next = nullptr;

    // 1 -> 2 -> 3
    // current = 1 (..2->3)
    // next = null
    // prev = null
    while (current) {
        // next = 2 -> 3
        next = current->next;
        // current = 1 -> null
        current->next = prev;
        // prev = 1 -> null
        prev = current;
        // current = 2 -> 3
        current = next;
        // next = 3 -> null
        // current = 2 -> 1 -> null
        // prev = 2 -> 1 -> null
        // current = 3 -> null

        //next = null
        //current = 3 -> 2 -> 1 -> null
        // prev = 3 -> 2 -> 1 -> null
        // current = null

        //  head = 3 -> 2 -> 1 -> null

    }
    this->head = prev;
}


template<typename Type>
LinkedList<Type> &LinkedList<Type>::operator=(LinkedList<Type> &&other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

template<typename Type>
LinkedList<Type> &LinkedList<Type>::operator=(const LinkedList<Type> &other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

template<typename Type>
LinkedList<Type>::LinkedList(LinkedList<Type> &&other) {
    this->head = other.head;
    this->tail = other.tail;
    this->sizeOfList = other.sizeOfList;

    other.head = other.tail = nullptr;
    other.sizeOfList = 0;
}

template<typename Type>
void LinkedList<Type>::free() {
    while (this->head != nullptr) {
        Node *node = this->head;
        this->head = this->head->next;
        delete node;
    }
}

template<typename Type>
LinkedList<Type>::LinkedList(const LinkedList<Type> &other) {
    copy(other);
}

template<typename Type>
void LinkedList<Type>::popBack() {
    if (this->empty()) {
        throw std::invalid_argument("Tried to pop an element from the back of an empty list");
    }
    this->sizeOfList--;
    if (this->head == this->tail) {
        Node *removed = this->head;
        this->head = this->tail = nullptr;
        delete removed;
        return;
    }

    Node *newTail = this->head;

    while (newTail->next != this->tail) {
        newTail = newTail->next;
    }
    delete this->tail;
    this->tail = newTail;
    this->tail->next = nullptr;
}

template<typename Type>
LinkedList<Type>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->sizeOfList = 0;
}

template<typename Type>
void LinkedList<Type>::pushBack(const Type &el) {
    Node *node = new Node(el);
    this->sizeOfList++;
    if (this->empty()) {
        this->head = this->tail = node;
        return;
    }
    this->tail->next = node;
    this->tail = node;
}

template<typename Type>
void LinkedList<Type>::pushFront(const Type &el) {
    Node *node = new Node(el, this->head);
    this->head = node;
    this->sizeOfList++;
}

template<typename Type>
void LinkedList<Type>::popFront() {
    if (this->empty()) {
        throw std::invalid_argument("Tried to pop an element in an empty list!");
    }
    this->sizeOfList--;
    if (this->head == this->tail) {
        delete this->head;
        this->head = this->tail = nullptr;
        return;
    }
    Node *removed = this->head;
    this->head = this->head->next;
    delete removed;
}

template<typename Type>
const Type &LinkedList<Type>::front() const {
    if (this->empty())
        throw std::runtime_error("Empty list!");
    return this->head->val;
}

template<typename Type>
const Type &LinkedList<Type>::back() const {
    if (this->empty())
        throw std::runtime_error("Empty list!");
    return this->tail->val;
}

template<typename Type>
Type &LinkedList<Type>::back() {
    if (this->empty())
        throw std::runtime_error("Empty list!");
    return this->tail->val;
}

template<typename Type>
Type &LinkedList<Type>::front() {
    if (this->empty())
        throw std::runtime_error("Empty list!");
    return this->head->val;
}

template<typename Type>
LinkedList<Type>::~LinkedList() {
    free();
}

template<typename Type>
size_t LinkedList<Type>::size() const {
    return this->sizeOfList;
}

template<typename Type>
bool LinkedList<Type>::empty() const {
    return this->head == nullptr;
}


template<typename Type>
void LinkedList<Type>::copy(const LinkedList<Type> &other) {
    Node *node = other.head;

    while (node) {
        this->pushBack(other.head->val);
        node = node->next;
    }
    this->sizeOfList = other.sizeOfList;
}

#endif
