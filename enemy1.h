#ifndef ENEMY1_H
#define ENEMY1_H
#include <stdlib.h>
#include <time.h>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <QCoreApplication>
#include <QTimer>
#include<QDebug>
#include "enemy1_weapon.h"


class enemy1: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    int random;
    int row;
    int column;
    int data[11][61];
    int spawnrow;
    int spawncol;
    int number_enemy;
    QString direction;
    QTimer *timer, *weapontimer;
public:
    enemy1();
    enemy1(int[11][61], int,int,int);
    ~enemy1();
public slots:
    virtual void move();
    virtual void shoot();
    virtual void dmg();
};


#endif // ENEMY1_H
