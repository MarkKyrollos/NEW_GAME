/**
 * Project Untitled
 */


#ifndef _MINOR_H
#define _MINOR_H

#include "enemy.h"


class minor: public enemy {
public: 
    
void Rand_Shoot();
    
/**
 * @param helth
 * @param mvmt_spd
 * @param Playa
 * @param Loc
 * @param Facer
 * @param Rowd
 * @param Cold
 */
void minor(int helth, float mvmt_spd, bool Playa, int Loc, int Facer, int Rowd, int Cold);
};

#endif //_MINOR_H