#include "Order.h"
#include "Test.h"
#include"databasemodel.h"


Order::Order(vector<Test> test, QString Address)
{
    this->test=test;
    this->Address=Address;


}


