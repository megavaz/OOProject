#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
using std::string;
//using std::vector;
using std::cout;


class flight
{

   
    private:
    string departure_city, arrival_city;
    int departure_day, arrival_day, departure_time, arrival_time, identifier; //time in minutes
    public:
    flight(string departure_city, string arrival_city, 
    int departure_day, int arrival_day, int departure_time, 
    int arrival_time, int identifier):
        departure_city(departure_city), arrival_city(arrival_city), departure_day(departure_day),
         arrival_day(arrival_day), departure_time(departure_time), arrival_time(arrival_time), identifier(identifier) {}

    
     flight  reverse (flight f);
    bool  operator < (const flight &f) const;
    bool  operator == (const flight &f) const;

    const string &get_departure_city(void){
        return(departure_city);
    };
    
    const string &get_arrival_city(){
        return (arrival_city);
    };

    const int &get_arrival_day(){
        return(arrival_day);
    };

    const int &get_departure_day(){
        return(departure_day);
    };

    const int &get_departure_time(){
        return(departure_time);
    };

    const int &get_arrival_time(){
        return(arrival_time);
    };

    const int &get_identidier(){
        return(identifier);
    };


};
#endif //FLIGHT_H