/**
 * Project Untitled
 */


#include "enemy.h"

/**
 * enemy implementation
 */


/**
 * @return int
 */
int enemy::Find_Player() {
    return 0;
}

/**
 * @param helth
 * @param mvmt_spd
 * @param Playa
 * @param Loc
 * @param Facer
 * @param Rowd
 * @param Cold
 */
enemy::enemy(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, bool los, bool playerFound): character(helth, mvmt_spd,live, Facer, Rowd, Cold, map, charLoc, Playa) {

    Line_of_sight=los;
    Found_player=playerFound;
}
