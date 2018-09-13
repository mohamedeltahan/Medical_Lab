#include "logindialog.h"
#include "ui_logindialog.h"
#include "dialog.h"
#include <QString.h>

MedicalLab m;

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->lineEdit_2->setInputMethodHints(Qt::ImhHiddenText);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_buttonBox_accepted()
{ QSqlQuery q;
    bool b=q.exec("select name from labs_database.labs where  id="+QString::number(ui->lineEdit->text().toInt()) );
    q.first();
    if(!q.value(0).isNull()){


    m=datab->read_medicallab(ui->lineEdit->text().toInt(),ui->lineEdit_2->text());
    datab->db_name=q.value(0).toString();
    datab->db.setDatabaseName(datab->db_name);
    qDebug()<<datab->db_name;


    qDebug()<<datab->db.open();
    m.D=datab;

    Form * f= new Form();
      f->show();


    }
    else{this->destroy();}



}
