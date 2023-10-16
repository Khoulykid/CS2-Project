#ifndef STORE_H
#define STORE_H

#include <QMainWindow>

namespace Ui {
class store;
}

class store : public QMainWindow
{
    Q_OBJECT

public:
    explicit store(QWidget *parent = nullptr);
    ~store();

private slots:
    void on_returns_clicked();

    void on_Character0_clicked();

    void on_Character1_clicked();

    void on_Character2_clicked();

    void on_Character3_clicked();

    void on_NewShuriken_clicked();

    void on_Health_clicked();

    void on_Character0equip_clicked();

    void on_Character1equip_clicked();

    void on_Character2equip_clicked();

    void on_Characterequip3_clicked();

    void on_Exit_clicked();

private:
    Ui::store *ui;

};

#endif // STORE_H
