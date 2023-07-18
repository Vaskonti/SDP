#pragma once

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber();

    ComplexNumber(double real, double imaginary);

    double getRealPart() const;

    double getImaginaryPart() const;

    void setRealPart(double number);

    void setImaginaryPart(double number);

    void readComplexNumber();

    void printComplexNumber() const;

    void add(ComplexNumber number);

    void subtract(ComplexNumber number);

    void multiplyBy(ComplexNumber number);

    void divideBy(ComplexNumber number);

};
ComplexNumber addTwo(const ComplexNumber &a, const ComplexNumber &b);
ComplexNumber subtractTwo(const ComplexNumber &a, const ComplexNumber &b);
ComplexNumber multiplyTwo(const ComplexNumber &a, const ComplexNumber &b);
ComplexNumber divideTwo(const ComplexNumber &a, const ComplexNumber &b);



