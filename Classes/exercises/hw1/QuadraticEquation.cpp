#include "QuadraticEquation.h"
#include <iostream>
#include <cmath>

QuadraticEquation::QuadraticEquation() {
    this->setA(0);
    this->setB(0);
    this->setC(0);
}

void QuadraticEquation::solveLinear() {
    std::cout<<-this->getC()/this->getB()<<std::endl;
}
QuadraticEquation::QuadraticEquation(const float A, const float B, const float C) {
    this->setA(A);
    this->setB(B);
    this->setC(C);
}
void QuadraticEquation::setA(const float _A) {
    this->A = _A;
}
void QuadraticEquation::setB(const float _B) {
    this->B = _B;
}
void QuadraticEquation::setC(const float _C) {
    this->C = _C;
}
const float QuadraticEquation::getA() const {
    return this->A;
}
const float QuadraticEquation::getB() const {
    return this->B;
}
const float QuadraticEquation::getC() const {
    return this->C;
}
void QuadraticEquation::solve() {
    if(this->getA() == 0)
    {
        this->solveLinear();
    }
    else
    {
        float D = this->getB()*this->getB() - 4 * this->getA() * this->getC();
        if(D < 0)
        {
            std::cout<<"There are no real roots"<<std::endl;
        }
        else if (D == 0)
        {
            std::cout<< (-this->getB()) / 2 * this->getA()<<std::endl;
        }
        else
        {
            std::cout<< (-this->getB() - sqrt(D)) / 2 * this->getA()<<std::endl;
            std::cout<< (-this->getB() + sqrt(D)) / 2 * this->getA()<<std::endl;
        }
    }

}
int main()
{
    QuadraticEquation quadraticEquation;
    quadraticEquation.setA(0);
    quadraticEquation.setB(6);
    quadraticEquation.setC(3);
    quadraticEquation.solve();
}