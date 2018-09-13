#include "Receptionist.h"

Receptionist::Receptionist(int id,QString name,QString phone,int salary,QString sex,int age,QString address):Staff( id, name, phone, salary, sex, age,  address){
    this->Id=id;
        this->Address=address;
        this->Age=age;
        this->Name=name;
        this->Phone=phone;
        this->Salary=salary;
        this->Sex=sex;



}
