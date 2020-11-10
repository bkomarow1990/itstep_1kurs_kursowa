#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextEdit>
#include <iostream>
#include <fstream>
#include "register.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // QPixmap bkgnd("images/1.png");
    //bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
   // QPalette palette;
    //palette.setBrush(QPalette::Background, bkgnd);
  //  this->setPalette(palette);
}
MainWindow::~MainWindow()
{
    delete ui;
}
QString getUserLogin(){
return "dd";
/* for(int i=1;i<logins_bd_size;i++){
     if(logins_bd[i-1]==login_text && logins_bd[i]==password_text){
         return login_text;
         break;
     }
 }
     return "Not correct login or password";
*/
 }
int getAcountsCount(){
    ifstream user_db("user_dbs.txt");
    string current;
    int count=0;
    while (!user_db.eof()) {
        getline(user_db,current);
        count++;
    }
    user_db.close();
    return count;
}
void getLogin(string&  login_text,string& password_text){
    ifstream user_db("user_dbs.txt");
    string current;
    string current_login;
    string current_password;
    int index_password;
    bool logined=false;
    int j=0;
  for(int i=0; i<getAcountsCount(); i++){
        j=0;
        current_login="";
        current_password="";
        getline(user_db, current);
        while(current[j]!=' '){
            current_login=current_login+current[j];
            j++;
            index_password=j;
        }
        index_password++;
        j=index_password;
        while (current[j]!='\0') {
            current_password=current_password+current[j];
            j++;
        }
        if(current_login==login_text && current_password==password_text){
            cout<<"YOU LOGINED AS "<<current_login<<endl;
            QMessageBox logined_msg(0);
            logined_msg.setText("YOU LOGINED ");
            logined_msg.setWindowTitle("LOGINED");
            logined_msg.setMinimumSize(800, 0);
            logined_msg.exec();
            logined=true;
            break;
        }
}
  if(logined==false){
      cout<<"Error"<<endl;
      QMessageBox incorrect_login(0);
         incorrect_login.setText("INCORRECT LOGIN OR PASSWORD");
         incorrect_login.setWindowTitle("Error");
         incorrect_login.setMinimumSize(800, 0);
         incorrect_login.exec();
  }
    user_db.close();
}
void MainWindow::on_login_button_clicked()
{
   QString Qlogin_text=ui->login_text->text();
   QString Qpassword_text=ui->password_text->text();
   string login_text=Qlogin_text.toStdString();
   string password_text=Qpassword_text.toStdString();
   getLogin(login_text,password_text);
/* char current;
int size=0;
do{
    user_db.get(current);
    cout<<current;
    size++;
}
while(current!=' ');
user_db.close(); */
/* const int logins_bd_size=10; // accounts array size

    QString logins_bd[logins_bd_size]={"admin","adminnelox","bogdan","secret","maks","12postawte_pz","illia","notgay","kursowa","oxy3nna"};
    QString login_text=ui->login_text->text();
    QString password_text=ui->password_text->text();
    QMessageBox::about(this, "Login ", "You are logined at "+getUserLogin(login_text,password_text,logins_bd,logins_bd_size));

*/
 }
void MainWindow::on_Register_button_clicked()
{
  Register register_window;
  register_window.setModal(true);
  register_window.exec();
}
