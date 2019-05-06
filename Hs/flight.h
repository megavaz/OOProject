#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
#include <flight_base.h>
using std::string;
//using std::vector;
using std::cout;


class flight: public flight_base
{
    public:   
   
    string departure_city, arrival_city; 
    enum week_day{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    week_day departure_day, arrival_day;
       
    int departure_time, arrival_time; //time in minutes
    

    flight(const string &departure_city,const string &arrival_city, 
     week_day departure_day, week_day arrival_day, int departure_time = 0, 
        int arrival_time = 0, int identifier = 0):
        departure_city(departure_city), arrival_city(arrival_city), departure_day(departure_day),
         arrival_day(arrival_day), departure_time(departure_time), arrival_time(arrival_time), flight_base(identifier) {}

    
     flight reverse () const;
    bool  operator < (const flight &f) const;
    bool  operator == (const flight &f) const;

    const string &get_departure_city(void) const{
        return(departure_city);
    };
    
    const string &get_arrival_city() const{
        return (arrival_city);
    };

    int get_arrival_day() const{
        return int(arrival_day);
    };

    int get_departure_day() const{
        return int(departure_day);
    };

    int get_departure_time() const{
        return(departure_time);
    };

    int get_arrival_time() const{
        return(arrival_time);
    };

    /*int get_identidier() const{
        return(identifier);
    };*/


};
#endif //FLIGHT_H