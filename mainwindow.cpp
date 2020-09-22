#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
QString getUserLogin(QString login_text,QString password_text,QString logins_bd[],const int logins_bd_size){
for(int i=1;i<logins_bd_size;i++){
     if(logins_bd[i-1]==login_text && logins_bd[i]==password_text){
         return login_text;
         break;
     }
 }
     return "Not correct login or password";

}
void MainWindow::on_login_button_clicked()
{
    const int logins_bd_size=10; // accounts array size

    QString logins_bd[logins_bd_size]={"admin","adminnelox","bogdan","secret","maks","12postawte_pz","illia","notgay","kursowa","oxy3nna"};
    QString login_text=ui->login_text->text();
    QString password_text=ui->password_text->text();
    QMessageBox::about(this, "Login ", "You are logined at "+getUserLogin(login_text,password_text,logins_bd,logins_bd_size));
}
