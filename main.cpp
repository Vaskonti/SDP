
#include <stack>
#include <iostream>
#include <string>

template<class T>
void sortedInsert(std::stack<T> &stack, const T &elem) {
    if (stack.empty() || elem < stack.top()) {
        stack.push(elem);
    } else {
        T temp = stack.top();
        stack.pop();
        sortedInsert(stack, elem);
        stack.push(temp);
    }
}

template<class T>
void sortStack(std::stack<T> &stack) {
    if (!stack.empty()) {
        T temp = stack.top();
        stack.pop();
        sortStack(stack);
        sortedInsert(stack, temp);
    }
}


void towersOfHanoi(int n, std::stack<int> &A, std::stack<int> &B, std::stack<int> &C) {
    if (n == 1) {
        C.push(A.top());
        A.pop();
        std::cout << "Move disk " << n << " from " << "A" << " to " << "C" << std::endl;
        return;
    }

    towersOfHanoi(n - 1, A, C, B);
    C.push(A.top());
    A.pop();
    std::cout << "Move disk " << n << " from " << "A" << " to " << "C" << std::endl;
    towersOfHanoi(n - 1, B, A, C);
}

std::string &reverseString(std::string &string) {
    std::stack<char> stack;
    for (char i: string) {
        stack.push(i);
    }
    string = "";
    while (!stack.empty()) {
        string += stack.top();
        stack.pop();
    }
    return string;
}

bool parenthesisMatch(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

bool hasValidParenthesis(std::string string) {
    std::stack<char> opening;
    for (const auto &c: string) {
        switch (c) {
            case '[':
            case '(':
            case '{':
                opening.push(c);
                break;
            case ']':
            case ')':
            case '}':
                if (opening.empty())
                    return false;
                if (parenthesisMatch(opening.top(), c)) {
                    opening.pop();
                }
                break;
            default:
                break;
        }
    }
    return opening.empty();

}

int main() {
    std::string string = "(3+4)/{54g(p3[jw][])}";
    std::string string1 = "{(526)}[91]}";
//   std::cout <<( hasValidParenthesis(string) ? "valid" : "invalid") << std::endl;
    std::cout << (hasValidParenthesis(string1) ? "valid" : "invalid") << std::endl;
}