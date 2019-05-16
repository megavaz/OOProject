#include "flight.h"

bool flight::operator == (const flight &f1) const{
   
     return((f1.departure_city == departure_city) && 
     (f1.arrival_city == arrival_city) && 
     (f1.departure_day == departure_day) && 
     (f1.departure_time == departure_time) && 
     (f1.arrival_day == arrival_day) && 
     (f1.arrival_time == arrival_time) && 
     (f1.identifier == identifier));
};

flight flight::reverse() const{
    return flight(arrival_city, departure_city,
     departure_day , arrival_day, departure_time, 
        arrival_time, identifier);
    //return this;
};


bool  flight::operator < (const flight &f1) const{
  return (arrival_time+(arrival_day-departure_day)*1440-departure_time)<
  ((f1.arrival_time+(f1.arrival_day-f1.departure_day)*1440-f1.departure_time));  
};



