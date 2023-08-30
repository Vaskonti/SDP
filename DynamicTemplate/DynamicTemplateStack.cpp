#include <iostream>

template<typename T>
class DynamicTemplateStack {
private:
    struct LinkedListNode {
        T val;
        LinkedListNode *next;

        LinkedListNode(const T &val, LinkedListNode *next = nullptr) : val(val), next(next) {};
    };

    LinkedListNode *head;
    size_t stackSize;

    void copy(const DynamicTemplateStack<T> &other);

    void free();

public:
    DynamicTemplateStack() {
        this->head = nullptr;
        this->stackSize = 0;
    }

    DynamicTemplateStack(const DynamicTemplateStack<T> &other);

    DynamicTemplateStack<T> &operator=(const DynamicTemplateStack<T> &other);

    DynamicTemplateStack(DynamicTemplateStack<T> &&other);

    DynamicTemplateStack<T> &operator=(DynamicTemplateStack<T> &&other);

    void pop();

    void push(const T &element);

    const T &top();

    bool empty() const;

    size_t size() const;

    ~DynamicTemplateStack();
};

template<typename T>
DynamicTemplateStack<T> &DynamicTemplateStack<T>::operator=(DynamicTemplateStack<T> &&other) {
    if (this != &other) {
        this->head = other.head;
        this->stackSize = other.stackSize;

        other.stackSize = 0;
        other.head = nullptr;
    }
    return *this;
}

template<typename T>
DynamicTemplateStack<T>::DynamicTemplateStack(DynamicTemplateStack<T> &&other) {
    this->head = other.head;
    this->stackSize = other.stackSize;

    other.head = nullptr;
    other.stackSize = 0;
}

template<typename T>
DynamicTemplateStack<T> &DynamicTemplateStack<T>::operator=(const DynamicTemplateStack<T> &other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

template<typename T>
void DynamicTemplateStack<T>::copy(const DynamicTemplateStack<T> &other) {
    if (this != &other) {
        while (other.head) {
            this->push(other.head);
            other.head = other.head->next;
        }
    }
}

template<typename T>
DynamicTemplateStack<T>::DynamicTemplateStack(const DynamicTemplateStack<T> &other) {
    copy(other);
}

template<typename T>
const T &DynamicTemplateStack<T>::top() {
    if (this->empty()) {
        throw std::logic_error("Tried to call top() on an empty stack!");
    }

    return this->head->val;
}

template<typename T>
void DynamicTemplateStack<T>::pop() {
    if (this->empty()) {
        throw std::logic_error("Tried to pop() from an empty stack!");
    }
    LinkedListNode *deleteMe = this->head;
    this->head = this->head->next;
    this->stackSize--;
    delete deleteMe;
}

template<typename T>
void DynamicTemplateStack<T>::push(const T &element) {
    if (this->empty()) {
        this->head = new LinkedListNode(element);
        stackSize++;
        return;
    }
    LinkedListNode *addMe = new LinkedListNode(element, this->head);
    this->head = addMe;
    stackSize++;

}

template<typename T>
size_t DynamicTemplateStack<T>::size() const {
    return this->stackSize;
}

template<typename T>
bool DynamicTemplateStack<T>::empty() const {
    return this->head == nullptr;
}

template<typename T>
void DynamicTemplateStack<T>::free() {
    while (!this->empty()) {
        LinkedListNode *deleteMe = this->head;
        this->head = this->head->next;
        delete deleteMe;
    }
}

template<typename T>
DynamicTemplateStack<T>::~DynamicTemplateStack() {
    free();
}
