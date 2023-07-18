#ifndef OOP_2022_TASKS_INTERSECTION_H
#define OOP_2022_TASKS_INTERSECTION_H

#include "Car.h"
#include <string>

class Intersection {
private:
    Car carsFromEast[10];
    unsigned numberOfCarsEast = 0;

    Car carsFromWest[10];
    unsigned numberOfCarsWest = 0;

    Car carsFromSouth[10];
    unsigned numberOfCarsSouth = 0;

    Car carsFromNorth[10];
    unsigned numberOfCarsNorth = 0;

    int duration;
    char * currentDirection;
    int currentDirectionIndex = 0;

public:
    Intersection();

    Intersection(const char * initDirection, int duration);
    const int getDuration() const;
    void addWest(Car car);

    void incrementWest();

    void decrementWest();

    void printWest();

    void removeCarsFromWest(int numberOfCars);

    void addEast(Car car);

    void incrementEast();

    void decrementEast();

    void printEast();

    void removeCarsFromEast(int numberOfCars);

    void addSouth(Car car);

    void incrementSouth();

    void decrementSouth();

    void printSouth();

    void removeCarsFromSouth(int numberOfCars);

    void addNorth(Car car);

    void incrementNorth();

    void decrementNorth();

    void printNorth();

    void removeCarsFromNorth(int numberOfCars);

    void reduceCarsFromCurrentDirection();

    void changeDirection();

    const char * getCurrentDirection() const;

    void tick();

    void add(Car car, const char * direction);

};

#endif //OOP_2022_TASKS_INTERSECTION_H
