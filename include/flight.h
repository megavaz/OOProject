#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
#include <flight_base.h>
using std::string;
//using std::vector;
using std::cout;


class flight: public flight_base{
    public:   
   
    string departure_city, arrival_city;
    
    week_day departure_day, arrival_day;
       
    int departure_time, arrival_time; //time in minutes
    

    flight(const string &departure_city_arg, const string &arrival_city_arg, 
     week_day departure_day_arg, week_day arrival_day_arg, int departure_time_arg = 0, 
        int arrival_time_arg = 0, int identifier = 0):
        flight_base(identifier)
        {
            departure_city = departure_city_arg;
            arrival_city = arrival_city_arg;
            departure_day = departure_day_arg;
            arrival_day = arrival_day_arg;
            departure_time = departure_time_arg;
            arrival_time = arrival_time_arg;
        }
    flight();

    
    flight reverse () const;
    bool  operator < (const flight &f) const;
    bool  operator == (const flight &f) const;

    const string &get_departure_city(void) const{
        return(departure_city);
    };
    
    const string &get_arrival_city() const{
        return (arrival_city);
    };

    week_day get_arrival_day() const{
        return (arrival_day);
    };

    week_day get_departure_day() const{
        return (departure_day);
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
#endif 