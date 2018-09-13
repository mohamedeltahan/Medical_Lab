#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "labform.h"
#include "form.h"
#include <logindialog.h>
#include <QGraphicsOpacityEffect>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // this->setFixedSize(1366,);
   // ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground);
    ui->graphicsView->setAttribute(Qt::WA_StyledBackground);
    QGraphicsOpacityEffect* g= new QGraphicsOpacityEffect(ui->graphicsView);
    g->setOpacity(0.3);
    ui->graphicsView->setGraphicsEffect(g);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ labForm* l= new labForm();
    l->show();

}

void MainWindow::on_pushButton_2_clicked()
{     loginDialog* l=new loginDialog();
      l->exec();



}
