#include<cstdio>
#include <cassert>
#include"flight.h"
#include "circle_flight.h"

void test_flight() {
    flight f1("Moscow", "LA",flight::week_day(4), flight::week_day(4), 300, 1020, 1);    
    
    assert(f1.get_departure_city() == "Moscow"); //tests for initialization
    assert(f1.get_arrival_city() == "LA");
    assert(f1.get_departure_day() == 4);
    assert(f1.get_arrival_day() == 4);
    assert(f1.get_departure_time() == 300);
    assert(f1.get_arrival_time() == 1020);    
    assert(f1.get_identifier() == 1);
    
    flight f2 = f1.reverse();    
    assert(f2.get_departure_city() == "LA");  //tests for reverse function
    assert(f2.get_arrival_city() == "Moscow");

    flight f3("Moscow", "LA", flight::week_day(4), flight::week_day(4), 300, 1020, 1);  
    assert(f3==f1);      //test for == operator

    flight f4("LA", "NY",flight::week_day(6),flight::week_day(7), 1240, 160, 2);
    assert(f4<f1);  //test for < operator
   };

void test_circle_flight(){
    circle_flight c_f1(3);
    c_f1.add_city("Madrid", circle_flight::week_day(1), 1020, circle_flight::week_day(3), 600);
    c_f1.add_city("Barcelona", circle_flight::week_day(3), 670, circle_flight::week_day(1), 935);
    assert(c_f1.get_city(0) == "Madrid");                //tests for initialization
    assert(c_f1.get_city(1) == "Barcelona");
    assert(c_f1.get_arrival_day(0) == 1);
    assert(c_f1.get_arrival_day(1) == 3);
    assert(c_f1.get_arrival_time(0) == 1020);
    assert(c_f1.get_arrival_time(1) == 670); 
    assert(c_f1.get_departure_day(0) == 3);
    assert(c_f1.get_departure_day(1) == 1);
    assert(c_f1.get_departure_time(0) == 600);
    assert(c_f1.get_departure_time(1) == 935);    
    assert(c_f1.get_identifier() == 3);
    //cout << c_f1.get_arrival_day(0) << " " << c_f1.get_identifier() << std::endl;
}

int main () {
    test_flight();
    test_circle_flight();
    cout<<"Done!"<<std::endl;
    return 0;
};