#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "ui_form.h"
class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_Start_clicked();

    void on_Exit_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
