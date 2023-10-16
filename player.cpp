#include "player.h"
#include "game.h"
#include "form.h"
#include "bigboss_weapon.h"
#include "coinobject.h"

extern game *g;
extern Form *f;

player::player(int dataitem [11][61], bool g )
{
    gender=g;
    space=false;
    direction = "right";
    row=5;
    column=0;
    if(gender){
            QPixmap p("Z:/CSPROJ/GameNew/girl.png");
            p=p.scaledToWidth(75);
            p=p.scaledToHeight(75);
            setPixmap(p);
            setPos(70*column+15,70*row+10);
        }
        else{
            QPixmap p("Z:/CSPROJ/GameNew/Potatochar.png");
            p=p.scaledToWidth(85);
            p=p.scaledToHeight(85);
            setPixmap(p);
            setPos(70*column,70*row);
        }
    for(int i=0;i<11;i++)
        for (int j=0;j<61;j++)
            data[i][j]=dataitem[i][j];

}

void player::move(QKeyEvent* event )
{
    if((event->key()==Qt::Key_Up)&&(data[row-1][column]>0))
    {
        row--;
        if(gender)
            setPos(70*column+15,70*row+10);
    }
    else if((event->key()==Qt::Key_Down)&&(data[row+1][column]>0))
    {
        row++;
        if(gender)
            setPos(70*column+15,70*row+10);
    }

    else if(event->key()==Qt::Key_Left&&(data[row][column-1]>0 || data[row][column-1]==-91))
    {
        column--;
        if(gender)
            setPos(70*column+15,70*row+10);
    }
    else if(event->key()==Qt::Key_Right&&(data[row][column+1]>0 ||data[row][column+1]==-91))
    {
        column++;
        if(gender)
            setPos(70*column+15,70*row+10);
    }
    else if((event->key()==Qt::Key_Right)&&((data[row][column+1]==-92 && g->counter>=2)||(data[row][column+1]==-93&&g->counter>=4)||(data[row][column+1]==-94&&g->counter>=8))){
        column++;
        if(gender)
            setPos(70*column+15,70*row+10);
    }
    else if(event->key()==Qt::Key_Left&&((data[row][column-1]==-92&&g->counter>=2)||(data[row][column-1]==-93&&g->counter>=4)||(data[row][column-1]==-94&&g->counter>=8)))
    {
        column--;
        if(gender)
            setPos(70*column+15,70*row+10);
    }
    if(!gender)
            setPos(70*column,70*row);

    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++)
    {
        if(typeid (*(collidningitem[i]))==typeid (enemy1) || typeid (*(collidningitem[i]))==typeid (enemy1_weapon)){
            g->health->decrement(10);
        }
        else if( typeid (*(collidningitem[i]))==typeid (enemy2)|| typeid (*(collidningitem[i]))==typeid (enemy2_weapon)){
            g->health->decrement(20);
        }
        else if(typeid (*(collidningitem[i]))==typeid (BigBoss) || typeid (*(collidningitem[i]))==typeid (bigboss_weapon))
        {
            g->health->decrement(30);
        }
        else if(typeid (*(collidningitem[i]))==typeid (coinobject))
        {
            g->currency->increment(10);
            scene()->removeItem(collidningitem[i]);
            delete collidningitem[i];
        }
        if(typeid (*(collidningitem[i]))==typeid (enemy2_weapon) || typeid (*(collidningitem[i]))==typeid (enemy1_weapon) || typeid (*(collidningitem[i]))==typeid (bigboss_weapon)){
            scene()->removeItem(collidningitem[i]);
            delete collidningitem[i];
        }
        if(g->health->gethp()<=0)
        {
            g->lost=true;
            f = new Form;
            f->show();
            delete this;
            return;
        }
    }
}

int player::getRow(){
    return row;
}

int player::getCol(){
    return column;
}

QString player::getDirection(){
    return direction;
}

void player::setDir(QString x)
{
    direction = x;
}
