#include "Aeroflot.h"

AEROFLOT::AEROFLOT() : flightNumber(0) {
    std::cout << "Default constructor called for AEROFLOT." << std::endl;
}

AEROFLOT::AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType)
    : destination(destination), flightNumber(flightNumber), aircraftType(aircraftType) {
    std::cout << "Parameterized constructor called for AEROFLOT." << std::endl;
}

AEROFLOT::AEROFLOT(const AEROFLOT& other) : destination(other.destination), flightNumber(other.flightNumber), aircraftType(other.aircraftType) {
    std::cout << "Copy constructor called for AEROFLOT." << std::endl;
}

AEROFLOT::~AEROFLOT() {
    std::cout << "Destructor called for AEROFLOT." << std::endl;
}

// Методы доступа
const std::string& AEROFLOT::getDestination() const {
    return destination;
}

int AEROFLOT::getFlightNumber() const {
    return flightNumber;
}

const std::string& AEROFLOT::getAircraftType() const {
    return aircraftType;
}

void AEROFLOT::setDestination(const std::string& destination) {
    this->destination = destination;
}

void AEROFLOT::setFlightNumber(int flightNumber) {
    this->flightNumber = flightNumber;
}

void AEROFLOT::setAircraftType(const std::string& aircraftType) {
    this->aircraftType = aircraftType;
}
