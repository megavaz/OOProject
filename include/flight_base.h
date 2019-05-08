#ifndef FLIGHT_BASE_H
#define FLIGHT_BASE_H
#include <string>
#include "math.h"
using std::string;
class flight_base{
    
    public:
    int identifier; 
    enum week_day{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    flight_base(int identifier):identifier(identifier){}
    int get_identifier() const{
        return(identifier);
    };

    string Weekday(week_day day);

};
#endif