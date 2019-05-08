#include "schedul.h"



void schedule::equaliser (schedule *current,const flight &a){  // this function is used just to reduce code length
    current->departure_city = a.get_departure_city();
    current->arrival_city = a.get_arrival_city();
    current->departure_day = a.get_departure_day();
    current->arrival_day = a.get_arrival_day();
    current->departure_time = a.get_departure_time();
    current->arrival_time = a.get_arrival_time();
    current->identifier = a.get_identifier();
}

int schedule::add(const flight &a){                            // adds flight into schedule
    schedule *current=this, *prev, *temp;    
    if (current->identifier == -1){     // checks if there are no flights in the schedule and if so adds first one
        equaliser(current, a);
    }
    else{
        while(current != nullptr){
            if(current->departure_time+current->departure_day*1440>(a.departure_time+a.departure_day*1440)){ 
                temp = new schedule;                
                temp->departure_city = current->get_departure_city();  // this while goes through list and adds flight with respect to its departure
                temp->arrival_city = current->get_arrival_city();
                temp->departure_day = current->get_departure_day();
                temp->arrival_day = current->get_arrival_day();
                temp->departure_time = current->get_departure_time();
                temp->arrival_time = current->get_arrival_time();
                temp->identifier = current->get_identifier();
                temp->next = current->next;
                equaliser(current, a);
                current->next = temp;
                break;
            }
            prev = current;
            current = current->next;
        }
        if (current == nullptr){             // if current flight is the latest of all it's added in the end of the list
            current = new schedule;
            equaliser(current, a);
            current->next = nullptr;
            prev->next = current;
        }
    }
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

int schedule::flight_time(){
    return (this->get_arrival_day()*1440+this->get_arrival_time()-this->get_departure_day()*1440-this->get_departure_time());
};

int schedule::get_schedule(){
    schedule *a = this;
    printf("| ID| Departure time| Departure day| Departure city| Arrival time| Arrival Day| Arrival city|    Flight time|\n");
    while (a != nullptr){
        printf("|%03i|          %02i:%02i|     %9s|%15s|        %02i:%02i|   %9s|%13s| %02i hrs %02i mins|\n", a->get_identifier(), a->get_departure_time()/60,
     a->get_departure_time()%60, a->Weekday(a->get_departure_day()).c_str(), a->get_departure_city().c_str(), a->get_arrival_time()/60,
     a->get_arrival_time()%60, a->Weekday(a->get_arrival_day()).c_str(), a->get_arrival_city().c_str(), a->flight_time()/60, a->flight_time()%60);
     a = a->next;     
    }    
    return 0;
};