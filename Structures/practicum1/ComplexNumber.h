#pragma once
#include <iostream>
#include <cmath>

void testReadPrint();
void testSum();
void testSubtraction();
void testMultiplication();
void testDivision();
void testAverage();
void testSort();


struct ComplexNumber
{
    double real, imaginary;

    void print()
    {
        std::cout<<real<<"+"<<imaginary<<"i"<<std::endl;
    }
    void read()
    {
        std::cout<<"Enter real part:";
        std::cin>>real;

        std::cout<<"Enter imaginary part:";
        std::cin>>imaginary;
    }
};

ComplexNumber add(ComplexNumber &number1, ComplexNumber & number2)
{
    ComplexNumber sum = {0,0};
    sum.real = number1.real + number2.real;
    sum.imaginary = number1.imaginary + number2.imaginary;

    return sum;
}

ComplexNumber subtraction(ComplexNumber &number1, ComplexNumber & number2)
{
    ComplexNumber result = {0,0};
    result.real = number1.real - number2.real;
    result.imaginary = number1.imaginary - number2.imaginary;

    return result;
}

ComplexNumber multiplication(ComplexNumber &number1, ComplexNumber & number2)
{
    ComplexNumber result = {0,0};
    result.real = number1.real * number2.real - number1.imaginary * number2.imaginary;
    result.imaginary = number1.real * number2.imaginary + number2.real * number1.imaginary;

    return result;
}

ComplexNumber division(ComplexNumber &number1, ComplexNumber & number2)
{
    ComplexNumber result = {0,0};
    result.real = (number1.real * number2.real + number1.imaginary * number2.imaginary)
            / (number2.real * number2.real + number2.imaginary * number2.imaginary);
    result.imaginary =( number1.imaginary * number2.real - number1.real * number2.imaginary)
            / (number2.real * number2.real + number2.imaginary * number2.imaginary);

    return result;
}

ComplexNumber average(ComplexNumber * array, int count)
{
    ComplexNumber sum = {0,0};
    for (int i = 0; i < count ; ++i) {
        sum  = add(sum, array[i]);
    }
    ComplexNumber n = {(double) count, (double) count};
    sum = division(sum,n);

    return sum;
}
double modulus(ComplexNumber &number)
{
    return sqrt(number.real * number.real + number.imaginary * number.imaginary);
}

void testReadPrint()
{
    std::cout<<"Testing read and print:"<<std::endl;
    ComplexNumber z {0,0}, w {0,0};
    z.read();
    w.read();

    z.print();
    w.print();
}
void testSum()
{
    std::cout<<"Testing sum:"<<std::endl;
    ComplexNumber z {0,0}, w {0,0};
    z.read();
    w.read();

    ComplexNumber sum = add(z,w);
    sum.print();
}
void testSubtraction()
{
    std::cout<<"Testing subtraction:"<<std::endl;
    ComplexNumber z {0,0}, w {0,0};
    z.read();
    w.read();

    ComplexNumber result = subtraction(z,w);
    result.print();
}

void testMultiplication()
{
    std::cout<<"Testing multiplication:"<<std::endl;
    ComplexNumber z {0,0}, w {0,0};
    z.read();
    w.read();

    ComplexNumber result = multiplication(z,w);
    result.print();
}

void testDivision()
{
    std::cout<<"Testing division:"<<std::endl;
    ComplexNumber z {0,0}, w {0,0};
    z.read();
    w.read();

    ComplexNumber result = division(z,w);
    result.print();
}

void testAverage()
{
    std::cout<<"Testing average:"<<std::endl;

    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    ComplexNumber  array[100] = {0,0};

    for (int i = 0; i < n ; ++i) {
        array[i].read();
    }

    ComplexNumber result = average(array, n);

    result.print();
}

void testSort()
{
    std::cout<<"Testing sort:"<<std::endl;

    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    ComplexNumber array[100];
    for (int i = 0; i < n ; ++i) {
        array[i].read();
    }

    double modulusArr[100];
    for (int i = 0; i < n ; ++i) {
        modulusArr[i] = modulus(array[i]);
    }

    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n ; ++j) {
            if(modulusArr[i] > modulusArr[j])
            {
                double tempModulus = modulusArr[j];
                modulusArr[j] = modulusArr[i];
                modulusArr[i] = tempModulus;

                ComplexNumber tempComplex = array[j];
                array[j] = array[i];
                array[i] = tempComplex;
            }
        }
    }

    for (int i = 0; i < n ; ++i) {
        array[i].print();
    }

}