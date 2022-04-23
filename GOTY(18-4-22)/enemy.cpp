/**
 * Project Untitled
 */


#include "enemy.h"
#include "player.h"

/**
 * enemy implementation
 */


/**
 * @return int
 */
int enemy::Find_Player(player p1) {
    //if messed up contact programmer to fix it
    player_location[0]=p1.row;
    player_location[1]=p1.col;
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
enemy::enemy(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, bool los, bool playerFound, QVector<QVector<bool>> &presence, QGraphicsScene &scene): character(helth, mvmt_spd,live, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene) {

    Line_of_sight=los;
    Found_player=playerFound;
    player_location[0]=Rowd;
    player_location[1]=Cold;

}
