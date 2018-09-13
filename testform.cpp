#include "testform.h"
#include "ui_testform.h"
#include <QGraphicsOpacityEffect>
#include "logindialog.h"
#include <QDate>
TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    QDate qd;
    QString date=qd.currentDate().toString("ddd MMMM d yy");
    qDebug()<<date;
    ui->setupUi(this);
    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(ui->graphicsView);
    effect->setOpacity(0.5);
    ui->graphicsView->setGraphicsEffect(effect);
    ui->lineEdit_3->setText(date);
    int z;
  QSqlQuery q;
  q.exec("SELECT max(id)  from lab1.tests");
   q.first();
   if(q.value(0).isNull()){z=0;}
else { z =q.value(0).toInt()+1;}
      ui->lineEdit->setText(QString::number(z));
      ui->lineEdit_5->setText("under_review");
      ui->lineEdit_6->setText("C:/Users/Desktop");




}

TestForm::~TestForm()
{
    delete ui;
}

void TestForm::on_pushButton_clicked()
{
   Patient p= m.read_patient_by_phone(ui->lineEdit_4->text());
   Test t(p,ui->comboBox->currentText());
   t.Date=ui->lineEdit_3->text();
   t.Id=ui->lineEdit->text().toInt();
   t.set_State(false);
   t.report="C:/Users/Desktop";

   m.Add_New_test(t);
   this->destroy();


}

void TestForm::on_pushButton_2_clicked()
{
this->destroy();

}
