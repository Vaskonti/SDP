#include <iostream>
#include <stack>
#include "Linked-Lists/LinkedList.h"

template <typename Type>
void placeElementIndex(LinkedList<Type> *& list, int index, Type element) {
    int ind = 0;
    if (index == 0) {
        LinkedList<Type> * node = new LinkedList<Type>(element);
        node->next = list;
        list = node;
        return;
    }
    LinkedList<Type> * temp = list;
    while (list != nullptr && ind < index - 1) {
        list = list->next;
        ind++;
    }
    LinkedList<Type> * newNode = new LinkedList<Type>(element);
    newNode->next = list->next;
    list->next = newNode;
    list = temp;
}
template <typename Type>
void deleteLinkedList(LinkedList<Type> *& list)
{
    while (list != nullptr)
    {
        LinkedList<Type> * node = list;
        list = list->next;
        delete node;
    }
}

template <typename Type>
void displayLinkedList (LinkedList<Type> *& list)
{
    while (list != nullptr)
    {
        if (list->next != nullptr)
        {
            std::cout << list->val << " -> ";
        } else {
            std::cout<< list->val << std::endl;
        }
        list = list->next;
    }
}

template <typename Type>
void removeElementIndex(LinkedList<Type> *& list, int index)
{
    int ind = 0;
    if (index == 0) {
        LinkedList<Type> * node = list;
        list = list->next;
        delete node;
        return;
    } else {
        LinkedList<Type> * temp = list;
        while (list != nullptr && ind < index - 1) {
            list = list->next;
        }
        LinkedList<Type> * node = list->next;
        list->next = list->next->next;
        list = temp;
        delete node;
    }
}
template <typename Type>
void addElementFront(LinkedList<Type> *& list, Type element)
{
    LinkedList<Type> * node = new LinkedList<Type>(element);
    node->next = list;
    list = node;
}

template <typename Type>
void reverse(LinkedList<Type> *& list)
{
    if (list == nullptr)
        return;
    std::stack<Type> stack;
    LinkedList<Type> * temp = list;
    while (temp != nullptr)
    {
        stack.push(temp->val);
        temp = temp->next;
    }
    temp = list;
    while (!stack.empty())
    {
        temp->val = stack.top();
        stack.pop();
        temp = temp->next;
    }
}
template <typename Type>
LinkedList<Type> * getMiddle(LinkedList<Type> *& list)
{
    LinkedList<Type> * slow = list;
    LinkedList<Type> * fast = list;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


int main() {
    LinkedList<int> * list = new LinkedList<int>(1, new LinkedList<int>(2, new LinkedList<int>(4)));


    placeElementIndex(list, 0, 0);
    removeElementIndex(list, 1);
    addElementFront(list,12);
//    addElementFront(list,1);
//    reverse(list);
    LinkedList<int> * temp = list;
    displayLinkedList(list);
    std::cout << getMiddle(temp);
    deleteLinkedList(list);
//    deleteLinkedList(temp);
}
