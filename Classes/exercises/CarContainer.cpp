// This is where you shine!

#include "CarContainer.h"
#include <iostream>
void CarContainer::setCapacity(int _capacity)
{
    this->capacity = _capacity;
}

int CarContainer::addCar(Car car)
{
    this->cars[this->currentNumberOfCars].setDoorsCount(car.getDoorsCount());
    this->cars[this->currentNumberOfCars].setBrand(car.getBrand());
    this->cars[this->currentNumberOfCars].setRegNo(car.getRegNo());
    this->cars[this->currentNumberOfCars].setColor(car.getColor());

    this->incrementCurrentNumberOfCars();
    if(this->currentNumberOfCars > this->capacity)
        return CAR_ADD_OVERFLOW_ERROR;
    return CAR_ADD_OK;
}
void CarContainer::print(ostream &out)
{
    for (int i = 0; i < this->currentNumberOfCars ; ++i) {
         cars->print(out);
    }
}
void CarContainer::removeMultiple(int count)
{
}
void CarContainer::incrementCurrentNumberOfCars()
{
    this->currentNumberOfCars++;
}