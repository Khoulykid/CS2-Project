
#include "form.h"
#include "ui_form.h"
#include <mainwindow.h>
#include "game.h"
#include <QGraphicsScene>
#include<QColorDialog>
#include <QGraphicsItem>
extern MainWindow *w;
extern game *g;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QPixmap bkgnd("Z:/CSPROJ/GameNew/gameover.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(this->width(),this->height());
    g->close();
}

Form::~Form()
{
    delete ui;
}

void Form::on_Start_clicked()
{
    w->show();
    delete g;
    g = new game;
    this->close();
    delete this;
}


void Form::on_Exit_clicked()
{
    delete w;
    delete g;
    this->close();
    delete this;
}

