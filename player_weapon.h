#ifndef PLAYER_WEAPON_H
#define PLAYER_WEAPON_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "enemy1.h"
#include "enemy2.h"

class player_weapon:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int row;
    int column;
    int data[11][61];
    int count = 2;
    QTimer *timer;
    QString direction;
    bool stop;

public:
    player_weapon(int dataitem[11][61],int, int, QString);
    ~player_weapon();
    int getcol();
    int getrow();
    void setrow(int);
    void setcol(int);
    void setplace(int, int);
    QString getdirection();

public slots:
    void move();
    bool getstop();
    void spawncoins();

};

#endif // PLAYER_WEAPON_H
