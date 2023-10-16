#include "store.h"
#include "ui_store.h"
#include "game.h"
#include<QPalette>
#include <QDebug>
#include "mainwindow.h"

extern game *g;
extern MainWindow *w;

store::store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::store)
{
    ui->setupUi(this);
    QPixmap bkgnd("Z:/CSPROJ/GameNew/storebackground.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(this->width(),this->height());
    g->pause = true;
    g->hide();
    if(g->bought[0])
        ui->Character0->setText("Sold!");
    if(g->bought[1])
        ui->Character1->setText("Sold!");
    if(g->bought[2])
        ui->Character2->setText("Sold!");
    if(g->bought[3])
        ui->Character3->setText("Sold!");
    if(g->bought[4])
        ui->NewShuriken->setText("Sold!");
}

store::~store()
{
    delete ui;
}

void store::on_returns_clicked()
{
    g->pause = false;
    g->show();
    close();
    delete this;
}


void store::on_Character0_clicked()
{
    if(!(g->bought[0]) && (g->currency->getcoins() >= 25))
    {
        g->bought[0]=true;
        g->currency->decrement(25);
        ui->Character0->setText("Sold!");
    }
}



void store::on_Character1_clicked()
{
    if(!(g->bought[1]) && (g->currency->getcoins() >= 30))
    {
        g->bought[1]=true;
        g->currency->decrement(30);
        ui->Character1->setText("Sold!");
    }
}


void store::on_Character2_clicked()
{
    if(!(g->bought[2]) && (g->currency->getcoins() >= 40))
    {
        g->bought[2]=true;
        g->currency->decrement(40);
        ui->Character2->setText("Sold!");
    }
}


void store::on_Character3_clicked()
{
    if(!(g->bought[3]) && (g->currency->getcoins() >= 40))
    {
        g->bought[3]=true;
        g->currency->decrement(40);
        ui->Character3->setText("Sold!");
    }
}




void store::on_NewShuriken_clicked()
{
    if(!(g->bought[4]) && (g->currency->getcoins() >= 40))
    {
        g->bought[4]=true;
        g->currency->decrement(40);
        ui->NewShuriken->setText("Sold!");
    }
}


void store::on_Health_clicked()
{
    if(g->currency->getcoins() >=50)
    {
        g->currency->decrement(50);
        g->health->increment(50);
    }
}


void store::on_Character0equip_clicked()
{
    if(g->bought[0])
    {
        QPixmap p("Z:/CSPROJ/GameNew/Girl2char.png");
        p=p.scaledToWidth(65);
        p=p.scaledToHeight(65);
        g->p->setPixmap(p);
    }
}


void store::on_Character1equip_clicked()
{
    if(g->bought[1])
    {
        QPixmap p("Z:/CSPROJ/GameNew/narutochar.png");
        p=p.scaledToWidth(75);
        p=p.scaledToHeight(75);
        g->p->setPixmap(p);
    }
}


void store::on_Character2equip_clicked()
{
    if(g->bought[2])
    {
        QPixmap p("Z:/CSPROJ/GameNew/sasukechar.png");
        p=p.scaledToWidth(75);
        p=p.scaledToHeight(75);
        g->p->setPixmap(p);
    }
}


void store::on_Characterequip3_clicked()
{
    if(g->bought[3])
    {
        QPixmap p("Z:/CSPROJ/GameNew/sakurachar.png");
        p=p.scaledToWidth(75);
        p=p.scaledToHeight(75);
        g->p->setPixmap(p);
    }
}


void store::on_Exit_clicked()
{
    delete w;
    delete g;
    this->close();
    delete this;
}

