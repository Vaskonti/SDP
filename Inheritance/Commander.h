#ifndef CAR_CPP_COMMANDER_H
#define CAR_CPP_COMMANDER_H

#include "Soldier.h"

template<typename Skill>
class Commander : public Soldier<Skill> {
    Soldier<Skill> * soldiers;
    char * description;
};


#endif //CAR_CPP_COMMANDER_H
