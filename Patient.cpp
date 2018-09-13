#include "Patient.h"

Patient::Patient(){}


Patient::Patient(int Id, QString Name, QString Phone, QString Address, QString Mail, int Age, QString Date, QString sex, QString Marital_status)
{
    this->Id=Id;
    this->Name=Name;
    this->Phone=Phone;
    this->Address=Address;
    this->Mail=Mail;
    this->Age=Age;
    this->Date=Date;
    this->Sex=sex;
    this->Marital_status=Marital_status;

}

bool Patient::search_By_id(int Id)
{
    return false;
}

bool Patient::search_by_phone(QString Phone)
{
    return false;
}
