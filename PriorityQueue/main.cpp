
#include <iostream>
#include <queue>
#include <map>

int cabinetNumber = 1;
// Time in minutes (9:00)
int timeNow = 540;
struct Person{
    std::string name;
    int timeOfArrival;
    std::map<int, bool> cabinetsVisited;

    friend std::istream & operator>>(std::istream &istream, Person &person);
};

std::istream &operator>>(std::istream &istream, Person &person) {
    if (istream >> person.name && istream >> person.timeOfArrival)
        return istream;
    else {
        person = Person();
        return istream;
    }
}

struct Cabinet {
    int number;
    int timeForService;
    bool isBusy;
    friend std::istream & operator>>(std::istream &istream, Cabinet &cabinet);
};

std::istream &operator>>(std::istream &istream, Cabinet &cabinet) {
    cabinet.number = cabinetNumber++;
    istream >> cabinet.timeForService;
    return istream;
}

struct ComparePeople {
    bool operator()(const Person & p1, const Person & p2) {
        return p1.timeOfArrival > p2.timeOfArrival;
    }
};
struct IsCabinetFree {
    bool operator() (const Cabinet & c1, const Cabinet & c2) {
        if (!c1.isBusy && !c2.isBusy)
            return c1.number > c2.number;
        else {
            return c1.isBusy && c2.isBusy;
        }
    }
};
std::string getTimeString(int time) {
    int hours = time / 60;
    int minutes = time - hours * 60;

    return std::to_string(hours) + ":" + std::to_string(minutes);
}
void enter(Person & person, Cabinet & cabinet) {
    std::cout << person.name << "влиза в кабинет "<< cabinet.number << " в " << getTimeString(timeNow + person.timeOfArrival) << std::endl;
    cabinet.isBusy = true;
    person.cabinetsVisited[cabinet.number] = true;
}

int main() {
    std::priority_queue<Person, std::vector<Person>, ComparePeople> pq;
    std::priority_queue<Cabinet, std::vector<Cabinet>, IsCabinetFree> cabinets;

    int m,n;
    std::cin>>m>>n;

    for (int i = 0; i < m ; ++i) {
        Person person;
        std::cin>>person;
        pq.push(person);
    }
    for (int i = 0; i < n; ++i) {
        Cabinet cabinet;
        std::cin>>cabinet;
        cabinet.isBusy = false;
        cabinets.push(cabinet);
    }

   while (!pq.empty()) {
       Cabinet cabinet = cabinets.top();
       cabinets.pop();
       Person person = pq.top();
       if (!person.cabinetsVisited[cabinet.number]) {
           enter(person, cabinet);
       }
       pq.pop();
       cabinet.isBusy = false;
       cabinets.push(cabinet);
       timeNow = timeNow + person.timeOfArrival + cabinet.timeForService;
   }



}