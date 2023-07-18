#ifndef OOP_2022_TASKS_CAR_H
#define OOP_2022_TASKS_CAR_H

class Car {
private:
    char * licensePlate = nullptr;
    char * brand = nullptr;
    char * color = nullptr;
    int doorsCount;

public:
    Car();

    Car(const char *licensePlate, const char *brand, const char *color, const int numberDoors);

    const char *getLicensePlate() const;

    const char *getBrand() const;

    const char *getColor() const;

    const int getDoorsCount() const;

    void setLicensePlate(const char *licensePlate);

    void setBrand(const char *brand);

    void setColor(const char *color);

    void setDoorsCount(const int doorsCount);

    void print();

};

#endif //OOP_2022_TASKS_CAR_H
