#ifndef Doctor_h
#define Doctor_h

#include "Staff.h"
#include "Test.h"
#include <QString>
#include <vector>
using namespace std;

class Doctor : public Staff {

 public:
    vector<Test> Holding_Tests;


 public:
    Doctor(){}
    Doctor(int id,QString name,QString phone,int salary,QString sex,int age, QString address);
    bool Set_Test_State(int Test_id);
};

#endif // Doctor_h
