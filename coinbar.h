#ifndef COINBAR_H
#define COINBAR_H
#include <QGraphicsTextItem>


class coinbar : public QGraphicsTextItem
{
    Q_OBJECT
private:
    int coins;
public:
    coinbar();
public slots:
    void increment(int);
    void decrement(int);
    int getcoins();
    void coinbarrestart();
};




#endif
