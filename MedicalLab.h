#ifndef MedicalLab_h
#define MedicalLab_h
#include "Patient.h"
#include "Test.h"
#include "Order.h"
#include <QString>
#include "Deliver_Doctor.h"
#include "Doctor.h"
#include<Receptionist.h>

using namespace std;
class DatabaseModel;
class MedicalLab {
public:

   DatabaseModel *D;
   int Id;
   QString Name;
   QString Phone;
   QString Address;
   QString Password;
 vector<Doctor> doctors;
 vector<Deliver_Doctor> deliver_doctors;



 public:
    MedicalLab(){}


    MedicalLab(int Id, QString Name, QString Phone, QString Address ,QString pass);

    void receive_order_from_DD(Deliver_Doctor d);

    bool search_lab_By_name(QString Name);

    bool search_by_phone(QString phone);

    MedicalLab login(int Id, QString Password);

    MedicalLab add_New_Lab(int Id, QString Name, QString Phone, QString Address,QString pass);

    Patient Add_New_Patient(int Id, QString Name, QString Phone, QString Address, QString Mail, int Age, QString Date, QString sex, QString Marital_status);

    bool Add_New_test(Test t);

    Order Add_New_order(vector<Test> t,QString Address);

    Doctor Add_New_Doctor(Doctor d);
    Deliver_Doctor Add_New_Deliver_Doctor(Deliver_Doctor d);
    Receptionist Add_New_Receptionist(Receptionist R);

    Patient read_patient_by_phone(QString phone);

    vector<Test> read_test(int patient_id);

    Order read_order(int patient_id);

    void write_order(Order o);



};

#endif // MedicalLab_h
