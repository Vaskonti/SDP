#pragma once
#include <iostream>

struct Appliance {
    int operationalHours;
    float wattage;
    // luxuryClass е число между 0 и 10, но никъде не е казано, че е цяло число
    int luxuryClass;
    float price;

    void init()
    {
        //обвързването на iostream с реализацията на типове данни е излишно и като цяло лоша идея. Ако искаш да имаш функция, която да въвежда данни от клавиатурата,
        //изнеси я на друго място - провери SRP
        std::cout<<"Enter operation hours of appliance:";
        std::cin>>operationalHours;
        std::cout<<"Enter wattage of appliance:";
        std::cin>>wattage;
        std::cout<<"Enter luxury class of appliance:";
        std::cin>>luxuryClass;
        std::cout<<"Enter price of device:";
        std::cin>>price;
    }
};
//Using polymorphism
//Това не е полиморфизъм, а наследяване
struct Microwave:  Appliance {};
struct Fridge:  Appliance {};
struct Aspirator:  Appliance {};
struct KitchenRobot:  Appliance {};
struct Stove:  Appliance {};

float getKWH(Appliance & appliance, const float priceKWH)
{
    int operationalHoursForMonth = appliance.operationalHours * 30;
    //не разбирам това 24 от къде дойде :)
    return ((((float)operationalHoursForMonth * appliance.wattage) / 1000) * priceKWH) / 24;
}

float getPrice(Appliance & appliance)
{
    return appliance.price;
}

int getLuxuryClass(Appliance & appliance)
{
    return appliance.luxuryClass;
}

void testCode()
{
    const int INSTALLATION_PRICE = 30;
    const float POWER_PRICE_KWH = 100.0f;
    const bool INCLUDES_INSTALLATION = true;

    Microwave microwave;
    std::cout<<"Microwave:"<<std::endl;
    microwave.init();

    Fridge fridge;
    std::cout<<"Fridge:"<<std::endl;
    fridge.init();

    std::cout<<"Total price per hour:"<<getKWH(microwave,POWER_PRICE_KWH ) + getKWH(fridge, POWER_PRICE_KWH )<<std::endl;
    std::cout<<"Microwave luxury class:"<<getLuxuryClass(microwave)<<std::endl;
    std::cout<<"Fridge luxury class:"<<getLuxuryClass(fridge)<<std::endl;

    std::cout<<"Microwave price: ("<<(INCLUDES_INSTALLATION ? "including": "excluding")<<" installation):"<<
                                    (INCLUDES_INSTALLATION ? getPrice(microwave) + INSTALLATION_PRICE: getPrice(microwave))<<std::endl;
    std::cout<<"Fridge price: ("<<(INCLUDES_INSTALLATION ? "including": "excluding")<<" installation):"<<
                                    (INCLUDES_INSTALLATION ? getPrice(microwave) + INSTALLATION_PRICE: getPrice(fridge))<<std::endl;



}

