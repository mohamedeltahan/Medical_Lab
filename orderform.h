#ifndef ORDERFORM_H
#define ORDERFORM_H

#include <QWidget>

namespace Ui {
class orderForm;
}

class orderForm : public QWidget
{
    Q_OBJECT

public:
    explicit orderForm(QWidget *parent = 0);
    ~orderForm();

private slots:
    void on_lineEdit_3_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::orderForm *ui;
};

#endif // ORDERFORM_H
