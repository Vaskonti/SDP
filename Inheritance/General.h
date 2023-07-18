#ifndef CAR_CPP_GENERAL_H
#define CAR_CPP_GENERAL_H

#include "Commander.h"

template<typename Skill>
class General : public Soldier<Skill> {
private:
    Commander<Skill> * commander;
    char * description;
public:
    General();
};


#endif //CAR_CPP_GENERAL_H
