#include "coinbar.h"
#include <QString>
#include "game.h"

extern game* g;

coinbar::coinbar()
{
    coins = 0;
    setPlainText("Coins:\n" + QString::number(coins));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 14));
    setPos(0, 45);
}

void coinbar::increment(int add)
{
    coins += add;
    setPlainText("Coins:\n" + QString::number(coins));
}

void coinbar::decrement(int dec)
{
    coins -= dec;
    setPlainText("Coins:\n" + QString::number(coins));
}

int coinbar::getcoins()
{
    return coins;
}

void coinbar::coinbarrestart()
{
    coins = 0;
    setPlainText("Coins:\n" + QString::number(coins));
    setPos(0, 45);
}

