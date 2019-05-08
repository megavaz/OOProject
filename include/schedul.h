#ifndef ZHOPA_H
#define ZHOPA_H
#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
#include "circle_flight.h"

class schedule: public flight{   
    
    public:
    schedule *next;
    schedule(int departure_time = 0, int identifier = -1):
        flight(departure_city, arrival_city, departure_day, arrival_day, departure_time, arrival_time, identifier),
        next(nullptr){}

    int add(const flight &a);

    int add(const circle_flight &a);

    std::vector<flight> convert(const circle_flight &a);

    void equaliser(schedule *current,const flight &a);

    int flight_time();

    int get_schedule();

};
#endif