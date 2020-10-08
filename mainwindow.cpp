#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextEdit>
#include <iostream>
#include <fstream>
using namespace std;
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

QString getUserLogin(){

/* for(int i=1;i<logins_bd_size;i++){
     if(logins_bd[i-1]==login_text && logins_bd[i]==password_text){
         return login_text;
         break;
     }
 }
     return "Not correct login or password";
*/
 }
void MainWindow::on_login_button_clicked()
{
const string user_db_path="user_db.txt";
ifstream user_db;
user_db.open("F:\\itstep\\1 Course\\Programming\\Kursowa\\itstep_1kurs_kursowa\\user_db.txt");
char current;
int size=0;
do{
    user_db.get(current);
    cout<<current;
    size++;
}
while(current!=' ');
user_db.close();
/* const int logins_bd_size=10; // accounts array size

    QString logins_bd[logins_bd_size]={"admin","adminnelox","bogdan","secret","maks","12postawte_pz","illia","notgay","kursowa","oxy3nna"};
    QString login_text=ui->login_text->text();
    QString password_text=ui->password_text->text();
    QMessageBox::about(this, "Login ", "You are logined at "+getUserLogin(login_text,password_text,logins_bd,logins_bd_size));

*/
 }
