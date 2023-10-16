#ifndef ENEMY2_WEAPON_H
#define ENEMY2_WEAPON_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>

class enemy2_weapon : public QObject, public QGraphicsPixmapItem
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
    int number_weapon;
public:
    enemy2_weapon(int dataitem[11][61], int, int, QString,int);
public slots:
    void move();
    void dmg();
};

#endif // ENEMY2_WEAPON_H
