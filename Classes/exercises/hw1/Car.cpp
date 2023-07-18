#include <iostream>
#include <cstring>
#include "Car.h"

Car::Car() {
    this->licensePlate = nullptr;
    this->brand = nullptr;
    this->color = nullptr;
    this->doorsCount = 0;
}
Car::Car(const char *licensePlate, const char *brand, const char *color, const int numberDoors) {
    this->setLicensePlate(licensePlate);
    this->setBrand(brand);
    this->setColor(color);
    this->setDoorsCount(numberDoors);
}

void Car::setLicensePlate(const char *_licensePlate) {
    if(this->licensePlate != nullptr)
        delete [] this->licensePlate;
    this->licensePlate = new char[strlen(_licensePlate) + 1];
    strcpy_s(this->licensePlate, _licensePlate);
}

void Car::setBrand(const char *_brand) {
    if(this->brand != nullptr)
        delete [] this->brand;
    this->brand = new char[strlen(_brand) + 1];
    strcpy(this->brand, _brand);
}

void Car::setColor(const char *_color) {
    if(this->color != nullptr)
        delete [] this->color;
    this->color = new char[strlen(_color) + 1];
    strcpy(this->color, _color);
}

void Car::setDoorsCount(int _doorsCount) {
    this->doorsCount = _doorsCount;
}

const char * Car::getLicensePlate() const {
    return this->licensePlate;
}
const char * Car::getBrand() const {
    return this->brand;
}
const char * Car::getColor() const {
    return this->color;
}
const int Car::getDoorsCount() const {
    return this->doorsCount;
}

void Car::print() {
    std::cout<<this->color<<" "<< this->brand<<" ("<<this->licensePlate<<"), "<<this->doorsCount<<" doors";
}