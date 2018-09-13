#include "patientform.h"
#include "ui_patientform.h"
#include <QGraphicsOpacityEffect>
#include<QDate>

patientForm::patientForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientForm)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(ui->graphicsView);
    effect->setOpacity(0.5);
    ui->graphicsView->setGraphicsEffect(effect);
    QString date=QDate::currentDate().toString("ddd MMMM d yy");
    ui->lineEdit_6->setText(date);

}

patientForm::~patientForm()
{
    delete ui;
}

void patientForm::on_pushButton_clicked()
{    QString radiobutton="female";
     if(ui->radioButton->isChecked()){radiobutton=ui->radioButton->text();}

     Patient p= m.Add_New_Patient(100,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text().toInt() , ui->lineEdit_6->text(),radiobutton,ui->comboBox->currentText());
      if(p.Id!=0){this->destroy();}
}

void patientForm::on_pushButton_2_clicked()
{
    this->destroy();
}
