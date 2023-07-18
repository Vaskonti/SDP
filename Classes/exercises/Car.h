#pragma once

#include <ostream>
using namespace std;

class Car
{
    char *brand;
    char *regNo;
    char *color;
    int doorsCount;

public:
    Car();
    Car(const char * brand, const char * regNo, const char * color, int doorsCount);

    ~Car();

    void setBrand(const char * brand);
    void setRegNo(const char * regNo);
    void setColor(const char * color);
    void setDoorsCount(int doorsCount);
    const char * getBrand() const;
    const char * getRegNo() const;
    const char * getColor() const;
    const int getDoorsCount() const;

    void print(ostream &);
};