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
    enum week_day{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    struct city
    {
        string city_name;
        week_day departure_day, arrival_day;
        int departure_time, arrival_time;
    };
    //int identifier;
    std::vector<city> cities;
    //string *city;
   //week_day *departure_day, *arrival_day;
    //int *departure_time, *arrival_time, identifier;

    circle_flight(const int identifier):flight_base(identifier){}


    int get_arrival_day(int n) const{
        return int(cities[n].arrival_day);
    };

    int get_departure_day(int n) const{
        return int(cities[n].departure_day);
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

    /*int get_identifier() const{
        return(identifier);
    };*/

    int add_city(const string c, const week_day a_d, const int a_t,
     const week_day d_d, const int d_t); //adds city into the "cities" vector
};

#endif