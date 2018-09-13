#ifndef PATIENTFORM_H
#define PATIENTFORM_H

#include <QWidget>
#include <Patient.h>
#include <dialog.h>
#include <logindialog.h>

namespace Ui {
class patientForm;
}

class patientForm : public QWidget
{
    Q_OBJECT

public:
    explicit patientForm(QWidget *parent = 0);
    ~patientForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::patientForm *ui;
};

#endif // PATIENTFORM_H
