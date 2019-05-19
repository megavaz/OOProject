#include "schedul.h"
#include <algorithm>

int schedule::add(const flight &a){
    this->flights.push_back(a);
    return 0;
};

std::vector<flight> schedule::convert(const circle_flight &a){  // this method converts circle flight into regular flight
    std::vector<flight> flights;
    int number_of_cities = a.cities.size(); //number of members in the vector with cities
    flight voyage(a.get_city(number_of_cities - 1), a.get_city(0), a.get_departure_day(number_of_cities - 1),    //creates first flight from last city
    a.get_arrival_day(0),a.get_departure_time(number_of_cities - 1), a.get_arrival_time(0), a.get_identifier()); //to first city
    flights.push_back(voyage);
    for(int i = 0; i<number_of_cities-1; i++){        //this creates more flights between every other cities
        voyage.arrival_city = a.get_city(i+1);
        voyage.arrival_time = a.get_arrival_time(i+1);
        voyage.arrival_day = a.get_arrival_day(i+1);
        voyage.departure_city = a.get_city(i);
        voyage.departure_time = a.get_departure_time(i);
        voyage.departure_day = a.get_departure_day(i);
        voyage.identifier = a.get_identifier();
        flights.push_back(voyage);
    }
    return(flights);
};

int schedule::add(const circle_flight &a){                 // uses vector of class flight and sends it into 
    std::vector<flight> flights = convert (a);       // add function which adds members of this vector into
    for (unsigned int i = 0; i<flights.size(); i++){          // schedule
        add(flights[i]);
    }
    return 0;
};

int schedule::flight_time(const int i){
    return (this->flights[i].get_arrival_day()*1440+this->flights[i].get_arrival_time()-this->flights[i].get_departure_day()*1440-this->flights[i].get_departure_time());
};


int schedule::get_schedule(){
    schedule *a = this;
    std::sort(a->flights.begin(),a->flights.end());
    printf("| ID| Departure time| Departure day| Departure city| Arrival time| Arrival Day| Arrival city|    Flight time|\n");
    for (unsigned int i = 0; i<a->flights.size(); i++){
        printf("|%03i|          %02i:%02i|     %9s|%15s|        %02i:%02i|   %9s|%13s| %02i hrs %02i mins|\n", a->flights[i].get_identifier(), a->flights[i].get_departure_time()/60,
     a->flights[i].get_departure_time()%60, a->flights[i].Weekday(a->flights[i].get_departure_day()).c_str(), a->flights[i].get_departure_city().c_str(), a->flights[i].get_arrival_time()/60,
     a->flights[i].get_arrival_time()%60, a->flights[i].Weekday(a->flights[i].get_arrival_day()).c_str(), a->flights[i].get_arrival_city().c_str(), a->flight_time(i)/60, a->flight_time(i)%60);     
    }    
    return 0;
};