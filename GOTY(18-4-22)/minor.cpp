#include "minor.h"

minor::minor(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene)
{
    QPixmap minorE("minor.png");
       minorE=minorE.scaledToWidth(50);
       minorE=minorE.scaledToHeight(50);
       setPixmap(minorE);
       setPos(50+50*col,50+50*row); // modify the 2 minor's position according to Mahmoud's map
}