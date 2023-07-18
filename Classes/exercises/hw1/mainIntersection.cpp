#include "Intersection.cpp"

int main()
{
    Intersection intersection("west",2);
    Car bmw1,bmw2,audi1,audi2,seat1,seat2,subaru1,subaru2;
    bmw1.setLicensePlate("EB2122BM");
    bmw1.setBrand("BMW");
    bmw1.setColor("Black");
    bmw1.setDoorsCount(3);

    bmw2.setLicensePlate("CB1200BH");
    bmw2.setBrand("BMW");
    bmw2.setColor("Red");
    bmw2.setDoorsCount(4);

    audi1.setLicensePlate("A1489AM");
    audi1.setBrand("Audi");
    audi1.setColor("Blue");
    audi1.setDoorsCount(4);

    audi2.setLicensePlate("E1185SB");
    audi2.setBrand("Audi");
    audi2.setColor("Black");
    audi2.setDoorsCount(4);

    subaru1.setLicensePlate("EB2037BA");
    subaru1.setBrand("Subaru");
    subaru1.setColor("Blue");
    subaru1.setDoorsCount(2);

    subaru2.setLicensePlate("EB5324BM");
    subaru2.setBrand("Subaru");
    subaru2.setColor("Red");
    subaru2.setDoorsCount(4);

    seat1.setLicensePlate("BA1154PA");
    seat1.setBrand("Seat");
    seat1.setColor("Yellow");
    seat1.setDoorsCount(4);

    seat2.setLicensePlate("PK1014KM");
    seat2.setBrand("Seat");
    seat2.setColor("Black");
    seat2.setDoorsCount(4);

    intersection.addWest(bmw1);
    intersection.addWest(audi1);
    intersection.addWest(subaru1);
    intersection.addSouth(bmw2);
    intersection.addEast(audi2);
    intersection.addNorth(subaru2);
    intersection.addNorth(seat2);
    intersection.addNorth(seat1);
    intersection.tick();

}