#include <iostream>
#include "../BinaryTrees/BinaryTree.h"
#include <vector>

//1. По подаден елемент elem връща итератор (указател) към
//първия намерен елемент от масива равен на elem или
//итератор към края на масива (nullptr) ако не съдържа elem.
template<typename T>
T *contains(std::vector<T> &vector,const T &elem) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector[i] == elem)
            return &vector[i];
    }
    return nullptr;
}

//2. Връща копие на масива, но с елементите му в обратен ред.
//Вход: [ 1, 5, 6, 2, 0 ]
//Изход: [ 0, 2, 6, 5, 1 ] / нов масив
template<typename T>
std::vector<T> &reverse(std::vector<T> &vector) {
    std::vector<T> reversed = {};
    for (const auto &item: vector) {
        reversed.push_back(item);
    }
    for (size_t i = 0; i < vector.size(); i++) {
        vector[i] = reversed[vector.size() - i - 1];
    }
    return vector;
}

//3. По подаден масив проверява дали всички елементи от втория
//масив се съдържат в първия.
//Вход: ( [ 1, 5, 6, 2, 0 ], [ 0, 5, 1 ] )
//Изход: true
template<typename T>
bool containsIn(std::vector<T> &vec1, std::vector<T> &vec2) {
    int cnt = 0;
    for (int i = 0; i < vec2.size(); ++i) {
        for (int j = 0; j < vec1.size(); ++j) {
            if (vec1[j] == vec2[i])
                cnt++;
        }
    }
    return cnt == vec2.size();
}

//4. По подадена функция прилага функцията върху всеки елемент
//на масива.
//Пример: void square( int& num ) { num *= num; }
//Вход: ( [ 1, 5, 6, 2, 0 ], square )
//Изход: [ 1, 25, 36, 4, 0 ]

template<typename T, class Func>
std::vector<T> &map(std::vector<T> &vector, Func func) {
    for (auto &item: vector) {
        item = func(item);
    }
    return vector;
}

//5. По подаден предикат (булева функция) връща нов масив
//съдържащ тези елементите на оригиналния масив, които
//удовлетворяват предиката.
//Пример: bool isEven( int num ) { return num % 2 == 0; }
//Вход: ( [ 1, 5, 6, 2, 0 ], isEven )
//Изход: [ 6, 2, 0 ] / нов масив

template<typename T, class Predicate>
std::vector<T> &filter(std::vector<T> &vector, Predicate pred) {
    std::vector<T> newVector;
    for (const auto &item: vector) {
        if (pred(item)) {
            newVector.push_back(item);
        }
    }
    vector.clear();
    for (const auto &item: newVector) {
        vector.push_back(item);
    }
    return vector;
}

//6. По подадено число 𝑘 ∈ [ 1; 𝑛 ] връща итератор (указател) към
//k-тия по големина елемент от масива.
//Сложността по време да бъде 𝑂( 𝑛 * 𝑘 ).
template<typename T>
std::vector<T>::iterator getKthBigElement(std::vector<T> &vector, int k) {
    if (k > vector.size() || k < 1) {
        throw std::invalid_argument("K out of boundaries!");
    }
    std::vector<T> copy = vector;

    for (int i = 0; i < copy.size(); ++i) {
        for (int j = i + 1; j < copy.size(); ++j) {
            if (copy[i] < copy[j]) {
                std::swap(copy[i], copy[j]);
            }
        }
    }
    return (std::find(vector.begin(), vector.end(), copy[k - 1]));
}


//7. Връща нов масив съдържащ само неповтарящите се елементи
//на оригиналния.
//Сложността по време да бъде 𝑂( 𝑛 * 𝑙𝑜𝑔(𝑛) ).
//use contains()
template<typename T>
std::vector<T> &unique(std::vector<T> &vector) {
   std::vector<T> newVector;
    for (const auto &item: vector) {
        if (!contains(newVector, item)) {
            newVector.push_back(item);
        }
    }
    vector.clear();
    for (const auto &item: newVector) {
        vector.push_back(item);
    }
    return vector;
}

template <typename T>
int search(std::vector<T> & vector, T target) {
    int left = 0;
    int right = vector.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (vector[mid] == target) {
            return mid;
        } else if (target > vector[mid]) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return -1;
}

template <typename T>
std::vector<T> inorderTraversal(Node<T> * root) {

    if (!root)
        return {};

    std::vector<T> left = inorderTraversal(root->left);
    left.push_back(root->val);
    std::vector<T> right = inorderTraversal(root->right);

    left.insert(left.end(), right.begin(), right.end());
    return left;
}


int main() {
    Node<int> * root = new Node<int>(1, new Node<int>(2,
                                                      new Node<int>(4), new Node<int>(5)),
                                            new Node<int>(3));
    std::vector<int> result = inorderTraversal(root);
    for (const auto &item: result) {
        std::cout << item << " ";
    }
}
