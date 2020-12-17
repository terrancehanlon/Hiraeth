#ifndef PASSENGER_HPP
#define PASSENGER_HPP


#include <string>

class Passenger {

    private:
        std::string name;
        std::string type;
        std::string startLocation;
        std::string endLocation;

    public:

        Passenger();
        ~Passenger();

        std::string getName();
        std::string getStartLocation();
        std::string getEndLocation();


};

#endif