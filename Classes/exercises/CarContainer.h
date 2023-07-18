#pragma once

// Feel free to change this as much as you want as long as the rest of the code still works

#include <ostream>

#include "Car.h"

const int CAR_ADD_OVERFLOW_ERROR = 1;
const int CAR_ADD_OK = 0;

const int MAX_CAPACITY_ALLOWED = 100;

class CarContainer
{
    int capacity = 0;
    Car cars[MAX_CAPACITY_ALLOWED];
    int currentNumberOfCars = 0;
    void incrementCurrentNumberOfCars();

public:
    void setCapacity(int capacity);
    int addCar(Car car);
    void print(ostream &);
    void removeMultiple(int count);
};