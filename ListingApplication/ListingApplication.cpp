//
// Created by Ramos on 1/5/2023.
//

#include <string>
#include "ListingApplication.h"
#include "../Database/Database.h"

ListingApplication::ListingApplication(DatabasePTR database): database(database){}

void ListingApplication::listFlights(std::string code){

    AirportPTR airport = database->getAirport(code);

    string title = "======= " + airport->name + "'s flights =======\n";
    std::cout << title;

    std::cout << "Airline | Destination\n";


    for (Flight flight: airport->getFlights()){

        AirportPTR destination = database->getAirport(flight.destinationCode);
        string airportName = destination->name;
        string city = destination->city;
        string country = destination->country;

        string airline = database->getAirline(flight.airlineCode).name;

        std::cout << airline << " | " << airportName << ',' << city << ',' << country << std::endl;
    }

}

void ListingApplication::listAirlines(std::string code){

    AirportPTR airport = database->getAirport(code);

    string title = "======= " + airport->name + "'s available airlines =======\n";
    std::cout << title;

    std::cout << "Name, Call Sign, Country \n\n";

    unordered_set<string> airlines;

    for (Flight flight: airport->getFlights()){

        airlines.insert(flight.airlineCode);
    }

    for (string airlineCode: airlines){

        Airline airline = database->getAirline(airlineCode);
        std::cout << airline.name << ", " << airline.callSign << ", " << airline.country << endl;
    }
}

void ListingApplication::listCities(std::string code){

    AirportPTR airport = database->getAirport(code);

    string title = "======= " + airport->name + "'s reachable countries =======\n";
    std::cout << title;

    std::cout << "Name | Country \n\n";

    unordered_set<City, City::hashFunction> cities;

    for (Flight flight: airport->getFlights()){

        AirportPTR airport = database->getAirport(flight.destinationCode);

        cities.insert({airport->city, airport->country});
    }

    for (City city: cities){

        std::cout << city.name << ", " << city.country << endl;
    }
}

void ListingApplication::listCountries(std::string code){

    AirportPTR airport = database->getAirport(code);

    string title = "======= " + airport->name + "'s reachable countries =======\n";
    std::cout << title;

    std::cout << "Name \n\n";

    unordered_set<string> countries;

    for (Flight flight: airport->getFlights()){

        AirportPTR airport = database->getAirport(flight.destinationCode);

        countries.insert(airport->country);
    }

    for (string country: countries){

        std::cout << country << endl;
    }
}