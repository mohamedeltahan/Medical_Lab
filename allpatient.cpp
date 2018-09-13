#include "allpatient.h"
#include "ui_allpatient.h"
#include<Patient.h>
#include<logindialog.h>
#include<QTableWidgetItem>
#include<QStringList>
#include<QHeaderView>
#include<QScrollBar>

allpatient::allpatient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allpatient)
{
    ui->setupUi(this);
    vector<Patient> v=m.D->read_All_Patient();
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    ui->tableWidget->setColumnWidth(4,10);

       header->setSectionResizeMode(QHeaderView::Stretch);
       QFont newFont("Courier", 12, QFont::Bold, true);
       ui->tableWidget->horizontalHeader()->setFont(newFont);
       ui->tableWidget->verticalHeader()->setFont(newFont);




    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(v.size());

    QStringList l;
    l.append("patient_id");
    l.append("Name");
    l.append("phone");
    l.append("address");
    l.append("mail");
    l.append("age");
    l.append("date");
    l.append("sex");
    l.append("marital_status");


    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(int i=0;i<v.size();i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(v.at(i).Id),0);

            ui->tableWidget->setItem(i, 0, newItem);
            newItem = new QTableWidgetItem(v.at(i).Name,0);

            ui->tableWidget->setItem(i, 1, newItem);
            newItem = new QTableWidgetItem(v.at(i).Phone,0);

            ui->tableWidget->setItem(i, 2, newItem);
            newItem = new QTableWidgetItem(v.at(i).Address,0);

            ui->tableWidget->setItem(i, 3, newItem);
            newItem = new QTableWidgetItem(v.at(i).Mail,0);

            ui->tableWidget->setItem(i, 4, newItem);

            newItem = new QTableWidgetItem(QString::number(v.at(i).Age),0);

            ui->tableWidget->setItem(i, 5, newItem);
            newItem = new QTableWidgetItem(v.at(i).Date,0);

            ui->tableWidget->setItem(i, 6, newItem);
            newItem = new QTableWidgetItem(v.at(i).Sex,0);

            ui->tableWidget->setItem(i, 7, newItem);
            newItem = new QTableWidgetItem(v.at(i).Marital_status,0);

            ui->tableWidget->setItem(i, 8, newItem);




    }
    ui->tableWidget->verticalScrollBar()->setEnabled(true);

}

allpatient::~allpatient()
{
    delete ui;
}
