#include "MedicalLab.h"
#include"databasemodel.h"



MedicalLab::MedicalLab(int Id, QString Name, QString Phone, QString Address,QString pass)
{
    this->Name=Name;
    this->Id=Id;
    this->Password=pass;
    this->Phone=Phone;
    this->Address=Address;
    //doctors=D->read_All_doctor();
    deliver_doctors=D->read_All_Deliver_doctor();

}

void MedicalLab::receive_order_from_DD(Deliver_Doctor d){
    D->write_order(d.recieve_order());

}


bool MedicalLab::search_lab_By_name(QString Name)
{
    return false;
}

bool MedicalLab::search_by_phone(QString phone)
{  Patient p=D->read_patient_by_phone(phone);
    if(p.Name!=""){return true;}
    return false;
}

 MedicalLab MedicalLab::login(int Id, QString Password)
{

    MedicalLab m=D->read_medicallab(Id,Password);

    return m;

}

Patient MedicalLab::Add_New_Patient(int Id, QString Name, QString Phone, QString Address, QString Mail, int Age, QString Date, QString sex, QString Marital_status)
{
    Patient p(Id,Name,Phone,Address,Mail,Age,Date,sex,Marital_status);

    D->write_patient(p);
    return p;

}

bool MedicalLab::Add_New_test(Test t)
{

    D->write_test(t);
    return true;

}

Order MedicalLab::Add_New_order(vector<Test> t,QString Address)
{
    Order o(t,Address);
    D->write_order(o);
    return o;

}

MedicalLab MedicalLab::add_New_Lab(int Id, QString Name, QString Phone, QString Address,QString pass){
    MedicalLab m(Id,Name,Phone,Address,pass);
    D->write_medicallab(m);
    return  m;


}
Doctor MedicalLab::Add_New_Doctor(Doctor d){
  D->write_doctor(d);
  return  d;

}
Deliver_Doctor MedicalLab::Add_New_Deliver_Doctor(Deliver_Doctor d){
  D->write_deliver_doctor(d);
  return  d;

}
Receptionist MedicalLab::Add_New_Receptionist(Receptionist R){
  D->write_receptionist(R);
  return  R;

}
vector<Test> MedicalLab::read_test(int id){


    return D->read_test_for_patient(id);

}
Order MedicalLab::read_order(int id){


    return D->read_order(id);

}
Patient MedicalLab::read_patient_by_phone(QString phon){

    return D->read_patient_by_phone(phon);


}
void MedicalLab::write_order(Order o){
    this->D->write_order(o);
}
