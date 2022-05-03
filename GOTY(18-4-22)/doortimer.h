#ifndef DOORTIMER_H
#define DOORTIMER_H

#include <QObject>
#include <QTimer>
#include "enemy.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsView>

class DoorTimer: public QObject,  public QGraphicsPixmapItem
{

public:
    DoorTimer(QVector<QVector<int>>& map,QGraphicsScene& scene, QGraphicsView& v);
    QVector<QVector<int>>* map;
    QGraphicsScene* scene;
    QGraphicsView * v;

//public slots:
void Open_door(QVector<QVector<int>>& map, QGraphicsPixmapItem boardItems[30][30]);
};

#endif // DOORTIMER_H
