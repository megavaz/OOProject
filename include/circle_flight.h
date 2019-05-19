#ifndef CIRCLE_FLIGHT_H
#define CIRCLE_FLIGHT_H
#include <iostream>
#include <string>
#include <vector>
#include <flight_base.h>
using std::string;
//using std::vector;
using std::cout;
class circle_flight: public flight_base
{
    public:
    struct city
    {
        string city_name;
        week_day departure_day, arrival_day;
        int departure_time, arrival_time;
    };
    
    std::vector<city> cities;  

    circle_flight(const int identifier):flight_base(identifier){}
    circle_flight();

    week_day get_arrival_day(int n) const{
        return (cities[n].arrival_day);
    };

    week_day get_departure_day(int n) const{
        return (cities[n].departure_day);
    };

    int get_departure_time(int n) const{
        return(cities[n].departure_time);
    };

    int get_arrival_time(int n) const{
        return(cities[n].arrival_time);
    };

    string get_city(int n) const{           //gets city's name
        return(cities[n].city_name);
    };

    int add_city(const string &c, week_day a_d, int a_t,
     week_day d_d, int d_t); //adds city into the "cities" vector

    //flight_base get_copy() const;
};

#endif