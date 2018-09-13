#ifndef Patient_h
#define Patient_h

#include <QString>
using namespace std;



class Patient {

 public:
    Patient();
    Patient(int Id, QString Name, QString Phone, QString Address, QString Mail, int Age, QString Date, QString sex, QString Marital_status);

    static bool search_By_id(int Id);

    static bool search_by_phone(QString Phone);

 public:
    int Id;
    QString Name;
    QString Phone;
    QString Address;
    QString Mail;
    int Age;
    QString Date;
    QString Sex;
    QString Marital_status;
};

#endif // Patient_h
