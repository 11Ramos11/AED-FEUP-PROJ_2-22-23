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

    std::cout << ('=' * title.size()) << endl;

}