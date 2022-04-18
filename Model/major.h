/**
 * Project Untitled
 */


#ifndef _MAJOR_H
#define _MAJOR_H

#include "enemy.h"


class major: public enemy {
public: 
    bool Line_of_sight;
    
/**
 * @param helth
 * @param mvmt_spd
 * @param Playa
 * @param Loc
 * @param Facer
 * @param Rowd
 * @param Cold
 */
void major(int helth, float mvmt_spd, bool Playa, int Loc, int Facer, int Rowd, int Cold);
};

#endif //_MAJOR_H