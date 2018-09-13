#include "Doctor.h"


Doctor::Doctor(int id,QString name,QString phone,int salary,QString sex,int age, QString address) :Staff( id, name, phone, salary, sex, age,  address)
{
   this->Id=id;
    this->Name=name;
    this->Phone=phone;
    this->Salary=salary;
    this->Sex=sex;
    this->Age=age;
    this->Address=address;


}

bool Doctor::Set_Test_State(int Test_id)
{
    return false;
}
