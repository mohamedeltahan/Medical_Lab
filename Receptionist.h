#ifndef Receptionist_h
#define Receptionist_h

#include "Staff.h"


class Receptionist : public Staff {

public:
    Receptionist();
    Receptionist(int id,QString name,QString phone,int salary,QString sex,int age, QString address);

};

#endif // Receptionist_h
