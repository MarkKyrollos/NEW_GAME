/**
 * Project Untitled
 */

#include "player.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>


/**
 * player implementation
 */


/**
 * @return void
 */
void player::In_Enemy(QVector<QVector<QVector<character*>>> &charLoc) {
    character* nullifier=NULL;
    if (charLoc[row][col][1] != nullifier)
    {
        health-=10;
    }//
}



/**
 * @return bool
 */

/**
 * @param helth
 * @param mvmt_spd
 * @param Playa
 * @param Loc
 * @param Facer
 * @param Rowd
 * @param Cold
 */
player::player(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QString NAME, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, QVector<QVector<bool>> &presence, QGraphicsScene &scene): character(helth, mvmt_spd,live, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene) {

    Name=NAME; //sets the name
    QPixmap pac("player.png"); //sets the image
       pac=pac.scaledToWidth(50);
       pac=pac.scaledToHeight(50);
       setPixmap(pac);
       setPos(50+50*col,50+50*row);

}

player::~player()
{
    //TODO: Make something happen when the player dies
}

void player::keyPressEvent(QKeyEvent* event)
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    QVector<QVector<bool>>* presencePoint=presence;
    if(event->key()==Qt::Key_Up)
    {

        moveUp(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row); //places the player image in its new position

    }
    else if(event->key()==Qt::Key_Down)
    {
        moveDown(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);


    }
    else if(event->key()==Qt::Key_Left)
    {

        moveLeft(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);


    }
    else if(event->key()==Qt::Key_Right)
    {

        moveRight(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);


    }
    if(event->key()==Qt::Key_Space)
    {
            shoot();
    }

    setPos(50+50*col,50+50*row);

}
