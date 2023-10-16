#include "coinobject.h"
#include "game.h"
#include "player.h"

extern game* g;

coinobject::coinobject(int row, int column)
{
    QPixmap pic("Z:/CSPROJ/GameNew/coin.png");
    pic = pic.scaledToWidth(50);
    pic = pic.scaledToHeight(50);
    setPixmap(pic);
    setPos(70*column+10, 70*row+10);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(disappear()));
    timer->start(15000);
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++){
        if(typeid (*(collidningitem[i]))==typeid (player))
        {
            g->currency->increment(50);
            scene()->removeItem(this);
            delete this;
        }
    }
}

void coinobject::disappear()
{
    delete this;
}

coinobject::~coinobject()
{
    delete timer;
}
