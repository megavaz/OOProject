#ifndef SCHEDUL_H
#define SCHEDUL_H
#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
#include "circle_flight.h"

class schedule{   
    
    public:
    std::vector<flight> flights;
    schedule(){}

    int add(const flight &a);

    int add(const circle_flight &a);

    std::vector<flight> convert(const circle_flight &a);

    int flight_time(const int i);

    int get_schedule();

};
#endif