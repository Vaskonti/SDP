#ifndef CAR_CPP_OLDIER_H
#define CAR_CPP_OLDIER_H
#include <cstring>

template<typename Skill>
class Soldier {
private:
    char *name;
    unsigned int age;
    Skill skill;
    double salary;
public:
    Soldier();

    Soldier(const char *name, const unsigned int age, const Skill skill, double salary);

    Soldier(const Soldier<Skill> &other);

    void setName(const char *name);

    void setAge(const unsigned int age);

    void setSkill(const Skill skill);

    void setSalary(const double salary);

    const char *getName() const;

    const unsigned int getAge() const;

    const Skill getSkill() const;

    const double getSalary() const;

    Soldier<Skill> &operator=(const Soldier<Skill> &soldier);

    ~Soldier();
};

template <class Skill>
const char *Soldier<Skill>::getName() const {
    return name;
}
template <class Skill>
void Soldier<Skill>::setName(const char *_name) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}
template <class Skill>
const unsigned int Soldier<Skill>::getAge() const {
    return age;
}
template <class Skill>
void Soldier<Skill>::setAge(const unsigned int _age) {
    age = _age;
}
template <class Skill>
const double Soldier<Skill>::getSalary() const {
    return salary;
}
template <class Skill>
void Soldier<Skill>::setSalary(const double _salary) {
    salary = _salary;
}
template <class Skill>Soldier<Skill>::Soldier() {
    setName("<unknown_name>");
    age = 0;
    salary = 0;
    Skill{};
}
template <class Skill>Soldier<Skill>::Soldier(const char *name, const unsigned int age, const Skill skill,
                                              double salary) {
    setName(name);
    setAge(age);
    setSalary(salary);
    setSkill(skill);
}
template <class Skill>Soldier<Skill>::Soldier(const Soldier<Skill> &other) {
    if(this != &other)
    {

    }
}
#endif //CAR_CPP_OLDIER_H
