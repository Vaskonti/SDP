#include <iostream>
#include <string>
#include <vector>
#include <queue>

//Main algorithm is not fully completed and not tested

struct Time {
    size_t hours;
    size_t minutes;
    size_t time;

    Time(int time) : time(time) {
        hours = 9 + time / 60;
        minutes = time % 60;
    }

    //O(1)
    void print() {
        std::cout << " " << hours << ":";
        if (minutes < 10)
            std::cout << "0" << minutes;
        else
            std::cout << minutes;
    }
};

class Teacher {
    std::string name;
    Time arriveTime;
    std::vector<bool> rooms;
public:
    Teacher() : name(""), arriveTime(0) {}

    Teacher(std::string name, int time, int numberOfRooms) : arriveTime(time), rooms(numberOfRooms, false) {
        if (name.size() > 50) {
            throw std::invalid_argument("Too long name!");
        }

        for (int i = 0; i < name.size(); ++i) {
            if (!isCorrectChar(name[i]))
                throw std::invalid_argument("Not correct input!");
        }
        this->name = name;
    }

    //O(1)
    std::string getName() const {
        return name;
    }

    //O(1)
    Time getTime() const {
        return arriveTime;
    }

    //O(1)
    void setTime(int time) {
        arriveTime = arriveTime.time + time;
    }

    //O(1)
    void printTime() {
        arriveTime.print();
    }

    //O(1)
    std::vector<bool> getRooms() const {
        return rooms;
    };
private:
    //O(1)
    bool isCorrectChar(char c) const {
        return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
    }
};

void printTeachersOut(std::vector<std::queue<Teacher *>> vector1, int i);

Teacher *readTeacher(int rooms) {
    std::string name;
    int time;

    std::cin >> name >> time;
    return new Teacher(name, time, rooms);
}

//O(n)
int minTimeIndex(std::vector<Teacher *> teachers, int time = 0) {
    int minTime = 240;
    int index = 0;
    for (int i = 0; i < teachers.size(); ++i) {
        int t = teachers[i]->getTime().minutes + (teachers[i]->getTime().hours - 9) * 60 + time;
        if (minTime < t) {
            minTime = t;
            index = i;
        }
    }
    return index;
}

// O(n)
bool isEmpty(std::vector<std::queue<Teacher *>> & roomQueue) {
    for (const auto &item: roomQueue) {
        if (!item.empty())
            return false;
    }
    return true;
}

//O(n)
void printTeachersOut(std::vector<std::queue<Teacher *>> vector1, int time) {
    for (int i = 0; i < vector1.size(); ++i) {
        if (vector1[i].front()->getTime().time <= time) {
            std::cout << vector1[i].front()->getName() << " left room "<<i + 1<<" at";
            vector1[i].front()->printTime();
            std::cout << "\n";
            vector1[i].pop();
        }
    }
}

int main() {

    int m, n;
    std::cin >> m;
    std::cin >> n;

    std::vector<Teacher *> teachers(m);
    std::vector<int> time(n);
    for (int i = 0; i < m; ++i) {
        Teacher *t = readTeacher(n);
        teachers[i] = t;
    }
    for (int i = 0; i < n; ++i) {
        int inputTime;
        std::cin >> inputTime;
        time[i] = inputTime;
    }

    std::vector<std::queue<Teacher *>> roomQueue(n);
    int globalTime = 0;
    Time currentTime(globalTime);

    //Main Algorithm

    // O(n^2)
    do {
        int index = minTimeIndex(teachers, globalTime);
        //O (n)
        for (int i = 0; i < n; ++i) {
            if (isEmpty(roomQueue)) {
                globalTime = teachers[index]->getTime().time;
                roomQueue[i].push(teachers[index]);

                std::cout << teachers[index]->getName() << " enters room "<< i + 1 << " at ";
                teachers[index]->printTime();
                std::cout << "\n";
                teachers[index]->setTime(teachers[index]->getTime().time + time[index]);
            }


            int nextTeacherTime = teachers[i]->getTime().time;

            globalTime = nextTeacherTime;
            printTeachersOut(roomQueue, globalTime);


            if (teachers[index]->getRooms()[i] == false) {
                //O(1)
                teachers[index]->setTime(teachers[index]->getTime().time + time[index]);
                roomQueue[i].push(teachers[index]);
            }
        }
    } while (!std::empty(roomQueue));

    for (int i = 0; i < m; ++i) {
        delete teachers[i];
        teachers[i] = nullptr;
    }


    return 0;
}

// input
/*
 * 4 3
Kali 15
Nora 25
Pepi 45
Trifi 30
5
20
15
 */


