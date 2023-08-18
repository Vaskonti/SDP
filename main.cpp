#include <iostream>
#include <stack>
#include "list"
#include "Linked-Lists/LinkedList.cpp"
//#include "Linked-Lists/LinkedList.h"

template<typename Type>
typename std::list<Type>::iterator getMiddle(std::list<Type> *list) {
    auto fast = list->begin();
    auto slow = list->begin();

    while (fast != list->end() && std::next(fast) != list->end()) {
        fast++;
        fast++;
        slow++;
    }
    return slow;
}

template<typename Type>
void shuffle(typename std::list<Type>::iterator it) {
    auto *middle = getMiddle(it);
}

void removeAtIndex(Node<int> *&head, int index) {
    if (head == nullptr) {
        return;
    }

    if (index == 0) {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<int> *current = head;
    Node<int> *prev = nullptr;

    int currentIndex = 0;
    while (current != nullptr && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }
    if (current == nullptr) {
        return;
    }
    prev->next = current->next;
    delete current;
}


void removeIdx(Node<int> *&head) {
    if (head == nullptr) {
        return;
    }
    Node<int> *temp = head;
    int lastIdx = 0;
    while (temp != nullptr) {
        lastIdx++;
        temp = temp->next;
    }
    std::cout << lastIdx << std::endl;
    temp = head;
    Node<int> * prev = nullptr;
    int index = 0;
    while (temp != nullptr) {
        if (temp->val == lastIdx - 1 - index) {
            if (prev == nullptr) {
                Node<int> * del = head;
                head = head->next;
                delete del;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
        index++;
    }
}

template <typename Type>
void insertAtEnd(Node<Type> *&head, int element) {
    Node<Type> *newNode = new Node(element);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<Type> *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

template <typename Type>
void printList(Node<Type> *&head) {
    Node<Type> *node = head;
    while (node != nullptr) {
        if (node->next != nullptr) {
            std::cout << node->val << " -> ";
        } else {
            std::cout << node->val << std::endl;
        }
        node = node->next;
    }
}
template <typename Type>
void deleteLinkedList(Node<Type> *&list) {
    while (list != nullptr) {
        Node<Type> *node = list;
        list = list->next;
        delete node;
    }
}
template <typename Type>
void popFront(Node<Type> *&node) {
    if (node == nullptr) {
        return;
    }
    Node<Type> *node1 = node;
    node1->next = node->next;
    node = node->next;
    delete node1;
}
template <typename Type>
void pushFront(Node<Type> *&node, int el) {
    if (node == nullptr) {
        node = new Node(el);
    } else {
        Node<Type> *node1 = new Node(el, node);
        node = node1;
    }
}
template <typename Type>
void printListRec(Node<Type> *& node) {
    if (node == nullptr) {
        return;
    }
    std::cout<< node->val << " ";
    printListRec(node->next);
}
template <typename Type>
void mirror(Node<Type> *& head) {
    if (head == nullptr) {
        return;
    }
    if(head->next == nullptr) {
        insertAtEnd(head, head->val);
        return;
    }
    Node<Type> * rev = getReversed(head);
    Node<Type> * current = head;
    while(current != nullptr) {
        current = current->next;
    }
    while (rev != nullptr) {
        Node<Type> * node = rev;
        insertAtEnd(head, rev->val);
        rev = rev->next;
        delete node;
    }
}

template <typename Type>
void append(Node<Type> *& head, Node<Type> & other) {
    Node<Type> * temp = head;

    while(temp) {
        temp = temp->next;
    }
    Node<Type> * other1 = other;
    while (other1) {
        Node<Type> * node = other1;
        temp = other1;
    }
}
template <typename Type>
Node<Type> * getReversed(Node<Type> *& head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }
    std::stack<Type> stack;
    Node<Type> * current = head;
    while(current != nullptr) {
        stack.push(current->val);
        current = current->next;
    }
    auto * reversed = new Node<Type>(stack.top());
    current = reversed;
    stack.pop();
    size_t size = stack.size();
    for (int i = 0; i < size ; ++i) {
        auto * node = new Node<Type>(stack.top());
        reversed->next = node;
        reversed = reversed->next;
        stack.pop();
    }
    return current;
}

template <typename Type>
void fillgaps(Node<Type> *& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        return;
    }

    Node<Type> * current = head;

    while (current->next != nullptr) {
        Type a = current->val;
        Type b = current->next->val;
        if (b - a > 1) {
            for (int i = a + 1; i < b; ++i) {
                auto * node = new Node<Type>(i, current->next);
                current->next = node;
                current = current->next;
            }
        } else {
            current = current->next;
        }
    }
}

template <typename Type>
void removedups(Node<Type> *& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        return;
    }

    Node<Type> * current = head;
    while(current != nullptr) {
        Node<Type> * runner = current;
        while (runner->next != nullptr) {
            if (runner->next->val == current->val) {
                Node<Type> * duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
int main() {
    Node<int> *list = nullptr;
    insertAtEnd(list, 1);
    insertAtEnd(list, 1);
    insertAtEnd(list, 2);
    insertAtEnd(list, 2);
    insertAtEnd(list, 2);
    insertAtEnd(list, 1);
    insertAtEnd(list, 5);
    removedups(list);
    printList(list);
    deleteLinkedList(list);

}
