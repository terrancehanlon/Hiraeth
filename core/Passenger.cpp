#include "Passenger.hpp"

Passenger::~Passenger(){};
Passenger::Passenger(){
    this->name = "Passenger 1";
    this->startLocation = "Town A";
    this->endLocation = "Town B";
};

std::string Passenger::getName(){
    return this->name;
};
std::string Passenger::getStartLocation(){
    return this->startLocation;
};
std::string Passenger::getEndLocation(){
    return this->endLocation;
};