#ifndef Order_h
#define Order_h

#include "Test.h"

#include <QString>
using namespace std;

class Order {

public:
   QString Address;
   QString Date;
  int deliver_doctor_id;
   vector<Test> test;

public:

    Order(vector<Test> test, QString Address);

     bool Set_Order_State();

};

#endif // Order_h
