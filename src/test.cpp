#include <cstdio>
#include <cassert>
#include "flight.h"
#include "circle_flight.h"
#include "schedul.h"

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

    flight f4("LA", "NY",flight::week_day(5),flight::week_day(6), 1240, 160, 2);
    assert(f1<f4);  //test for < operator    
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

void test_schedule(){
    flight f1("Moscow", "LA", flight::week_day(4), flight::week_day(4), 300, 1020, 1);
    flight f2("LA", "NY", flight::week_day(5), flight::week_day(6), 1240, 160, 2);
    flight f3("Maryland", "Oklahoma", flight::week_day(5), flight::week_day(6), 1239, 160, 3);
    circle_flight c_f1(4);
    c_f1.add_city("Madrid", circle_flight::week_day(1), 1020, circle_flight::week_day(3), 600);
    c_f1.add_city("Barcelona", circle_flight::week_day(3), 670, circle_flight::week_day(1), 935);
    schedule s1, *s = &s1;

    s1.add(f1);
    s1.add(f2);
    s1.add(f3);
    s1.add(c_f1);

    s1.get_schedule();
    unsigned int i = 0;
    assert(s1.flights[i].get_identifier() == 4);
    assert(s1.flights[i].get_departure_city() == "Barcelona"); //tests for initialization
    assert(s1.flights[i].get_arrival_city() == "Madrid");
    assert(s1.flights[i].get_departure_day() == 1);
    assert(s1.flights[i].get_arrival_day() == 1);
    assert(s1.flights[i].get_departure_time() == 935);
    assert(s1.flights[i].get_arrival_time() == 1020);   
    i++;
    assert(s->flights[i].get_identifier() == 4);
    assert(s->flights[i].get_departure_city() == "Madrid"); //tests for initialization
    assert(s->flights[i].get_arrival_city() == "Barcelona");
    assert(s->flights[i].get_departure_day() == 3);
    assert(s->flights[i].get_arrival_day() == 3);
    assert(s->flights[i].get_departure_time() == 600);
    assert(s->flights[i].get_arrival_time() == 670);   
    i++;
    assert(s->flights[i].get_identifier() == 1);
    assert(s->flights[i].get_departure_city() == "Moscow"); //tests for initialization
    assert(s->flights[i].get_arrival_city() == "LA");
    assert(s->flights[i].get_departure_day() == 4);
    assert(s->flights[i].get_arrival_day() == 4);
    assert(s->flights[i].get_departure_time() == 300);
    assert(s->flights[i].get_arrival_time() == 1020);   
    i++;
    assert(s->flights[i].get_identifier() == 3);
    assert(s->flights[i].get_departure_city() == "Maryland"); //tests for initialization
    assert(s->flights[i].get_arrival_city() == "Oklahoma");
    assert(s->flights[i].get_departure_day() == 5);
    assert(s->flights[i].get_arrival_day() == 6);
    assert(s->flights[i].get_departure_time() == 1239);
    assert(s->flights[i].get_arrival_time() == 160);  
    i++;
    assert(s->flights[i].get_identifier() == 2);
    assert(s->flights[i].get_departure_city() == "LA"); //tests for initialization
    assert(s->flights[i].get_arrival_city() == "NY");
    assert(s->flights[i].get_departure_day() == 5);
    assert(s->flights[i].get_arrival_day() == 6);
    assert(s->flights[i].get_departure_time() == 1240);
    assert(s->flights[i].get_arrival_time() == 160);

};

int main () {
    test_flight();
    test_circle_flight();
    test_schedule();
    cout<<"Done!"<<std::endl;
    return 0;
};