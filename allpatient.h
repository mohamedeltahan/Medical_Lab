#ifndef ALLPATIENT_H
#define ALLPATIENT_H

#include <QWidget>

namespace Ui {
class allpatient;
}

class allpatient : public QWidget
{
    Q_OBJECT

public:
    explicit allpatient(QWidget *parent = 0);
    ~allpatient();

private:
    Ui::allpatient *ui;
};

#endif // ALLPATIENT_H
