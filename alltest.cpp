#include "alltest.h"
#include "ui_alltest.h"
#include<logindialog.h>
#include<QTableWidgetItem>
#include<QStringList>
#include<QHeaderView>
#include<QScrollBar>
#include<Test.h>
void verticalResizeTableViewToContents(QTableView *tableView)
{
    int count=tableView->verticalHeader()->count();
    int scrollBarHeight=tableView->horizontalScrollBar()->height();
    int horizontalHeaderHeight=tableView->horizontalHeader()->height();
    int rowTotalHeight=0;
    for (int i = 0; i < count; ++i) {
        rowTotalHeight+=tableView->verticalHeader()->sectionSize(i);
    }
    tableView->setMinimumHeight(horizontalHeaderHeight+rowTotalHeight+scrollBarHeight);
}

alltest::alltest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alltest)
{
    ui->setupUi(this);
    vector<Test> v;

    vector<Patient> p=m.D->read_All_Patient();
    for(int i=0;i<p.size();i++){
        vector<Test> temp=m.D->read_test_for_patient(p.at(i).Id);
        v.insert( v.end(), temp.begin(), temp.end() );

    }
    for(int i=0;i<v.size();i++){
qDebug()<<v.at(i).Date;
    }

  QHeaderView* header = ui->tableWidget->horizontalHeader();
     header->setSectionResizeMode(QHeaderView::Stretch);
     QFont newFont("Courier", 35, QFont::Bold, true);
     ui->tableWidget->horizontalHeader()->setFont(newFont);
     ui->tableWidget->verticalHeader()->setFont(newFont);



  ui->tableWidget->setColumnCount(6);
  ui->tableWidget->setRowCount(v.size());

  QStringList l;
  l.append("Test_id");
  l.append("Type");
  l.append("Date");
  l.append("Patient_id");
  l.append("State");
  l.append("Path");
  ui->tableWidget->setHorizontalHeaderLabels(l);

  for(int i=0;i<v.size();i++){
      QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(v.at(i).Id),0);
          ui->tableWidget->setItem(i, 0, newItem);
       newItem = new QTableWidgetItem(v.at(i).type,0);

          ui->tableWidget->setItem(i, 1, newItem);
          newItem = new QTableWidgetItem(v.at(i).Date,0);

          ui->tableWidget->setItem(i, 2, newItem);
          newItem = new QTableWidgetItem(QString::number(v.at(i).p.Id),0);

          ui->tableWidget->setItem(i, 3, newItem);
          newItem = new QTableWidgetItem("false",0);

          ui->tableWidget->setItem(i, 4, newItem);
          newItem = new QTableWidgetItem(v.at(i).report,0);

          ui->tableWidget->setItem(i, 5, newItem);




  }
  ui->tableWidget->horizontalHeader()->setFixedHeight(80);
  ui->tableWidget->verticalHeader()->setFixedWidth(60);

  ui->tableWidget->verticalScrollBar()->setEnabled(true);


}

alltest::~alltest()
{
    delete ui;
}
