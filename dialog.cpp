#include "dialog.h"
#include "ui_dialog.h"
#include "qdebug.h"
#include <QString>
#include"mainwindow.h"
 DatabaseModel*datab;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
   QString h=ui->lineEdit->text();
   QString y=ui->lineEdit_2->text();
  datab=new DatabaseModel("QMYSQL",h,"","root","mohamed");
   if(datab->db.open()){
   MainWindow* m= new MainWindow();
   m->show();
   }
   qDebug()<<datab->connected;



}
