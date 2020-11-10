#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <iostream>
// #include "mainwindow.h"
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_register_button_clicked();

    void on_mainMenu_button_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
