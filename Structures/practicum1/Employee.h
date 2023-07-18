//#pragma once
#include <iostream>

void testHasEmployee();

struct Employee {
    char  name[64];
    double salary;
    Employee *boss;

    void init()
    {
        std::cout<<"Enter name of employee:";
        std::cin>>name;

        std::cout<<"Enter salary:";
        std::cin>>salary;

    }

};

struct Team {
    char name[128];
    Employee employees[100];
    int numberOfEmployees;

    void init()
    {
        std::cout<<"Enter name for team:";
        std::cin>>name;
        std::cout<<"Enter number of employees:";
        std::cin>>numberOfEmployees;
    }
};

struct Company {
    char name[128];
    Team teams[10];
    int numberOfTeams;
};

bool hasEmployee (Company & company, const char * name)
{
    for (int i = 0; i < company.numberOfTeams ; ++i) {
        for (int j = 0; j < company.teams[i].numberOfEmployees ; ++j) {
            if(strcmp(name,company.teams[i].employees[j].name) == 0)
                return true;
        }
    }
    return false;
}
void findBossName(const Company &company)
{
    for (int i = 0; i < company.numberOfTeams ; ++i) {
        for (int j = 0; j <company.teams[i].numberOfEmployees ; ++j) {
            if(!company.teams[i].employees[j].boss)
            {
                std::cout<<company.teams[i].employees[j].name;
                return;
            }
        }
    }
}
void testHasEmployee()
{
    Company company = {};

    std::cout<<"Enter company name:";
    std::cin>>company.name;
    std::cout<<"Enter number of teams:";
    std::cin>>company.numberOfTeams;

    for (int i = 0; i < company.numberOfTeams ; ++i) {
        company.teams[i].init();
        for (int j = 0; j < company.teams[i].numberOfEmployees; ++j) {
            company.teams[i].employees[j].init();
        }
    }

    char name[128];
    std::cin>>name;

    std::cout<<(hasEmployee(company, name)? "it exists" : "it does not exist")<<std::endl;

}
void testFindBoss()
{
    Company company = {};

    std::cout<<"Enter company name:";
    std::cin>>company.name;
    std::cout<<"Enter number of teams:";
    std::cin>>company.numberOfTeams;

    for (int i = 0; i < company.numberOfTeams ; ++i) {
        company.teams[i].init();
        for (int j = 0; j < company.teams[i].numberOfEmployees; ++j) {
            company.teams[i].employees[j].init();
            company.teams[i].employees[j].boss = &company.teams[i].employees[j];
        }
    }
    company.teams[0].employees[0].boss = nullptr;
    std::cout<<"The boss is:";
    findBossName(company);
}