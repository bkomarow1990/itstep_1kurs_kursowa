#include "register.h"
#include "ui_register.h"
#include <QString>
#include <iostream>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <conio.h>
#include "mainwindow.h"
using namespace std;
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}
// illia pidor
int stringSize(string string){
    int i=0;
    while(true){
        if(string[i]!='\0'){
            i++;
        }
        else{
            break;
        }
    }
    return i;
}
void getRegister(string&  login_text,string& password_text){
    int correct=0;
    for (int i=0; i<stringSize(login_text);i++){
        if(login_text[i]!=' ' && login_text[i]!='!' && login_text[i]!=',' && stringSize(login_text)<20){
        correct++;
        }
        else{
            QMessageBox incorrect_login(0);
            incorrect_login.setText("ENTER CORRECT LOGIN ");
            incorrect_login.setWindowTitle("Error");
            incorrect_login.setMinimumSize(800, 0);
            incorrect_login.exec();
            break;
        }
    }
    for(int i=0;i<stringSize(password_text);i++){
        if(password_text[i]!=' ' && password_text[i]!='!' && password_text[i]!=',' && stringSize(password_text)>5){
            correct++;
        }
        else{
            QMessageBox incorrect_password(0);
            incorrect_password.setText("ENTER CORRECT PASSWORD ");
            incorrect_password.setWindowTitle("Error");
            incorrect_password.setMinimumSize(800, 0);
            incorrect_password.exec();
            break;
        }
    }
    if(correct == stringSize(login_text)+stringSize(password_text)){
        ofstream user_db("user_dbs.txt", ios_base::app);
        user_db<<endl<<login_text<<" ";
        user_db<<password_text;
        user_db.close();
        QMessageBox registred(0);
        registred.setText("Successfully Register");
        registred.setWindowTitle("Error");
        registred.setMinimumSize(800, 0);
        registred.exec();
    }
}
void Register::on_register_button_clicked()
{
    QString Qlogin_text=ui->login_text->text();
    QString Qpassword_text=ui->password_text->text();
    string login_text=Qlogin_text.toStdString();
    string password_text=Qpassword_text.toStdString();
    getRegister(login_text,password_text);
}

