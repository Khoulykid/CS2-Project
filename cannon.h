#ifndef CANNON_H
#define CANNON_H
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
#include"bullet.h"

class cannon: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[11][61];
    int number_cannon;
    QTimer *weapontimer;
public:
    cannon(int[11][61], int,int,int);
public slots:
    void shoot();
};

#endif // CANNON_H
