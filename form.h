#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <testform.h>
#include <patientform.h>
#include <staffform.h>
#include <orderform.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
