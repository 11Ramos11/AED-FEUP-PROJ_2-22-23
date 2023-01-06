//
// Created by Alberto on 05/01/2023.
//
#include <string>
#include "NumbersApplication.h"
#include "../Database/Database.h"

NumbersApplication::NumbersApplication(DatabasePTR database) : database(database) {}

int NumbersApplication::numbersFlights(std::string code) {
    AirportPTR airport = database->getAirport(code);
    return airport->getnumFlights();
}

int NumbersApplication::numbersAirlines(std::string code) {
    AirportPTR airport = database->getAirport(code);
    unordered_set<string> airlines;
    for (Flight flight: airport->getFlights()) {
        airlines.insert(flight.airlineCode);
    }
    for (string airlineCode: airlines) {
        for (Flight flight: airport->getFlights()) {
            airlines.insert(flight.airlineCode);
        }
    }
    return airlines.size();
}

int NumbersApplication::numbersCities(std::string code) {
    AirportPTR airport = database->getAirport(code);
    unordered_set<City, City::hashFunction> cities;
    for (Flight flight: airport->getFlights()) {
        for (Flight flight: airport->getFlights()) {
            AirportPTR airport = database->getAirport(flight.destinationCode);
            cities.insert({airport->city, airport->country});
        }
    }
    return cities.size();
}

int NumbersApplication::numbersCountries(std::string code) {
    AirportPTR airport = database->getAirport(code);
    unordered_set<string> countries;
    for (Flight flight: airport->getFlights()) {
        for (Flight flight: airport->getFlights()) {
            AirportPTR airport = database->getAirport(flight.destinationCode);
            countries.insert(airport->country);
        }
    }
    return countries.size();
}