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
int main() {
    std::queue<int> queue;
    queue.push(4);
    queue.push(2);
    queue.push(1);
    queue.push(0);
    queue.push(-1);

    std::cout << isSorted(queue) << std::endl;
    return 0;
}