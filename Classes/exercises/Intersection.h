#pragma once

#include <cstring>
#include <ostream>

#include "Car.h"
#include "CarContainer.h"

const int DIRECTION_EAST = 0;
const int DIRECTION_WEST = 1;
const int DIRECTION_NORTH = 2;
const int DIRECTION_SOUTH = 3;
const int DEFAULT_DIRECTION = DIRECTION_WEST;

class Intersection
{
    CarContainer westCarContainer;
    CarContainer eastCarContainer;
    CarContainer southCarContainer;
    CarContainer northCarContainer;

    int direction;
    int duration;
    int directionMap[4];

    int getDirectionFromString(const char *);
    void changeDirection();

    const char *handleCarAddError(int);
    const char *addCarToContainer(const Car&, CarContainer &);

    void print(ostream &);
    void letCarsPassFromCurrentDirection();

public:
    Intersection();
    Intersection(const char *direction, int duration, int capacityPerContainer);

    const char *addWest(Car car);
    const char *addNorth(Car car);
    const char *addEast(Car car);
    const char *addSouth(Car car);

    void tick(ostream &);
};