#ifndef STAFFFORM_H
#define STAFFFORM_H

#include <QWidget>

namespace Ui {
class staffForm;
}

class staffForm : public QWidget
{
    Q_OBJECT

public:
    explicit staffForm(QWidget *parent = 0);
    ~staffForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::staffForm *ui;
};

#endif // STAFFFORM_H
