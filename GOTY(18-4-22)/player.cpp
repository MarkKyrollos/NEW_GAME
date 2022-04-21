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
player::player(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QString NAME, bool Invincible, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live): character(helth, mvmt_spd,live, Facer, Rowd, Cold, map, charLoc, Playa) {

    Name=NAME;
    this->Invincible=Invincible;
    QPixmap p("Tweety.png");
       p=p.scaledToWidth(50);
       p=p.scaledToHeight(50);
       setPixmap(p);
       setPos(50+50*col,50+50*row);

}

void player::keyPressEvent(QKeyEvent* event)
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    if(event->key()==Qt::Key_Up)
    {
        moveUp(*charLocPoint);
        In_Enemy(*charLocPoint);
    }
    else if(event->key()==Qt::Key_Down)
    {
        moveDown(*charLocPoint);
        In_Enemy(*charLocPoint);
    }
    else if(event->key()==Qt::Key_Left)
    {
        moveLeft(*charLocPoint);
        In_Enemy(*charLocPoint);
    }
    else if(event->key()==Qt::Key_Right)
    {
        moveRight(*charLocPoint);
        In_Enemy(*charLocPoint);
    }
    setPos(50+50*col,50+50*row);
}
