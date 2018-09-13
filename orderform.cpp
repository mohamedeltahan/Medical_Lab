#include "orderform.h"
#include "ui_orderform.h"
#include<qgraphicseffect.h>
#include<Patient.h>
#include"logindialog.h"
#include<QDate>
#include<QGraphicsOpacityEffect>
orderForm::orderForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderForm)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect* effect=new QGraphicsOpacityEffect(ui->graphicsView);
    effect->setOpacity(0.3);
    ui->graphicsView->setGraphicsEffect(effect);
    QString date=QDate::currentDate().toString("ddd MMMM d yy");
    ui->lineEdit_2->setText(date);
    QStringList qs;
    for(int i=0;i<m.deliver_doctors.size();i++){
        qs.append(m.deliver_doctors.at(i).Name);

    }
    ui->comboBox->addItems(qs);

}

orderForm::~orderForm()
{
    delete ui;
}

void orderForm::on_lineEdit_3_editingFinished()
{
    Patient p=m.read_patient_by_phone(ui->lineEdit_3->text());
    ui->lineEdit->setText(p.Address);
}

void orderForm::on_pushButton_clicked()
{   Patient p=m.read_patient_by_phone(ui->lineEdit_3->text());
    Test t= Test(p,ui->comboBox_2->currentText());
    vector<Test> v;
    v.push_back(t);
    Order o=Order(v,ui->lineEdit->text());
    o.Date=ui->lineEdit_2->text();
    o.deliver_doctor_id=m.D->get_delive_doctor_id(ui->comboBox->currentText());

    m.write_order(o);
    this->destroy();

}

void orderForm::on_pushButton_2_clicked()
{
    this->destroy();
}
