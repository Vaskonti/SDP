#include <iostream>
#include "ComplexNumber.h"


int main() {
    ComplexNumber number = addTwo(ComplexNumber(1,2), ComplexNumber(1,2));
    number.printComplexNumber();
    ComplexNumber number1 = subtractTwo(ComplexNumber(2,3), ComplexNumber(1,2));
    number1.printComplexNumber();
    ComplexNumber number2 = multiplyTwo(ComplexNumber(2,3), ComplexNumber(1,2));
    number2.printComplexNumber();
    ComplexNumber number3 = divideTwo(ComplexNumber(2,3), ComplexNumber(1,2));
    number3.printComplexNumber();
}