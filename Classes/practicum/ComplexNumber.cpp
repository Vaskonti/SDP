#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

ComplexNumber::ComplexNumber() {
    this->real = 0;
    this->imaginary = 0;
}

double ComplexNumber::getRealPart() const  {
    return this->real;
}

double ComplexNumber::getImaginaryPart() const {
    return this->imaginary;
}
void ComplexNumber::setRealPart(double number) {
    this->real = number;
}
void ComplexNumber::setImaginaryPart(double number) {
    this->imaginary = number;
}
void ComplexNumber::printComplexNumber() const {
    std::cout << this->real << " + " << this->imaginary << "i" << std::endl;
}

void ComplexNumber::readComplexNumber() {
    std::cout << "Enter real part:";
    std::cin >> this->real;
    std::cout << "Enter imaginary part:";
    std::cin >> this->imaginary;
}

void ComplexNumber::add(ComplexNumber number) {
    this->real += number.real;
    this->imaginary += number.imaginary;
}

void ComplexNumber::subtract(ComplexNumber number) {
    this->real -= number.real;
    this->imaginary -= number.imaginary;
}
void ComplexNumber::multiplyBy(ComplexNumber number) {
    this->real = this->real * number.real - this->imaginary * number.imaginary;
    this->imaginary = this->real * number.imaginary + this->imaginary * number.real;
}
void ComplexNumber::divideBy(ComplexNumber number) {
    this->real = this->real * number.real + this->imaginary * number.imaginary /
            (number.real * number.real + number.imaginary * number.imaginary);
    this->imaginary = this->imaginary * number.real - this->real * number.imaginary /
            (number.real * number.real + number.imaginary * number.imaginary);
}
ComplexNumber addTwo(const ComplexNumber &a, const ComplexNumber &b) {
    return {a.getRealPart() + b.getRealPart(), a.getImaginaryPart() + b.getImaginaryPart()};
}

ComplexNumber subtractTwo(const ComplexNumber &a, const ComplexNumber &b) {
    return {a.getRealPart() - b.getRealPart(), a.getImaginaryPart() - b.getImaginaryPart()};
}

ComplexNumber multiplyTwo(const ComplexNumber &a, const ComplexNumber &b) {
    ComplexNumber result;
    result.setRealPart(a.getRealPart() * b.getRealPart() - a.getImaginaryPart() * b.getImaginaryPart());
    result.setImaginaryPart(a.getRealPart() * b.getImaginaryPart() + a.getImaginaryPart() * b.getRealPart());
    return result;
}

ComplexNumber divideTwo(const ComplexNumber &a, const ComplexNumber &b) {
    ComplexNumber result;
    result.setRealPart(a.getRealPart() * b.getRealPart() + a.getImaginaryPart() * b.getImaginaryPart() /
        (b.getRealPart() * b.getRealPart() + b.getImaginaryPart() * b.getImaginaryPart()));
    result.setImaginaryPart(a.getImaginaryPart() * b.getRealPart() - a.getRealPart() * b.getImaginaryPart() /
        (b.getRealPart() * b.getRealPart() + b.getImaginaryPart() * b.getImaginaryPart()));
    return result;
}