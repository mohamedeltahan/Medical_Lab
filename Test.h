#ifndef Test_h
#define Test_h

#include "Patient.h"
#include "QString.h"
#include <QString>
#include<QSqlQuery>

using namespace std;


class Test {

public:
   int Id;
   QString Date;
   Patient p;
   bool State;
   QString type;
   QString report;

 public:
   Test();
    Test( Patient p,QString type);
    void set_State(bool s);



};

#endif // Test_h
