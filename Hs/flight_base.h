#ifndef FLIGHT_BASE_H
#define FLIGHT_BASE_H
class flight_base{
    protected:
    int identifier;
    public:
    flight_base(int identifier):identifier(identifier){}
    int get_identifier() const{
        return(identifier);
    };
};
#endif