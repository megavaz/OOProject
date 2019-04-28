#include "flight.h"



//flight::flight(string "", string "", int 0, int 0, int 0, int 0, int 0);

 bool flight::operator == (const flight &f1) const{
     if ((f1.departure_city == departure_city) && 
     (f1.arrival_city == arrival_city) && 
     (f1.departure_day == departure_day) && 
     (f1.departure_time == departure_time) && 
     (f1.arrival_city == arrival_city) && 
     (f1.arrival_time == arrival_time) && 
     (f1.identifier == identifier))
         return true;
    else return false;
};

  flight flight::reverse(flight f) {
    string temporary;
    temporary = f.departure_city;
    departure_city = f.arrival_city;
    arrival_city = temporary;
    return f;
};
 bool  flight::operator < (const flight &f1) const{
    return (arrival_time+(arrival_day-departure_day)*1440-departure_time)<
    ((f1.arrival_time+(f1.arrival_day-f1.departure_day)*1440-f1.departure_time)
   );
};


