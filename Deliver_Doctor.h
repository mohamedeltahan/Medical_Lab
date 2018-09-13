#ifndef Deliver_Doctor_h
#define Deliver_Doctor_h
#include <vector>
#include "Order.h"
#include "Staff.h"
#include <QString>
using namespace std;

class Deliver_Doctor : public Staff {


public:
  vector<Order> Holding_orders;

 public:
   Deliver_Doctor();
   Deliver_Doctor(int id,QString name,QString phone,int salary,QString sex,int age, QString address);
   void assign_order(Order o);
   Order recieve_order();
   ~Deliver_Doctor();
};

#endif // Deliver_Doctor_h
