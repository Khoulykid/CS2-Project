#ifndef COINOBJECT_H
#define COINOBJECT_H

#include <QTimer>
#include "game.h"
#include <QGraphicsPixmapItem>

class coinobject : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    coinobject(int, int);
    ~coinobject();

private:
    QTimer* timer;

public slots:
    void disappear();

};

#endif // COINOBJECT_H
