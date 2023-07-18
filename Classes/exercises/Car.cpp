#include <cstring>
#include <ostream>
#include "Car.h"

using namespace std;

Car::Car()
{
    this->brand = nullptr;
    this->regNo = nullptr;
    this->color = nullptr;
    this->doorsCount = 0;
}

Car::Car(const char *brand, const char *color, const char *regNo, int doorsCount) : Car()
{
    this->setBrand(brand);
    this->setColor(color);
    this->setRegNo(regNo);
    this->setDoorsCount(doorsCount);
}

void Car::setBrand(const char * _brand)
{
    if (this->brand != nullptr)
    {
        delete[] this->brand;
    }
    this->brand = new char[strlen(_brand) + 1];
    strcpy(this->brand, _brand);
}

void Car::setRegNo(const char * _regNo)
{
    if (this->regNo != nullptr)
    {
        delete[] this->regNo;
    }
    this->regNo = new char[strlen(_regNo) + 1];
    strcpy(this->regNo, _regNo);
}

void Car::setColor(const char * _color)
{
    if (this->color != nullptr)
    {
        delete[] this->color;
    }
    this->color = new char[strlen(_color) + 1];
    strcpy(this->color, _color);
}

void Car::setDoorsCount(int _doorsCount)
{
    this->doorsCount = _doorsCount;
}

void Car::print(ostream &out)
{
    out << this->color << " " << this->brand << " (" << this->regNo << "), " << this->doorsCount << " doors" << endl;
}

Car::~Car()
{
    if (this->color != nullptr)
    {
        delete[] this->color;
    }

    if (this->brand != nullptr)
    {
        delete[] this->brand;
    }

    if (this->regNo != nullptr)
    {
        delete[] this->regNo;
    }
}
const char * Car::getRegNo() const {
    return this->regNo;
}
const char * Car::getColor() const {
    return this->color;
}
const char * Car::getBrand() const {
    return this->brand;
}
const int Car::getDoorsCount() const {
    return this->doorsCount;
}
