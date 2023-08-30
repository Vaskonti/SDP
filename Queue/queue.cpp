#include <iostream>
#include <queue>

//Check if queue is sorted either descending or ascending
bool isSorted(std::queue<int> & queue) {
    //get the first two elements of the queue
    if (queue.empty())
        return true;
    int first = queue.front();
    queue.pop();
    if (queue.empty())
        return true;
    int second = queue.front();
    queue.pop();
    // check if the queue is descending
    if (first > second) {
        while (!queue.empty()) {
            if (queue.front() > first)
                return false;
            first = queue.front();
            queue.pop();
        }
    } else {
        while (!queue.empty()) {
            if (queue.front() < first)
                return false;
            first = queue.front();
            queue.pop();
        }
    }
    return true;
}

int getSmallestElement(std::queue<int> & queue) {
    if (queue.empty()) {
        throw std::logic_error("cannot find smallest element of an empty queue");
    }
    std::queue<int> helper;

    int first = queue.front();
    queue.pop();

    while(!queue.empty()) {
        if (first > queue.front()) {
            helper.push(first);
            first = queue.front();
        } else {
            helper.push(queue.front());
        }
        queue.pop();
    }
    queue = helper;
    return first;
}

void sortQueue(std::queue<int> & queue) {
    std::queue<int> sorted;

    while (!queue.empty()) {
        sorted.push(getSmallestElement(queue));
    }
    queue = sorted;
}

int main() {
    std::queue<int> queue;
    queue.push(4);
    queue.push(2);
    queue.push(1);
    queue.push(0);
    queue.push(-1);

    sortQueue(queue);
    while(!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    return 0;
}