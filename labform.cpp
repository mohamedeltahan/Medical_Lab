#include "labform.h"
#include "ui_labform.h"
#include "dialog.h"
#include"MedicalLab.h"


labForm::labForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labForm)
{
    ui->setupUi(this);
}

labForm::~labForm()
{
    delete ui;
}

void labForm::on_pushButton_clicked()
{

  MedicalLab m(2015,ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit->text(),ui->lineEdit_4->text());
   datab->write_medicallab(m);
   this->destroy();

}
