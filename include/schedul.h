#ifndef SCHEDUL_H
#define SCHEDUL_H
#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
#include "circle_flight.h"

class schedule{   
    
    public:
    schedule *next;
    flight voyage;
    schedule(): next(nullptr){}

    int add(const flight &a);

    int add(const circle_flight &a);

    std::vector<flight> convert(const circle_flight &a);

    void equaliser(flight &current,const flight &a);

    int flight_time();

    int get_schedule();

};
#endif