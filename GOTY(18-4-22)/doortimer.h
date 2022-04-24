#ifndef DOORTIMER_H
#define DOORTIMER_H

#include <QObject>
#include <QTimer>
#include "enemy.h"
class DoorTimer: public QObject
{
public:
    DoorTimer(QVector<QVector<int>>& map,QGraphicsScene& scene);
    QVector<QVector<int>>* map;
    QGraphicsScene* scene;
public slots:
void Open_door(QVector<QVector<int>>& map);
};

#endif // DOORTIMER_H
