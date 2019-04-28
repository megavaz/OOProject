#include<cstdio>
#include <cassert>
#include"flight.h"

void test_flight() {
    flight f1("Moscow", "LA", 4, 4, 300, 1020, 1);    
    
    assert(f1.get_departure_city()=="Moscow"); //tests for initialization
    assert(f1.get_arrival_city()=="LA");
    assert(f1.get_departure_day()==4);
    assert(f1.get_arrival_day()==4);
    assert(f1.get_departure_time()==300);
    assert(f1.get_arrival_time()==1020);    
    assert(f1.get_identidier()==1);
    
    flight f2("", "", 0, 0, 0, 0, 0);
    f2.reverse(f1);    
    assert(f2.get_departure_city() == "LA");  //tests for reverse function
    assert(f2.get_arrival_city() == "Moscow");

    flight f3("Moscow", "LA", 4, 4, 300, 1020, 1);    
    assert(f3==f1);      //test for == operator

    flight f4("LA", "NY", 6, 7, 1240, 160, 2);
    assert(f4<f1);  //test for < operator
};

int main () {
    test_flight();
    cout<<"Done!"<<std::endl;
    return 1;
};