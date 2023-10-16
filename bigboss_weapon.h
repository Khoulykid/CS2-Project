#ifndef BIGBOSS_WEAPON_H
#define BIGBOSS_WEAPON_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>

class bigboss_weapon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[11][61];
    bool stop;
    QTimer *timer;
    QString direction;
public:
    bigboss_weapon(int dataitem[11][61], int, int, QString);
public slots:
    void move();
    void dmg();
};

#endif // BIGBOSS_WEAPON_H
