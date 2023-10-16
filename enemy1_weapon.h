#ifndef ENEMY1_WEAPON_H
#define ENEMY1_WEAPON_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>



class enemy1_weapon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[11][61];
    QTimer *timer;
    QString direction;
    bool stop;
    bool pass;
public:
    enemy1_weapon(int dataitem[11][61], int, int, QString);
public slots:
     void move();
     void dmg();

};

#endif // ENEMY1_WEAPON_H
