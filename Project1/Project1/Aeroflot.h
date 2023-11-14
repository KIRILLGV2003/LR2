#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>

class AEROFLOT {
public:
    AEROFLOT();
    AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType);
    AEROFLOT(const AEROFLOT& other);
    ~AEROFLOT();

    // Методы доступа
    const std::string& getDestination() const;
    int getFlightNumber() const;
    const std::string& getAircraftType() const;

    void setDestination(const std::string& destination);
    void setFlightNumber(int flightNumber);
    void setAircraftType(const std::string& aircraftType);

private:
    std::string destination;
    int flightNumber;
    std::string aircraftType;
};

#endif // AEROFLOT_H
