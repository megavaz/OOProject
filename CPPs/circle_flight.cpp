#include "circle_flight.h"
using std::cout;

int circle_flight::add_city(const string c, const week_day a_d, const int a_t, const week_day d_d, const int d_t)
{
    city temp;
    temp.city_name = c;
    temp.arrival_day = a_d;
    temp.arrival_time = a_t;    
    temp.departure_day = d_d;
    temp.departure_time = d_t;
    cities.push_back(temp);
    return 0;
};