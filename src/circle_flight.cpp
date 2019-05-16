#include "circle_flight.h"
using std::cout;

int circle_flight::add_city(const string &c, week_day a_d, int a_t, week_day d_d, int d_t)
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

/*circle_flight::flight_base circle_flight::get_copy() const{
    int n = cities.size();
    circle_flight temp(identifier);
    for(int i = 0;i < cities.size(); i++){
        temp.add_city(cities[i].city_name, cities[i].arrival_day, cities[i].arrival_time, cities[i].departure_day, cities[i].departure_time);
    }
    return(temp);
};*/