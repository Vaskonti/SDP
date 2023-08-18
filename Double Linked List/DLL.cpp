//
// Created by vasilhristov on 18.08.23.
//

#include "DLL.h"
#include "queue"
#include "stack"
#include "array"

template <typename Type>
struct Node {
    Type val;
    Node * next;
    Node(Type val, Node * next = nullptr): val(val), next(next) {}
};
template <typename Type>
void insertSorted(Node<Type> *& head, Type element) {
    if (head == nullptr) {
        auto * node = new Node(element);
        head = node;
        return;
    }

    if (head->val > element) {
        auto * node = new Node (element, head);
        head = node;
        return;
    }

    Node<Type> * iterator = head;

    while (iterator->next != nullptr) {
        if (iterator->val < element && element < iterator->next->val) {
            auto * node = new Node(element, iterator->next);
            iterator->next = node;
            return;
        }
        iterator = iterator->next;
    }

    iterator->next = new Node(element);

}

int evaluateRPN(std::queue<char> & queue) {
    std::stack<int> stack;
    while (!queue.empty()) {
        char ch = queue.front();
        queue.pop();
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            switch (ch) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Invalid operator");
            }
        }
    }
    return stack.top();
}

bool isSymmetric(Node<std::queue<char>> *& head) {
    if (head == nullptr) {
        return true;
    }
    if (head->next == nullptr) {
        return true;
    }

    int i = 0;
    std::array<int, 256> arr{};
    Node<std::queue<char>> * iterator = head;

    while (iterator != nullptr) {
        arr[i++] = evaluateRPN(iterator->val);
        iterator = iterator->next;
    }
    for (int j = 0; j < i; ++j) {
        if (arr[j] != arr[i - j - 1]) {
            return false;
        }
    }
    return true;
}

template <typename Type>
bool hasCycle(Node<Type> *& head) {

    if (head == nullptr) {
        return false;
    }
    if (head->next == nullptr) {
        return false;
    }

    Node <Type> * slow = head;
    Node <Type> * fast = head;

    while (fast != nullptr && fast->next != nullptr && slow) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}
template <typename Type>
bool isPalindromeRec(Node<Type> *& head, Node<Type> *& tail) {
    if (tail == nullptr) {
        return true;
    }

    bool isPal = isPalindromeRec(head, tail->next) && head->val == tail->val;
    std::cout << head->val << " " << tail->val << std::endl;
    head = head->next;
    return isPal;
}

template <typename Type>
bool isPalindrome(Node<Type> *& head) {
    if (head == nullptr) {
        return true;
    }
    if (head->next == nullptr) {
        return true;
    }

    Node<Type> * start = head;
    Node<Type> * end = head;

    return isPalindromeRec(start, end);
}

int main() {
    auto * head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(3, new Node<int>(2, new Node<int>(1))))));
    std::cout << isPalindrome(head) << std::endl;

    while (head != nullptr) {
        Node<int> * temp = head;
        head = head->next;
        delete temp;
    }

}

template<class Type>
DoublyLinkedList<Type>::Iterator &DoublyLinkedList<Type>::Iterator::operator++() {
    if (this->current) {
        this->current = this->current->next;
    }
    return *this;
}

template<class Type>
DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator++(int) {
    if (this->current) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }
    return *this;
}

template<class Type>
DoublyLinkedList<Type>::Iterator &DoublyLinkedList<Type>::Iterator::operator--() {
    if (current) {
        this->current = this->current->prev;
    }
    return *this;
}

template<class Type>
DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator--(int) {
    if (current) {
        Iterator temp = *this;
        --(*this);
        return temp;
    }
    return *this;
}

template<class Type>
const Type &DoublyLinkedList<Type>::Iterator::operator*() {
    if (this->current) {
        return this->current->val;
    }
    throw std::runtime_error("Accessing element of type null");
}
