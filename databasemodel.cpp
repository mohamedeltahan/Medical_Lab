#include "databasemodel.h"
#include <QSqlError>
#include <QStringBuilder>

DatabaseModel::DatabaseModel(QString db_type,QString host_name,QString db_name,QString db_username,QString db_password)
{
    this->database_type=db_type;
    this->host_name=host_name;
    this->db_name=db_name;
    this->host_name=db_username;
    this->db_password=db_password;
   db= QSqlDatabase::addDatabase(db_type);
   db.setHostName(host_name);
   db.setDatabaseName(db_name);
   db.setUserName(db_username);
   db.setPassword(db_password);
   connected = db.open();




}
void DatabaseModel::write_medicallab(MedicalLab l){

    QSqlQuery q;
   bool c= q.exec("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES where TABLE_NAME='labs' ");


   q.first();
   if(q.isNull(0)){
       q.exec("create database labs_database");
       q.exec("create table labs_database.labs( id int,name varchar(255),phone varchar(255),address varchar(255),password varchar(255))");
       QString a="create database ";
       QString h=l.Name;
       QString s=a % h;
       q.exec(s);


       db.setDatabaseName(l.Name);

       qDebug() <<db.open();
       q.exec("create table delive_doctor( id int,name varchar(255),phone varchar(255), salary int,sex varchar(25), age int ,address varchar(255))");

       q.exec("create table doctor( id int,name varchar(255),phone varchar(255), salary int,sex varchar(25), age int ,address varchar(255))");
       q.exec("create table receptionist( id int,name varchar(255),phone varchar(255), salary int ,sex varchar(25), age int,address varchar(255))");
       q.exec("create table patient( id int,name varchar(255),phone varchar(255),address varchar(255),mail varchar(255), age int , date varchar(30),sex varchar(25),marital_status varchar(255))");
       q.exec("create table tests( id int, test_type varchar(255),date varchar(255), patient_id int,state bool,report_path varchar(255))");
       q.exec("create table orders( address varchar(255),date varchar(255), test_id int, patient_id int,doc_id int)");


}

   q.exec("SELECT max(id)  from labs");
    q.first();
    int z;
    if(q.value(0).isNull()){z=0;}
    else { z =q.value(0).toInt()+1;}
    l.Id=z;
   db.setDatabaseName("labs_database");
   db.open();


   q.prepare("insert into labs (id , name , phone ,address,password)"
          "values(?,?,?,?,?)");
   q.addBindValue(l.Id);
   q.addBindValue(l.Name);
   q.addBindValue(l.Phone);
   q.addBindValue(l.Address);
   q.addBindValue(l.Password);
   q.exec();

   db.setDatabaseName(l.Name);

   db.open();



}
MedicalLab DatabaseModel::read_medicallab(int lab_id,QString Pass){
    QSqlQuery q;
    bool c =q.exec("select * from  labs_database.labs where id="+QString::number(lab_id));
    q.first();
    if(q.value(0).toString()!=""){
    int id=q.value(0).toInt();
    QString name=q.value(1).toString();
    QString phone=q.value(2).toString();
    QString address=q.value(3).toString();
    QString pass=q.value(4).toString();
  if(pass==Pass) return MedicalLab(id,name,phone,address,pass);

}
    return MedicalLab();


}
void DatabaseModel::write_doctor(Doctor D){
    QSqlQuery q;
    q.exec("SELECT max(id)  from doctor");
     q.first();
     int z;
     if(q.value(0).isNull()){z=0;}
     else { z =q.value(0).toInt()+1;}
    D.Id=z;

    q.prepare("insert into doctor(id ,name,phone,salary,sex,age,address)"
           "values(?,?,?,?,?,?,?)");
    q.addBindValue(D.Id);
    q.addBindValue(D.Name);
    q.addBindValue(D.Phone);
    q.addBindValue(D.Salary);
    q.addBindValue(D.Sex);
    q.addBindValue(D.Age);
    q.addBindValue(D.Address);
    q.exec();
    QSqlError e=q.lastError();
    qDebug()<<e.text();





}
Doctor DatabaseModel::read_doctor(int doctor_id){
    QSqlQuery q;
    bool b=q.exec("select * from doctor where  id="+QString::number(doctor_id) );

    if(b){
        q.first();
        int id=q.value(0).toInt();
        QString name=q.value(1).toString();
        QString phone=q.value(2).toString();
        int salary=q.value(3).toInt();
        QString sex=q.value(4).toString();
        int age =q.value(4).toInt();
        QString address=q.value(3).toString();

        return Doctor(id,name,phone,salary,sex,age,address);

    }
    return Doctor();




}
void DatabaseModel::write_test(Test t){
    QSqlQuery q;
    q.exec("select * from tests where id="+QString::number(t.Id));
    q.first();
     if(!q.isNull(0)){q.exec("drop *  from tests where id="+QString::number(t.Id));}

    q.prepare("insert into tests (id,test_type,date,patient_id,state,report_path)"
           "values(?,?,?,?,?,?)");
    q.addBindValue(t.Id);
    q.addBindValue(t.type);
    q.addBindValue(t.Date);
    q.addBindValue(t.p.Id);
    q.addBindValue(t.State);
    q.addBindValue(t.report);

    q.exec();





}

Test DatabaseModel::read_test(int test_id){
    QSqlQuery q;

    bool b=q.exec("select * from tests where  id="+QString::number(test_id) );

    if(b){
          q.first();
        int id=q.value(0).toInt();
        QString test_type=q.value(1).toString();
        QString date=q.value(2).toString();
        int patient_id=q.value(3).toInt();
        bool state=q.value(4).toBool();
        QString report_path=q.value(5).toString();
    Patient p= read_patient_by_id(patient_id);
    Test t;
    t.p=p;
    t.Id=id;
    t.type=test_type;
    t.Date=date;
    t.State=state;
    t.report=report_path;
    return t;

}
}
vector <Test> DatabaseModel::read_test_for_patient(int patient_id){
    QSqlQuery q;
    bool b=q.exec("select * from tests where  patient_id="+QString::number(patient_id) );
    vector<Test> V;
    while(q.next()){
    int id=q.value(0).toInt();
    qDebug()<<id;
Patient p= read_patient_by_id(patient_id);
Test t=read_test(id);
  qDebug()<<t.Id;
     V.push_back(t);

   }


return V;





}
vector<Test> DatabaseModel::read_All_Test_for_order(int patient_id){
    QSqlQuery q;
    q.exec("select test_id from orders where patient_id="+QString::number(patient_id));
    vector<Test> V;
    while(q.next()){
    int id=q.value(0).toInt();
Patient p= read_patient_by_id(patient_id);
Test t=read_test(id);
     V.push_back(t);

   }
    return V;



}



Order DatabaseModel::read_order(int patient_id){
    Patient p =read_patient_by_id(patient_id);

    vector<Test> T = read_All_Test_for_order(patient_id);
    Order o(T,"");

    return o;





}
void DatabaseModel::write_order(Order o){
    vector<Test>::iterator it;
    for(it=o.test.begin();it!=o.test.end();it++){
        QSqlQuery q;
        int z;
        q.exec("SELECT max(id)  from tests");
         q.first();
         if(q.value(0).isNull()){z=0;}
      else { z =q.value(0).toInt()+1;}
         (*it).Id=z;

        write_test(*it);

        q.prepare("insert into orders (address,date,test_id,patient_id,doc_id)"
               "values(?,?,?,?,?)");
        q.addBindValue(o.Address);
        q.addBindValue(o.Date);
        q.addBindValue((*it).Id);
        q.addBindValue((*it).p.Id);
        q.addBindValue(o.deliver_doctor_id);
        q.exec();

    }

}
void DatabaseModel::write_patient(Patient p ){
    int id;
    QSqlQuery q;
     q.exec("SELECT max(id)  from patient");
     q.first();
     if(q.value(0).isNull()){id=0;}
     else { id =q.value(0).toInt()+1;}
     p.Id=id;


    q.prepare("insert into patient(id,name,phone,address,mail,age,date,sex,marital_status)"
           "values(?,?,?,?,?,?,?,?,?)");
    q.addBindValue(p.Id);
    q.addBindValue(p.Name);
    q.addBindValue(p.Phone);
    q.addBindValue(p.Address);

    q.addBindValue(p.Mail);
    q.addBindValue(p.Age);

    q.addBindValue(p.Date);
    q.addBindValue(p.Sex);
    q.addBindValue(p.Marital_status);
    q.exec();





}
Patient DatabaseModel::read_patient_by_id(int patient_id){
    QSqlQuery q;
    bool b=q.exec("select * from patient where  id="+QString::number(patient_id) );
    if(b){
        q.first();
        int id=q.value(0).toInt();
        QString name=q.value(1).toString();
        QString phone=q.value(2).toString();
        QString address=q.value(3).toString();
        QString mail=q.value(4).toString();
        int age =q.value(5).toInt();

        QString date=q.value(6).toString();
        QString sex=q.value(7).toString();
        QString marital_status=q.value(8).toString();




        return Patient(id,name,phone,address,mail,age,date,sex,marital_status);




}}
Patient DatabaseModel::read_patient_by_phone(QString phone){
    QSqlQuery q;
    QString h=phone;
    QString s="select * from patient where  phone=";
    QString y=h % s;
    bool b=q.prepare("select * from patient where  phone=?" );

    q.addBindValue(phone);
    q.exec();
        if(b){
        q.first();
        int id=q.value(0).toInt();
        QString name=q.value(1).toString();
        QString phone=q.value(2).toString();
        QString address=q.value(3).toString();
        QString mail=q.value(4).toString();
        int age =q.value(5).toInt();

        QString date=q.value(6).toString();
        QString sex=q.value(7).toString();
        QString marital_status=q.value(7).toString();




        return Patient(id,name,phone,address,mail,age,date,sex,marital_status);




}}
Deliver_Doctor DatabaseModel::read_deliver_doctor(int id){
    QSqlQuery q;
    bool b=q.exec("select * from delive_doctor where  id="+QString::number(id) );

    if(b){
        q.first();
        int id=q.value(0).toInt();
        QString name=q.value(1).toString();
        QString phone=q.value(2).toString();
        int salary=q.value(3).toInt();
        QString sex=q.value(4).toString();
        int age =q.value(4).toInt();
        QString address=q.value(3).toString();

        return Deliver_Doctor(id,name,phone,salary,sex,age,address);

    }





}
vector<Deliver_Doctor> DatabaseModel::read_All_Deliver_doctor(){
    QSqlQuery q;
    bool b=q.exec("select id from delive_doctor" );
    vector<Deliver_Doctor> v;
    while(q.next()){
        v.push_back(read_deliver_doctor(q.value(0).toInt()));



    }

    return v;





}
vector<Doctor> DatabaseModel::read_All_doctor(){
    QSqlQuery q;
    bool b=q.exec("select id from doctor" );
    vector<Doctor> v;
    while(q.next()){
        v.push_back(read_doctor(q.value(0).toInt()));



    }

    return v;





}

void DatabaseModel::write_deliver_doctor(Deliver_Doctor d){
    QSqlQuery q;
    q.exec("SELECT max(id) from delive_doctor");
     q.first();
     int z;
     if(q.value(0).isNull()){z=0;}
     else { z =q.value(0).toInt()+1;}
    d.Id=z;
    q.prepare("insert into delive_doctor(id ,name,phone,salary,sex,age,address)"
           "values(?,?,?,?,?,?,?)");
    q.addBindValue(d.Id);
    q.addBindValue(d.Name);
    q.addBindValue(d.Phone);
    q.addBindValue(d.Salary);
    q.addBindValue(d.Sex);
    q.addBindValue(d.Age);
    q.addBindValue(d.Address);
    q.exec();





}
void DatabaseModel::write_receptionist(Receptionist R){
    QSqlQuery q;
    q.exec("SELECT max(id)  from receptionist");
     q.first();
     int z;
     if(q.value(0).isNull()){z=0;}
     else { z =q.value(0).toInt()+1;}
    R.Id=z;
    q.prepare("insert into receptionist (id ,name,phone,salary,sex,age,address)"
           "values(?,?,?,?,?,?,?)");
    q.addBindValue(R.Id);
    q.addBindValue(R.Name);
    q.addBindValue(R.Phone);
    q.addBindValue(R.Salary);
    q.addBindValue(R.Sex);
    q.addBindValue(R.Age);
    q.addBindValue(R.Address);
    q.exec();





}
void DatabaseModel::qu(QString s){

    QSqlQuery q;
    q.exec(s);

    while(q.next()){
        qDebug()<<q.value(3).toInt();


    }



}
int  DatabaseModel::get_delive_doctor_id(QString name){
    QSqlQuery q;

    bool b=q.prepare("select id from delive_doctor where  name=?" );

    q.addBindValue(name);
    q.exec();
    q.first();
    return q.value(0).toInt();



}
vector<Patient>DatabaseModel::read_All_Patient(){
    QSqlQuery q;
    vector<Patient> v;
    bool b=q.exec("select id from patient" );

    while(q.next()){
      v.push_back(read_patient_by_id(q.value(0).toInt()));

    }

    return v;

}

