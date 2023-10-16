#include "healthbar.h"
#include <QString>
#include "game.h"
extern game* g;

healthbar::healthbar()
{
    health = 100;
    setPlainText("Health:\n" + QString::number(health));
    setDefaultTextColor(Qt::magenta);
    setFont(QFont("times", 14));
}

void healthbar::decrement(int decrease)
{
    health -= decrease;
    setPlainText("Health:\n" + QString::number(health));
}

void healthbar::increment(int add)
{
    health +=add;
    setPlainText("Health:\n" + QString::number(health));
}

int healthbar::gethp()
{
    return health;
}

void healthbar::hprestart()
{
    health = 100;
    setPlainText("Health:\n" + QString::number(health));
}
