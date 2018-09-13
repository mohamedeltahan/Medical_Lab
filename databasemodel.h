#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
#include <QtCore>
#include <QString>
#include <QtSql/QSqlDatabase>
#include<QSqlQuery>
#include "Doctor.h"
#include "Deliver_Doctor.h"
#include "MedicalLab.h"
#include "Order.h"
#include "Patient.h"
#include "Receptionist.h"
#include "Staff.h"
#include "Test.h"
#include <vector>
class DatabaseModel
{
  public:

    QSqlDatabase db ;
    QString db_type;
    QString host_name;
    QString db_name;
    QString db_username;
    QString db_password;
    bool connected;


    QString database_type;

public:
    DatabaseModel();
    DatabaseModel(QString,QString ,QString ,QString ,QString );
    void write_doctor(Doctor D);
    Doctor read_doctor(int doctor_id);
    void write_medicallab(MedicalLab l);
    MedicalLab read_medicallab(int lab_id,QString pass);
    void write_order(Order o);
    Order read_order(int patient_id);
    void write_patient(Patient p);
    Patient read_patient_by_id(int patient_id);
    Patient read_patient_by_phone(QString phone);
    void write_receptionist(Receptionist R);
    Receptionist read_receptionist(int r_id);
    void write_test(Test T);
    Test read_test(int test_id);
    Deliver_Doctor read_deliver_doctor(int id);
    int  get_delive_doctor_id(QString name);

    void write_deliver_doctor(Deliver_Doctor d);
    vector<Deliver_Doctor> read_All_Deliver_doctor();

    vector<Test> read_test_for_patient(int patient_id);
    vector<Doctor> read_All_doctor();
    vector<MedicalLab> read_All_Medicallab();
    vector<Order> read_All_Order();
    vector<Patient> read_All_Patient();
    vector<Receptionist> read_All_Receptionist();
    vector<Test> read_All_Test_for_order(int patient_id);
    void qu(QString s);
};

#endif // DATABASEMODEL_H
