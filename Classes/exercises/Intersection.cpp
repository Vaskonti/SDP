#include <cstring>
#include <iostream>
#include "Car.h"
#include "CarContainer.h"
#include "Intersection.h"

const int INTERSECTION_CAR_CAPACITY = 20;

const char *Intersection::handleCarAddError(int responseCode)
{
	if (responseCode == CAR_ADD_OK)
	{
		return "Car added successfully!";
	}
	if (responseCode == CAR_ADD_OVERFLOW_ERROR)
	{
		return "Car added successfully!";
	}
	return "Car addition operation ended unexpectedly";
}

const char *Intersection::addCarToContainer(const Car& car, CarContainer &container)
{
	int result = container.addCar(car);
	return this->handleCarAddError(result);
}

int Intersection::getDirectionFromString(const char *directionString)
{
	int directionCode = DEFAULT_DIRECTION;
	if (strcmp(directionString, "west") == 0 || strcmp(directionString, "West") == 0)
	{
		directionCode = DIRECTION_WEST;
	}
	if (strcmp(directionString, "east") == 0 || strcmp(directionString, "East") == 0)
	{
		directionCode = DIRECTION_EAST;
	}
	if (strcmp(directionString, "south") == 0 || strcmp(directionString, "South") == 0)
	{
		directionCode = DIRECTION_SOUTH;
	}
	if (strcmp(directionString, "north") == 0 || strcmp(directionString, "North") == 0)
	{
		directionCode = DIRECTION_NORTH;
	}
	return directionCode;
}

void Intersection::changeDirection()
{
	this->direction = this->directionMap[this->direction];
}

void Intersection::print(ostream &out)
{
	out << "East:";
	this->westCarContainer.print(out);
	out << "West:";
	this->westCarContainer.print(out);
	out << "North:";
	this->westCarContainer.print(out);
	out << "South:";
	this->westCarContainer.print(out);
}

void Intersection::letCarsPassFromCurrentDirection()
{
	CarContainer currentContainer;
	bool containerExists = true;
	switch (this->direction)
	{
	case DIRECTION_EAST:
		currentContainer = this->eastCarContainer;
		break;
	case DIRECTION_WEST:
		currentContainer = this->westCarContainer;
		break;
	case DIRECTION_NORTH:
		currentContainer = this->northCarContainer;
		break;
	case DIRECTION_SOUTH:
		currentContainer = this->southCarContainer;
		break;
	default:
		containerExists = false;
	}

	if (containerExists)
		currentContainer.removeMultiple(this->duration);
}

Intersection::Intersection()
{
	this->direction = DEFAULT_DIRECTION;
	this->duration = 0;
	this->directionMap[DIRECTION_WEST] = DIRECTION_NORTH;
	this->directionMap[DIRECTION_WEST] = DIRECTION_NORTH;
	this->directionMap[DIRECTION_WEST] = DIRECTION_NORTH;
	this->directionMap[DIRECTION_WEST] = DIRECTION_NORTH;
	this->westCarContainer.setCapacity(INTERSECTION_CAR_CAPACITY);
	this->eastCarContainer.setCapacity(INTERSECTION_CAR_CAPACITY);
	this->southCarContainer.setCapacity(INTERSECTION_CAR_CAPACITY);
	this->northCarContainer.setCapacity(INTERSECTION_CAR_CAPACITY);
}

Intersection::Intersection(const char *direction, int duration, int capacityPerContainer)
{
	this->direction = this->getDirectionFromString(direction);
    this->westCarContainer.setCapacity(capacityPerContainer);
    this->northCarContainer.setCapacity(capacityPerContainer);
    this->eastCarContainer.setCapacity(capacityPerContainer);
    this->southCarContainer.setCapacity(capacityPerContainer);
	this->duration = duration;
}

const char *Intersection::addWest(Car car)
{
	return this->addCarToContainer(car, this->westCarContainer);
}

const char *Intersection::addNorth(Car car)
{
	return this->addCarToContainer(car, this->northCarContainer);
}

const char *Intersection::addSouth(Car car)
{
	return this->addCarToContainer(car, this->southCarContainer);
}

const char *Intersection::addEast(Car car)
{
	return this->addCarToContainer(car, this->eastCarContainer);
}

void Intersection::tick(ostream &out)
{
	out << "BEFORE:";
	this->print(cout);

	this->letCarsPassFromCurrentDirection();
	this->changeDirection();

	out << "AFTER:";
	this->print(out);
}