#include "BigElevator.h"
#include <iostream>

BigElevator::BigElevator() {
    this->initFloor = 0;
    this->maxFloors = 10;
    this->currentRequest = 0;
    this->to = false;
    this->currentFloor = this->initFloor;
}
BigElevator::BigElevator(int initFloor, int maxFloors) {
    this->initFloor = initFloor;
    this->maxFloors  = maxFloors;
    this->to = false;
    this->currentFloor = this->initFloor;
    this->currentRequest = 0;
}

void BigElevator::add(int fromFloor, int toFloor) {
    this->requestsFrom[this->numberRequests] = fromFloor;
    this->requestsTo[this->numberRequests++] = toFloor;
}
void BigElevator::tick() {
    if(this->currentFloor == this->requestsTo[currentRequest] && this->to)
    {
        this->currentRequest++;
        this->to = false;
    }
    if(this->currentFloor != this->requestsFrom[this->currentRequest] && !this->to)
    {
        if(this->currentFloor < this->requestsFrom[this->currentRequest])
        {
            this->currentFloor++;
        }
        else if(this->currentFloor > this->requestsFrom[this->currentRequest])
        {
            this->currentFloor--;
        }
        else {
            this->to = true;
        }
    }
    else
    {
        this->to = true;
        if(this->currentFloor < this->requestsTo[this->currentRequest])
        {
            this->currentFloor++;
        }
        else if(this->currentFloor > this->requestsTo[this->currentRequest])
        {
            this->currentFloor--;
        }
        else {
            this->to = false;
        }
    }
    std::cout<<this->currentFloor<<std::endl;
}

int main()
{
    BigElevator elevator(1, 20);//20 етажа максимум, началнапозиция - ет. 1
    elevator.add(3,5);
    elevator.add(8,1);
    elevator.add(6,2);
    elevator.add(7,1);
    elevator.add(1,4);
    elevator.tick();//Output: fl. 2
    elevator.tick();//Output: fl. 3
    elevator.tick();//Output: fl. 4
    elevator.tick();//Output: fl. 5
    elevator.tick();//Output: fl. 6
    elevator.tick();//Output: fl. 7
    elevator.tick();//Output: fl. 8
    elevator.tick();//Output: fl. 7
    elevator.tick();//Output: fl. 6
    elevator.tick();//Output: fl. 5
    elevator.tick();//Output: fl. 4
    elevator.tick();//Output: fl. 3
    elevator.tick();//Output: fl. 2
    elevator.tick();//Output: fl. 1
}