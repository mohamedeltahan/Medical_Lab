#ifndef ALLTEST_H
#define ALLTEST_H

#include <QDialog>

namespace Ui {
class alltest;
}

class alltest : public QDialog
{
    Q_OBJECT

public:
    explicit alltest(QWidget *parent = 0);
    ~alltest();

private:
    Ui::alltest *ui;
};

#endif // ALLTEST_H
