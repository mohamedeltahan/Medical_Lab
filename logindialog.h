#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include<form.h>
extern MedicalLab m;
namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
