#include "Test.h"
Test::Test(){


}



Test::Test(Patient p,QString type)
{
this->p=p;
    this->type=type;
    this->State=false;
    this->Date="";

}

void Test::set_State( bool s)
{
    State=s;
}
