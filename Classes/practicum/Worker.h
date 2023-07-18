#pragma once

class Worker {
private:
    char name[128];
    double salary;
    Worker *boss;
public:
    Worker(const char *name, double salary, Worker *boss);

    ~Worker();

    const char *getName() const;


};

class Team {
public:
    char name[128];
    Worker workers[20];
};

class Company {
public:
    char name[128];
    Team teams[10];
};
