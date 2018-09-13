#include "form.h"
#include "ui_form.h"
#include <qgraphicseffect.h>
#include <alltest.h>
#include<allpatient.h>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(ui->graphicsView_5);
    effect->setOpacity(0.5);
    ui->graphicsView_5->setGraphicsEffect(effect);





}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{   TestForm* t =new TestForm();
    t->show();


}

void Form::on_pushButton_2_clicked()
{
    patientForm* p=new patientForm();
    p->show();
}

void Form::on_pushButton_3_clicked()
{
    orderForm* o= new orderForm();
    o->show();
}


void Form::on_pushButton_4_clicked()
{
    staffForm* s=new staffForm();
    s->show();


}

void Form::on_pushButton_6_clicked()
{
  alltest *a=new alltest();
  a->show();

}

void Form::on_pushButton_5_clicked()
{
    allpatient *a=new allpatient();
    a->show();



}
