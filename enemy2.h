#ifndef ENEMY2_H
#define ENEMY2_H
#include"enemy1.h"
#include <stdio.h>
#include <QTime>
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"
#include "enemy2_weapon.h"

class enemy2: public enemy1
{
    Q_OBJECT
public:
    enemy2(int[11][61], int,int, int);
    ~enemy2();
public slots:
    void move();
    void shoot();
    void dmg();
};

#endif // ENEMY2_H
