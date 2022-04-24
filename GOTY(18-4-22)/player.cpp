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
    }
}



/**
 * @return bool
 */
bool player::Trigger_Invincibility() {
    return false;
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
player::player(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QString NAME, bool Invincible, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, QVector<QVector<bool>> &presence, QGraphicsScene &scene): character(helth, mvmt_spd,live, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene) {

    Name=NAME;
    this->Invincible=Invincible;
    QPixmap pac("player.png");
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

        //QPointF point(50+50*col,50+50*row);
        moveUp(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(row+25, col+25);
        //QLineF ln(point,pos());
        //setRotation(-1*ln.angle());

    }
    else if(event->key()==Qt::Key_Down)
    {
        /*
        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(50+col,50+row);
        setRotation(90);
        */
        //QPointF point(50+50*col,50+50*row);
        moveDown(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(row+25, col+25);
        //QLineF ln(point,pos());
        //setRotation(-1*ln.angle());


    }
    else if(event->key()==Qt::Key_Left)
    {
        /*
        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(50+col,50+row);

        setRotation(180);
        */
        //QPointF point(50+50*col,50+50*row);
        moveLeft(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(row+25, col+25);
        //QLineF ln(point,pos());
        //setRotation(-1*ln.angle());

    }
    else if(event->key()==Qt::Key_Right)
    {
        /*
        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(50+col,50+row);
        setRotation(0);
        */
        //QPointF point(50+50*col,50+50*row);
        moveRight(*charLocPoint, *presencePoint);
        In_Enemy(*charLocPoint);

        setPos(50+50*col,50+50*row);
        setTransformOriginPoint(row+25, col+25);
        //QLineF ln(point,pos());
        //setRotation(-1*ln.angle());

    }
    if(event->key()==Qt::Key_Space)
    {
            shoot();
    }

    setPos(50+50*col,50+50*row);

    //FIXME: this entire rotation system
}
