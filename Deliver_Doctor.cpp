#include "Deliver_Doctor.h"





Deliver_Doctor::Deliver_Doctor(int id,QString name,QString phone,int salary,QString sex,int age, QString address):Staff( id, name, phone, salary, sex, age,  address){

this->Id=id;
    this->Address=address;
    this->Age=age;
    this->Name=name;
    this->Phone=phone;
    this->Salary=salary;
    this->Sex=sex;


}
void Deliver_Doctor::assign_order(Order o){
    Holding_orders.push_back(o);


}
Order Deliver_Doctor::recieve_order(){
    Order temp=(*Holding_orders.begin());
    Holding_orders.erase(Holding_orders.erase(Holding_orders.begin()));
    return temp;


}
Deliver_Doctor::~Deliver_Doctor(){




}
