#ifndef Staff_h
#define Staff_h
#include <QString>
using namespace std;


class Staff {

 public:
    int Id;
    QString Name;
    QString Phone;
    int Salary;
    QString Sex;
    int Age;
    QString Address;
public:
    Staff();
    Staff(int id,QString name,QString phone,int salary,QString sex,int age, QString address);
};

#endif // Staff_h
