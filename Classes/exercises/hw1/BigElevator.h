
#ifndef OOP_2022_TASKS_BIGELEVATOR_H
#define OOP_2022_TASKS_BIGELEVATOR_H
class BigElevator {
    int requestsFrom [20];
    int requestsTo [20];
    int currentRequest = 0;
    int numberRequests = 0;
    int currentFloor;
    int maxFloors;
    int initFloor;

    bool to = false;
public:
    BigElevator();
    BigElevator(int initFloor, int maxFloors);
    void tick();
    void add(int fromFloor, int toFloor);

};
#endif //OOP_2022_TASKS_BIGELEVATOR_H
