#include "mainwindow.h"
#include <QApplication>
#include <QString.h>
#include<testform.h>

#include<staffform.h>
#include"databasemodel.h"
#include <qdebug.h>
#include <patientform.h>
#include <vector>
#include<QDesktopWidget>
#include <QStyle>
#include<dialog.h>
#include<form.h>
#include<labform.h>
#include <orderform.h>
#include <staffform.h>


using namespace std;
int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
   /* MainWindow w;
   w.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, w.size(), a.desktop()->availableGeometry()));
    w.show();*/

    Dialog *dialog = new Dialog();

    dialog->show();

 QString h;

 /*MedicalLab m;
 DatabaseModel d("QMYSQL","localhost","mohamed","root","mohamed");
 m.D=&d;
 //MedicalLab e=m.add_New_Lab(2015,"mohamed","0101319","2 abo 5oda","12345");
 MedicalLab x=m.login(2015,"12345");
// x.Add_New_Doctor(2018,"doctor1","0128490011",2000,"male",25,"sakakiny");
 //x.Add_New_Doctor(2018,"doctor2","0128490022",2000,"male",25,"sakakiny_daher");
// x.Add_New_Patient(400, "p1","01556","daher", "@yahoo", 55, "8/4/2015","male", "single");
 // x.Add_New_Patient(401, "p2","01557","basateen", "@hotmail", 24, "8/4/2015","male", "single");
  Patient p=x.read_patient_by_phone("01556");
 Test t(p,"blood");
  vector<Test> v;
  v.push_back(t);


  x.Add_New_order(v,"bab el sha3ria");
 //Patient p=x.read_patient_by_phone("01556");

 qDebug()<<x.Address;

 /*MedicalLab m(2015,"mohamed","0101319","2 abo 5oda","12345");
 MedicalLab m=d.read_medicallab(2015,"12345");

 d.write_deliver_doctor(Deliver_Doctor(2018,"sayed","01284900",2000,"male",25,"sakakiny"));
 d.write_doctor(Doctor(2018,"sayed","01284900",2000,"male",25,"sakakiny"));


 d.write_patient(Patient(455, "p1","01556","daher", "@yahoo", 55, "8/4/2015","male", "single"));

 d.write_patient(Patient(456, "p1","01556","daher", "@yahoo", 55, "8/4/2015","male", "single"));
 Patient p=d.read_patient_by_phone("01556");
 Test t(p,"homeg");
 d.write_test(t);
 vector<Test> v;
 v.push_back(t);
 Order o(v,"sssssssssssssss");
 d.write_order(o);

Order s=d.read_order(455);
 Doctor r=d.read_doctor(2018);
 qDebug()<<s.test.at(0).Id;
*/

    return a.exec();
}
