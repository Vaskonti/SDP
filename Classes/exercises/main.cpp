#include <iostream>
#include "Car.cpp"
#include "CarContainer.cpp"
#include "Intersection.cpp"
using namespace std;

int main()
{
    Car bmw1;
    bmw1.setBrand("BMW");
    bmw1.setRegNo("CB0123XA");
    bmw1.setColor("Black");
    bmw1.setDoorsCount(2);
    bmw1.print(cout); // Black BMW (CB0123XA), 2 doors

    Intersection intersection("west", 2,30); //Първоначална посока - запад, продължителност на светофара - 2, капацитет на страна
    Car bmw2("BMW 2", "Red", "CB0124XA", 4),
        audi1("AUDI 1", "Red", "CB0124XA", 4),
        audi2("AUDI 2", "Red", "CB0124XA", 4),
        seat1("SEAT 1", "Red", "CB0124XA", 4),
        seat2("SEAT 2", "Red", "CB0124XA", 4),
        subaru1("Subaru 1", "Red", "CB0124XA", 4),
        subaru2("Subaru 2", "Red", "CB0124XA", 4);

    cout << intersection.addWest(bmw1);
//    cout << intersection.addWest(audi1);
//    cout << intersection.addWest(subaru1);
//    cout << intersection.addSouth(bmw2);
//    cout << intersection.addEast(audi2);
//    cout << intersection.addNorth(subaru2);
//    cout << intersection.addNorth(seat2);
//    cout << intersection.addNorth(seat1);
////    intersection.tick(cout);

    return 0;
}