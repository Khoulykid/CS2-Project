#include "game.h"
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <mainwindow.h>
#include "store.h"

extern QVector<enemy1*> botatos;
extern MainWindow *w;
extern store* s;

game::game()
{
    pause = false;
    for(int i = 0; i<5; i++)
        bought[i] = false;
    sound=new QMediaPlayer;
    audio=new QAudioOutput;
    sound->setAudioOutput(audio);
    sound->setSource(QUrl::fromLocalFile("Z:/CSPROJ/GameNew/hiyaaa.mp3"));
    audio->setVolume(50);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(910,770);
    setWindowTitle("SAN");
    counter = 0;
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,910,770);
    setScene(scene);
    lost=false;
    w=new MainWindow;
    QBrush brush(Qt::black);
    setBackgroundBrush(brush);
    QString temp;
    QFile file("Z:/CSPROJ/GameNew/Board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    for (int i=0;i<11;i++)
        for (int j=0;j<61;j++)
        {
         stream>>temp;
         boarddata[i][j]=temp.toInt();
        }
    QPixmap floor("Z:/CSPROJ/GameNew/floor1.png");
    QPixmap brick("Z:/CSPROJ/GameNew/blackbrick.png");
    QPixmap floor1("Z:/CSPROJ/GameNew/floor2.jpg");
    QPixmap floor2("Z:/CSPROJ/GameNew/shells.jpg");
    QPixmap door1("Z:/CSPROJ/GameNew/door1.png");
    QPixmap door2("Z:/CSPROJ/GameNew/door2.png");
    QPixmap door3("Z:/CSPROJ/GameNew/door3.png");
    QPixmap door4("Z:/CSPROJ/GameNew/door4.jpg");
    QPixmap lastfloor("Z:/CSPROJ/GameNew/tfloor.jpg");
    QPixmap tree("Z:/CSPROJ/GameNew/tree.png");
    floor=floor.scaledToWidth(70);
    floor=floor.scaledToHeight(70);
    floor2=floor2.scaledToWidth(70);
    floor2=floor2.scaledToHeight(70);
    brick=brick.scaledToWidth(70);
    brick=brick.scaledToHeight(70);
    floor1=floor1.scaledToWidth(70);
    floor1=floor1.scaledToHeight(70);
    door1=door1.scaledToWidth(70);
    door1=door1.scaledToHeight(70);
    door2=door2.scaledToWidth(70);
    door2=door2.scaledToHeight(70);
    door3=door3.scaledToWidth(70);
    door3=door3.scaledToHeight(70);
    door4=door4.scaledToWidth(70);
    door4=door4.scaledToHeight(70);
    lastfloor=lastfloor.scaledToHeight(70);
    lastfloor=lastfloor.scaledToWidth(70);
    tree=tree.scaledToWidth(70);
    tree=tree.scaledToHeight(70);
    for (int i=0;i<11;i++)
            for (int j=0;j<23;j++)
            {
                if(boarddata[i][j]==-2 || boarddata[i][j]==-1||boarddata[i][j]==-5||boarddata[i][j]==-4)
                    dataimage[i][j].setPixmap(brick);
                else if(boarddata[i][j]==-91 )
                     dataimage[i][j].setPixmap(door1);
                else if(boarddata[i][j]==-92 )
                     dataimage[i][j].setPixmap(door2);
                else if(boarddata[i][j]==-93 )
                     dataimage[i][j].setPixmap(door3);
                else
                    dataimage[i][j].setPixmap(floor);
                dataimage[i][j].setPos(70*j,70*i);
                scene->addItem(&dataimage[i][j]);
           }
        for (int i=0;i<11;i++){
            for (int j=23;j<36;j++)
                {
                if(boarddata[i][j]==-2 || boarddata[i][j]==-1 ||boarddata[i][j]==-4 ||boarddata[i][j]==-5)
                    dataimage[i][j].setPixmap(brick);
                else if(boarddata[i][j]==-92 )
                     dataimage[i][j].setPixmap(door2);
                else if(boarddata[i][j]==-93 )
                    dataimage[i][j].setPixmap(door3);
                else if(boarddata[i][j]==-94 )
                   dataimage[i][j].setPixmap(door4);
                else if(boarddata[i][j]==-91 )
                    dataimage[i][j].setPixmap(door1);
                else
                    dataimage[i][j].setPixmap(lastfloor);
                dataimage[i][j].setPos(70*j,70*i);
                scene->addItem(&dataimage[i][j]);
            }
        }
        for (int i=0;i<11;i++){
            for (int j=36;j<48;j++)
            {
                if(boarddata[i][j]==-2 || boarddata[i][j]==-1 ||boarddata[i][j]==-4 ||boarddata[i][j]==-5)
                    dataimage[i][j].setPixmap(brick);
                else if(boarddata[i][j]==-92 )
                    dataimage[i][j].setPixmap(door2);
                else if(boarddata[i][j]==-93 )
                    dataimage[i][j].setPixmap(door3);
                else if(boarddata[i][j]==-94 )
                   dataimage[i][j].setPixmap(door4);
                else if(boarddata[i][j]==-91 )
                    dataimage[i][j].setPixmap(door1);
                else
                    dataimage[i][j].setPixmap(floor1);
                dataimage[i][j].setPos(70*j,70*i);
                scene->addItem(&dataimage[i][j]);
            }
        }

        for (int i=0;i<11;i++){
            for (int j=48;j<61;j++)
            {
                if(boarddata[i][j]==-2 || boarddata[i][j]==-1 ||boarddata[i][j]==-4 ||boarddata[i][j]==-5)
                    dataimage[i][j].setPixmap(brick);
                else if(boarddata[i][j]==-92 )
                    dataimage[i][j].setPixmap(door2);
                else if(boarddata[i][j]==-93 )
                    dataimage[i][j].setPixmap(door3);
                else if(boarddata[i][j]==-94 )
                    dataimage[i][j].setPixmap(door4);
                else if(boarddata[i][j]==-91 )
                    dataimage[i][j].setPixmap(door1);
                else if(boarddata[i][j]==-06 )
                    dataimage[i][j].setPixmap(tree);
                else
                    dataimage[i][j].setPixmap(floor2);
                dataimage[i][j].setPos(70*j,70*i);
                scene->addItem(&dataimage[i][j]);
            }
        }
    p=new player (boarddata, false);
    scene->addItem(p);
    e1=new enemy1(boarddata,4,19,1);
    scene->addItem(e1);
    e2=new enemy1(boarddata,9,19,2);
    scene->addItem(e2);
    e3=new enemy2(boarddata,9,25,1);
    scene->addItem(e3);
    e4=new enemy2(boarddata,9,33,2);
    scene->addItem(e4);
    e5=new enemy1(boarddata,5,40,3);
    scene->addItem(e5);
    e6=new enemy1(boarddata,9,38,4);
    scene->addItem(e6);
    e7=new enemy2(boarddata,3,45,3);
    scene->addItem(e7);
    e8=new enemy2(boarddata,9,46,4);
    scene->addItem(e8);
    boss=new BigBoss(boarddata,5,54);
    scene->addItem(boss);
    health = new healthbar;
    scene->addItem(health);
    currency = new coinbar;
    scene->addItem(currency);
    c1=new cannon(boarddata,2,50,1);
    scene->addItem(c1);
    c2=new cannon(boarddata,2,57,2);
    scene->addItem(c2);
    c3=new cannon(boarddata,8,50,1);
    scene->addItem(c3);
    c4=new cannon(boarddata,8,57,2);
    scene->addItem(c4);
    setScene(scene);
    prv = boarddata[p->getRow()][p->getCol()];
    for(int  i = 0; i<9; i++)
        SPAWN[i] = true;
}

void game::keyPressEvent(QKeyEvent*event){
    if(event->key()==Qt::Key_Up||event->key()==Qt::Key_Down){
        p->move(event);
    }
    else if(event->key()==Qt::Key_Right){
        p->move(event);
        if(boarddata[p->getRow()][p->getCol()]==-91){
            scene->setSceneRect(770,0,width(),height());
            health->setPos(770, 0);
            currency->setPos(770, 45);
        }

        else if(boarddata[p->getRow()][p->getCol()]==-92){
            scene->setSceneRect(1610,0,width(),height());
            health->setPos(1610, 0);
            currency->setPos(1610, 45);
        }

        else if(boarddata[p->getRow()][p->getCol()]==-93){
            scene->setSceneRect(2450,0,width(),height());
            health->setPos(2450, 0);
            currency->setPos(2450, 45);
        }

        else if(boarddata[p->getRow()][p->getCol()]==-94){
            scene->setSceneRect(3290,0,width(),height());
            health->setPos(3290, 0);
            currency->setPos(3290, 45);
            boss->timer->start(800);
            boss->weapontimer->start(1200);
            boss->gethardertimer->start(15000);
        }
        prv = boarddata[p->getRow()][p->getCol()];
    }
    else if(event->key()==Qt::Key_Left){
        p->move(event);
        if(boarddata[p->getRow()][p->getCol()]==404){
            scene->setSceneRect(0,0,910,height());
            health->setPos(0, 0);
            currency->setPos(0, 45);
        }
        else if(boarddata[p->getRow()][p->getCol()]==46){
            scene->setSceneRect(770,0,910,height());
            health->setPos(770, 0);
            currency->setPos(770, 45);
        }
        else if(boarddata[p->getRow()][p->getCol()]==403){
            scene->setSceneRect(1610,0,width(),height());
            health->setPos(1610, 0);
            currency->setPos(1610, 45);
        }
        else if(boarddata[p->getRow()][p->getCol()]==1){
            scene->setSceneRect(2450,0,width(),height());
            health->setPos(2450, 0);
            currency->setPos(2450, 45);
        }

        prv = boarddata[p->getRow()][p->getCol()];
    }
    else if(event->key()==Qt::Key_W)
    {
        p->setDir("up");
    }
    else if(event->key()==Qt::Key_S)
    {
        p->setDir("down");
    }
    else if(event->key()==Qt::Key_D)
    {
        p->setDir("right");
    }
    else if(event->key()==Qt::Key_A)
    {
        p->setDir("left");
    }
    else if(event->key()==Qt::Key_Space)
    {
        player_weapon *pw = new player_weapon(boarddata , p->getRow() , p->getCol(), p->getDirection());
        scene->addItem(pw);
        sound->play();
    }
    else if(event->key()==Qt::Key_Shift)
    {
        pause = true;
        s = new store;
        s->show();

    }
}

game::~game(){
//    gamestart();
//    delete e1;
//    delete e2;
//    delete e3;
//    delete e4;
//    delete e5;
//    delete e6;
//    delete e7;
//    delete e8;
//    delete boss;
//    delete p;
//    delete c1;
//    delete c2;
//    delete c3;
//    delete c4;
}

void game::deleteall()
{
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;
    delete e7;
    delete e8;
    delete boss;
    delete p;
    delete c1;
    delete c2;
    delete c3;
    delete c4;
}

void game::gamestart()
{
    botatos.clear();
    scene->setSceneRect(0,0,910,770);
    counter = 0;
    health->setPos(0, 0);
    lost = false;
    p=new player (boarddata,w->gender);
    scene->addItem(p);
    if(!SPAWN[0]){
        e1=new enemy1(boarddata,4,19,1);
        scene->addItem(e1);
    }
    if(!SPAWN[1]){
        e2=new enemy1(boarddata,9,19,2);
        scene->addItem(e2);
    }
    if(!SPAWN[4]){
        e3=new enemy2(boarddata,9,25,1);
        scene->addItem(e3);
    }
    if(!SPAWN[5]){
        e4=new enemy2(boarddata,9,33,2);
        scene->addItem(e4);
    }
    if(!SPAWN[2]){
        e5=new enemy1(boarddata,5,40,3);
        scene->addItem(e5);
    }
    if(!SPAWN[3]){
        e6=new enemy1(boarddata,9,38,4);
        scene->addItem(e6);
    }
    if(!SPAWN[6]){
        e7=new enemy2(boarddata,3,45,5);
        scene->addItem(e7);
    }
    if(!SPAWN[7]){
        e8=new enemy2(boarddata,9,46,6);
        scene->addItem(e8);
    }
    if(!SPAWN[8]){
        boss=new BigBoss(boarddata,5,54);
        scene->addItem(boss);
    }
    for(int i=0; i<8; i++)
        SPAWN[i] = true;
    for(int i = 0; i<5; i++)
        bought[i] = false;
    c1=new cannon(boarddata,2,50,1);
    scene->addItem(c1);
    c2=new cannon(boarddata,2,57,2);
    scene->addItem(c2);
    c3=new cannon(boarddata,8,50,1);
    scene->addItem(c3);
    c4=new cannon(boarddata,8,57,2);
    scene->addItem(c4);
    health->hprestart();
    currency->coinbarrestart();
    prv = boarddata[p->getRow()][p->getCol()];
}
