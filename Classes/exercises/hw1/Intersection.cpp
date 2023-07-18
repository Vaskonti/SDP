#include "Intersection.h"
#include <cstring>
#include <string>
#include <iostream>

const char directions[4][6] = {{"east"},
                            {"west"},
                            {"north"},
                            {"south"}};


Intersection::Intersection() {
    this->currentDirection = new char[strlen(directions[0]) + 1];
    strcpy(this->currentDirection, directions[0]);
    this->duration = 0;
}

Intersection::Intersection(const char *initDirection, int duration) {
    if (this->currentDirection != nullptr) {
        delete[] this->currentDirection;
    }
    for (int i = 0; i < 4; ++i) {
        if (strcmp(initDirection, directions[i]) == 0) {
            this->currentDirection = new char[strlen(directions[i]) + 1];
            strcpy(this->currentDirection, directions[i]);
            this->currentDirectionIndex = i;
        }
    }

    this->duration = duration;
}

void Intersection::add(Car car, const char *direction) {
    if (strcmp(direction, "west") == 0) {
        this->addWest(car);
    } else if (strcmp(direction, "east") == 0) {
        this->addEast(car);
    } else if (strcmp(direction, "north") == 0) {
        this->addNorth(car);
    } else if (strcmp(direction, "south") == 0) {
        this->addSouth(car);
    } else {
        std::cerr << "Invalid direction entered!";
    }
}

void Intersection::addNorth(Car car) {
    this->carsFromNorth[this->numberOfCarsNorth] = car;
    this->incrementNorth();
}

void Intersection::incrementNorth() {
    this->numberOfCarsNorth++;
}

void Intersection::decrementNorth() {
    this->numberOfCarsNorth--;
}

void Intersection::addSouth(Car car) {
    this->carsFromSouth[this->numberOfCarsSouth] = car;
    this->incrementSouth();
}

void Intersection::incrementSouth() {
    this->numberOfCarsSouth++;
}

void Intersection::decrementSouth() {
    this->numberOfCarsSouth--;
}

void Intersection::addEast(Car car) {
    this->carsFromEast[this->numberOfCarsEast] = car;
    this->incrementEast();
}

void Intersection::incrementEast() {
    this->numberOfCarsEast++;
}

void Intersection::decrementEast() {
    this->numberOfCarsEast--;
}

void Intersection::addWest(Car car) {
    this->carsFromWest[this->numberOfCarsWest] = car;
    this->incrementWest();
}

void Intersection::incrementWest() {
    this->numberOfCarsWest++;
}

void Intersection::decrementWest() {
    this->numberOfCarsWest--;
}

void Intersection::tick() {
    std::cout << "BEFORE:" << std::endl;
    this->printEast();
    this->printWest();
    this->printNorth();
    this->printSouth();
    this->reduceCarsFromCurrentDirection();
    std::cout << "AFTER:" << std::endl;
    this->printEast();
    this->printWest();
    this->printNorth();
    this->printSouth();
}

void Intersection::printEast() {
    if (this->numberOfCarsEast == 0) {
        std::cout << "------EMPTY------" << std::endl;
    } else {
        for (int i = 1; i <= numberOfCarsEast; ++i) {
            std::cout << i << ". " << this->carsFromEast[i - 1].getBrand() << std::endl;
        }
    }
}

void Intersection::printWest() {
    if (this->numberOfCarsWest == 0) {
        std::cout << "------EMPTY------" << std::endl;
    } else {
        for (int i = 1; i <= numberOfCarsWest; ++i) {
            std::cout << i << ". " << this->carsFromWest[i - 1].getBrand() << std::endl;
        }
    }
}

void Intersection::printNorth() {
    if (this->numberOfCarsNorth == 0) {
        std::cout << "------EMPTY------" << std::endl;
    } else {
        for (int i = 1; i <= numberOfCarsNorth; ++i) {
            std::cout << i << ". " << this->carsFromNorth[i - 1].getBrand() << std::endl;
        }
    }
}

void Intersection::printSouth() {
    if (this->numberOfCarsSouth == 0) {
        std::cout << "------EMPTY------" << std::endl;
    } else {
        for (int i = 1; i <= numberOfCarsSouth; ++i) {
            std::cout << i << ". " << this->carsFromSouth[i - 1].getBrand() << std::endl;
        }
    }
}

void Intersection::reduceCarsFromCurrentDirection() {
    char *currentDir = new char[strlen(this->getCurrentDirection()) + 1];
    strcpy(currentDir, this->getCurrentDirection());

    if (strcmp(currentDir, "west") == 0) {
        this->removeCarsFromWest(this->getDuration());
    } else if (strcmp(currentDir, "east") == 0) {
        this->removeCarsFromEast(this->getDuration());
    } else if (strcmp(currentDir, "north") == 0) {
        this->removeCarsFromNorth(this->getDuration());
    } else if (strcmp(currentDir, "south") == 0) {
        this->removeCarsFromSouth(this->getDuration());
    } else {
        std::cerr << "Invalid direction entered!";
    }
    this->changeDirection();

}


const char *Intersection::getCurrentDirection() const {
    return this->currentDirection;
}

const int Intersection::getDuration() const {
    return this->duration;
}

void Intersection::removeCarsFromEast(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsEast; ++i) {
        this->carsFromEast[i] = this->carsFromEast[i + numberOfCars];
    }
    for (int i = 0; i < this->duration; ++i) {
        this->decrementEast();
    }
}

void Intersection::removeCarsFromWest(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsWest; ++i) {
        this->carsFromWest[i] = this->carsFromWest[i + numberOfCars];
    }
    for (int i = 0; i < this->duration; ++i) {
        this->decrementWest();
    }
}

void Intersection::removeCarsFromNorth(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsNorth; ++i) {
        this->carsFromNorth[i] = this->carsFromNorth[i + numberOfCars];
    }
    for (int i = 0; i < this->duration; ++i) {
        this->decrementNorth();
    }
}

void Intersection::removeCarsFromSouth(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsWest; ++i) {
        this->carsFromSouth[i] = this->carsFromSouth[i + numberOfCars];
    }
    for (int i = 0; i < this->duration; ++i) {
        this->decrementSouth();
    }
}

void Intersection::changeDirection() {
    if (this->currentDirectionIndex == 3) {
        this->currentDirectionIndex = 0;
    } else {
        this->currentDirectionIndex++;
    }
    delete[] this->currentDirection;
    this->currentDirection = new char[strlen(directions[currentDirectionIndex]) + 1];
    strcpy(this->currentDirection, directions[this->currentDirectionIndex]);

}

