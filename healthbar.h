#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include <QGraphicsTextItem>


class healthbar : public QGraphicsTextItem
{
    Q_OBJECT
private:
    int health;
public:
    healthbar();
public slots:
    void increment(int);
    void decrement(int);
    int gethp();
    void hprestart();
};

#endif // HEALTHBAR_H
