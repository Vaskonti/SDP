//#include "LinkedList.h"
#include <iostream>

struct Node {
    int val;
    Node *next;

    explicit Node(int val, Node *next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

// Reverse a linked list
void reverse(Node *&head) {
    if (!head || !head->next) {
        return;
    }

    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Returne a reversed linked list
Node *reverseList(Node *head) {
    if (!head || !head->next) {
        return head;
    }

    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Check if a linked list contains a given element
bool contains(Node *&head, const int &el) {
    Node *iterator = head;
    while (iterator) {
        if (iterator->val == el) {
            return true;
        }
        iterator = iterator->next;
    }
    return false;
}

// Remove an element from a linked list
void removeElement(Node *&node, const int &el) {

    if (!node) {
        return;
    }
    if (node->val == el) {
        Node *remove = node;
        node = node->next;
        delete remove;
        return;
    }
    Node *iterator = node;

    while (iterator->next) {
        if (iterator->next->val == el) {
            Node *remove = iterator->next;
            iterator->next = remove->next;
            delete remove;
        } else {
            iterator = iterator->next;
        }
    }
}

// remove duplicates from a sorted list
void removeDuplicates(Node *&head) {
    Node *iterator = head;

    while (iterator) {
        if (contains(iterator->next, iterator->val)) {
            removeElement(iterator->next, iterator->val);
        }
        iterator = iterator->next;
    }
}

// Detect a cycle in a linked list
bool hasCycle(Node *head) {
    Node *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        head = head->next;

        if (head == fast)
            return true;
    }
    return false;
}

// Detect the node where the cycle begins
// Input: [3,2,0,-4 -> 2] pos = 1
// Output: 2
Node *detectCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    if (!fast || !fast->next)
        return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

}
// Merge two sorted lists into one sorted list
// Input : list1:[1,1,2,4,5] list2:[0,1,2,5,7]
// Output: [0,1,1,1,2,2,4,5,5,7]

Node *mergeLists(Node *list1, Node *list2) {
    Node *head = new Node(INT16_MIN);
    Node *current = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    current->next = (list1 ? list1 : list2);
    return head->next;
}

//Get the middle of a linked list
//Input: [1,2,3,4,5]
//Output: 3 -> 4 -> 5
Node *getMid(Node *head) {
    if (!head || !head->next) {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Sort a linked list in O(nlogn) time using constant space complexity
// using merge sort algorithm
Node *sortList(Node *head) {
    if (!head || !head->next) {
        return head;
    }
    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr;

    left = sortList(left);
    right = sortList(right);

    return mergeLists(left, right);
}

Node *removeNthFromEnd(Node *head, int n) {
    Node *reversed = reverseList(head);
    Node *copy = reversed;
    int count = 0;

    if (n == 1) {
        Node *toRemove = reversed;
        delete toRemove;

        return reverseList(copy);
    } else {
        while (reversed && count < n - 2) {
            reversed = reversed->next;
            count++;
        }
        Node *toRemove = reversed->next;
        reversed->next = toRemove->next;
        delete toRemove;

    }

    return reverseList(copy);

}

Node *mergeTwoLists(Node *list1, Node *list2) {
    Node *head;
    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    Node *current = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1) {
        current = list1;
    } else {
        current = list2;
    }

    return head;
}

int main() {
    Node *node1 = new Node(1, new Node(2, new Node(2, new Node(8))));
    Node *node2 = new Node(0, new Node(1, new Node(3, new Node(9))));
    Node *node3 = mergeTwoLists(node1, node2);

    while (node3) {
        std::cout << node3->val << " ";
        node3 = node3->next;
    }


}