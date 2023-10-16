#include "enemy1.h"
#include "player.h"
#include "game.h"
#include "form.h"

extern Form* f;
extern game *g;
extern QVector<enemy1*> botatos;

enemy1::enemy1(){
}
enemy1::enemy1(int dataitem[11][61], int r, int c , int n)
{
    srand(time(NULL));
    row=r;
    column=c;
    spawnrow = r;
    spawncol = c;
    number_enemy=n;
    QPixmap e1("Z:/CSPROJ/GameNew/enemy1.png");
    e1=e1.scaledToWidth(70);
    e1=e1.scaledToHeight(70);
    setPixmap(e1);
    setPos(70*column,70*row);
    for(int i=0;i<11;i++)
        for (int j=0;j<61;j++)
            data[i][j]=dataitem[i][j];
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1500);
    weapontimer = new QTimer(this);
    connect(weapontimer, SIGNAL(timeout()), this, SLOT(shoot()));
    weapontimer->start(1500);

}

void enemy1::move()
{
    if(!g->pause)
    {
        random = rand()%4;
        if(number_enemy==1)
        {
            if(random == 0 && data[row-1][column]>=12 && data[row-1][column]<42){
                row--;
                direction="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && data[row+1][column]>=12 && data[row+1][column]<42){
                row++;
                direction="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && data[row][column+1]>=12&& data[row][column+1] <42){
                column++;
                direction="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && data[row][column-1] >=12 && data[row][column-1] <42){
                column--;
                direction="left";
                setPos(70*column, 70*row);
                dmg();
            }

        }
        else if(number_enemy==2)
        {
            if(random == 0 && data[row-1][column]>=47 && data[row-1][column]<=78){
                row--;
                direction="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && data[row+1][column]>=47 && data[row+1][column]<=78){
                row++;
                direction="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && data[row][column+1]>=47&& data[row][column+1] <=78){
                column++;
                direction="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && data[row][column-1] >=47 && data[row][column-1] <=78){
                column--;
                direction="left";
                setPos(70*column, 70*row);
                dmg();
            }

        }
        else if(number_enemy==3)
        {
            if(random == 0 && data[row-1][column]>=6 && data[row-1][column]<=10){
                row--;
                direction="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && data[row+1][column]>=6 && data[row+1][column]<=10){
                row++;
                direction="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && data[row][column+1]>=6 && data[row][column+1] <=10){
                column++;
                direction="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && data[row][column-1] >=6 && data[row][column-1] <=10){
                column--;
                direction="left";
                setPos(70*column, 70*row);
                dmg();
            }

        }
        else if(number_enemy == 10)
        {
            if(random == 0 && data[row-1][column]>0 && data[row-1][column]>0){
                row--;
                direction="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && data[row+1][column]>0 && data[row+1][column]>0){
                row++;
                direction="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && data[row][column+1]>0 && data[row][column+1] >0){
                column++;
                direction="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && data[row][column-1] >0 && data[row][column-1] >0){
                column--;
                direction="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
        else
        {
            if(random == 0 && data[row-1][column]>=11 && data[row-1][column]<=22){
                row--;
                direction="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && data[row+1][column]>=11 && data[row+1][column]<=22){
                row++;
                direction="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && data[row][column+1]>=11 && data[row][column+1] <=22){
                column++;
                direction="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && data[row][column-1] >=11 && data[row][column-1] <=22){
                column--;
                direction="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
    }
}

void enemy1::shoot()
{
    if(!g->pause)
    {
        int random = rand()%2;
        if(random == 0){
            if(direction=="up"&&data[row-1][column]>=0){
                enemy1_weapon* eweap = new enemy1_weapon(data, row, column, direction);
                scene()->addItem(eweap);
            }
            else if(direction=="down"&&data[row+1][column]>=0){
                enemy1_weapon* eweap = new enemy1_weapon(data, row, column, direction);
                scene()->addItem(eweap);
            }
            else if(direction=="left"&&data[row][column-1]>=0){
                enemy1_weapon* eweap = new enemy1_weapon(data, row, column, direction);
                scene()->addItem(eweap);
            }
            else if(direction=="right"&&data[row][column+1]>=0){
                enemy1_weapon* eweap = new enemy1_weapon(data, row, column, direction);
                scene()->addItem(eweap);
            }
        }
    }
}

void enemy1::dmg()
{
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int j =0 , n =collidningitem.size(); j<n ; j++){
        if(typeid (*(collidningitem[j]))==typeid (player)){
            g->health->decrement(10);
            if(g->health->gethp()<=0 && !g->lost){
                g->lost=true;
                f = new Form;
                f->show();
                delete g->p;
                delete this;
                return;
            }
        }
    }
}

enemy1::~enemy1()
{
    if(number_enemy != 10)
        g->SPAWN[number_enemy-1] = false;
}
