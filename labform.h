#ifndef LABFORM_H
#define LABFORM_H

#include <QWidget>


namespace Ui {
class labForm;
}

class labForm : public QWidget
{
    Q_OBJECT

public:
    explicit labForm(QWidget *parent = 0);
    ~labForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::labForm *ui;
};

#endif // LABFORM_H
