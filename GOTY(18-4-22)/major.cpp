#include "major.h"


major::major(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major):  enemy(helth,mvmt_spd,alive,Facer,Rowd,Cold,map,charLoc,Playa,presence,scene, major)
{
    QPixmap majorE("major.png");
       majorE=majorE.scaledToWidth(50);
       majorE=majorE.scaledToHeight(50);
       setPixmap(majorE);
       setPos(50+50*col,50+50*row); // modify 2 major enemies' placement on the map

}



// this random movement function should be called repetitively

