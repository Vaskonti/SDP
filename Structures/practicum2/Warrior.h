#pragma once
#include <iostream>

struct Warrior {
    char name [128];
    int age;
    Sword sword;
};

struct Sword {
    char * model;
    char * type;
    double power;
    int est;
};

void initializeWarrior(Warrior &warrior)
{
    std::cout<<"Enter sword model:";
    std::cin>>warrior.sword.model;
    std::cout<<"Enter sword type:";
    std::cin>>warrior.sword.type;
    std::cout<<"Enter sword power:";
    std::cin>>warrior.sword.power;
    std::cout<<"Enter year of forgery:";
    std::cin>>warrior.sword.est;
}