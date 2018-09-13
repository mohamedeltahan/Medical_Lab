#include "staffform.h"
#include "ui_staffform.h"
#include <QGraphicsOpacityEffect>
#include<Staff.h>
#include<Doctor.h>
#include<Deliver_Doctor.h>
#include<Receptionist.h>
#include<logindialog.h>
staffForm::staffForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::staffForm)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(ui->graphicsView);
    effect->setOpacity(0.5);
    ui->graphicsView->setGraphicsEffect(effect);
}

staffForm::~staffForm()
{
    delete ui;
}

void staffForm::on_pushButton_clicked()
{
        QString radiobutton="female";
        if(ui->radioButton_2->isChecked()){radiobutton=ui->radioButton_2->text();}
        if(ui->radioButton_3->isChecked()){Doctor D=Doctor(100,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_4->text().toInt(),radiobutton,ui->lineEdit_5->text().toInt(),ui->lineEdit_3->text());
        m.Add_New_Doctor(D);
        this->destroy();
        }
        if(ui->radioButton_4->isChecked()){Deliver_Doctor D=Deliver_Doctor(100,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_4->text().toInt(),radiobutton,ui->lineEdit_5->text().toInt(),ui->lineEdit_3->text());
            m.Add_New_Deliver_Doctor(D);
            this->destroy();

        }
        if(ui->radioButton_5->isChecked()){Receptionist R=Receptionist(100,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_4->text().toInt(),radiobutton,ui->lineEdit_5->text().toInt(),ui->lineEdit_3->text());
            m.Add_New_Receptionist(R);
            this->destroy();

        }

}

void staffForm::on_pushButton_2_clicked()
{
    this->destroy();

}
