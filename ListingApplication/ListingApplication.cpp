/** @file ListingApplication.cpp
 *  @brief Contains the ListingApplication Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <string>
#include "ListingApplication.h"
#include "../Database/Database.h"

ListingApplication::ListingApplication(DatabasePTR database) : database(database) {}

bool operator<(const AirportPTR &airport1, const AirportPTR &airport2) {
    return airport1->getFlights().size() < airport2->getFlights().size();
}

void ListingApplication::showTrajectories(LocalPTR origin, LocalPTR destination) {
    auto trajectories = database->getTrajectories(origin, destination);

    for (auto trajectory: trajectories) {
        cout << trajectory.first->name << "," << trajectory.first->city;

        for (Flight flight: trajectory.second) {
            AirportPTR destination = database->getAirport(flight.destinationCode);
            Airline airline = database->getAirline(flight.airlineCode);

            cout << " -> " << destination->name << ',' << destination->city;
        }
        cout << endl << "(";

        for (auto it = trajectory.second.begin(); it != trajectory.second.end(); it++) {

            Flight flight = *it;
            AirportPTR destination = database->getAirport(flight.destinationCode);
            Airline airline = database->getAirline(flight.airlineCode);

            cout << airline.name;

            if (it != --trajectory.second.end())
                cout << " , ";
        }
        cout << ")" << endl << endl;
    }
}

void ListingApplication::listFlights(std::string airportCode) {
    AirportPTR airport = database->getAirport(airportCode);

    string title = "======= " + airport->name + "'s flights =======\n";
    std::cout << title;
    std::cout << "Airline | Destination\n";

    for (Flight flight: airport->getFlights()) {
        AirportPTR destination = database->getAirport(flight.destinationCode);
        string airportName = destination->name;
        string city = destination->city;
        string country = destination->country;

        string airline = database->getAirline(flight.airlineCode).name;

        std::cout << airline << " | " << airportName << ',' << city << ',' << country << std::endl;
    }
}

void ListingApplication::listAirlines(std::string airportCode) {
    AirportPTR airport = database->getAirport(airportCode);

    string title = "======= " + airport->name + "'s available airlines =======\n";
    std::cout << title;
    std::cout << "Name, Call Sign, Country \n\n";

    unordered_set<string> airlines;

    for (Flight flight: airport->getFlights()) {
        airlines.insert(flight.airlineCode);
    }

    for (string airlineCode: airlines) {
        Airline airline = database->getAirline(airlineCode);
        std::cout << airline.name << ", " << airline.callSign << ", " << airline.country << endl;
    }
}

void ListingApplication::listCities(std::string airportCode) {
    AirportPTR airport = database->getAirport(airportCode);

    string title = "======= " + airport->name + "'s reachable countries =======\n";
    std::cout << title;
    std::cout << "Name | Country \n\n";

    unordered_set<City, City::hashFunction> cities;

    for (Flight flight: airport->getFlights()) {
        AirportPTR airport = database->getAirport(flight.destinationCode);
        cities.insert({airport->city, airport->country});
    }

    for (City city: cities) {
        std::cout << city.name << ", " << city.country << endl;
    }
}

void ListingApplication::listCountries(std::string code) {
    AirportPTR airport = database->getAirport(code);

    string title = "======= " + airport->name + "'s reachable countries =======\n";
    std::cout << title;
    std::cout << "Name \n\n";

    unordered_set<string> countries;

    for (Flight flight: airport->getFlights()) {
        AirportPTR airport = database->getAirport(flight.destinationCode);
        countries.insert(airport->country);
    }

    for (string country: countries) {
        std::cout << country << endl;
    }
}

void ListingApplication::listAirportsByCity(City city) {
    std::cout << "======= " << city.name << "'s existing Airports =======";
    std::cout << endl;
    std::cout << "Airport Name |  Airport city & country \n";

    auto airports = database->getAirportsPerCity()[city];
    for (auto airport: airports) {

        std::cout << airport->name << " | " << airport->city << ", "
                  << airport->country
                  << endl;
    }
}

void ListingApplication::globalStatistic(int k) {
    int numAirports = database->getAirports().size();
    std::cout << "Number of airports:" << numAirports << std::endl;

    int numFlights = 0;
    for (auto pair: database->getAirports()) {
        AirportPTR airport = pair.second;
        numFlights += airport->getFlights().size();
    }
    std::cout << "Number of flights: " << numFlights << std::endl;

    int numAirlines = 0;
    numAirlines = database->getAirlines().size();
    std::cout << "Number of airlines: " << numAirlines << std::endl;

    int diameter;
    diameter = database->diameter();
    std::cout << "Diameter: " << diameter << std::endl;

    priority_queue<AirportPTR> pq;
    for (auto pair: database->getAirports()) {
        AirportPTR airport = pair.second;
        pq.push(airport);
    }
    std::cout << "Airports with more flights - top" << k << ": " << std::endl;
    for (int i = 0; i <= k; i++) {
        std::cout << pq.top()->name << std::endl;
        pq.pop();
    }
}

void ListingApplication::statisticPerCountry(std::string country, int k) {
    int count = 0;
    for (auto pair: database->getAirports()) {
        AirportPTR airport = pair.second;
        if (airport->country == country) {
            count++;
        }
    }
    std::cout << "Number of airports: " << count << endl;

    int numFlights = 0;
    for (auto pair: database->getAirports()) {
        AirportPTR airport = pair.second;
        if (airport->country == country) {
            numFlights += airport->getFlights().size();
        }
    }
    std::cout << "Number of flights: " << numFlights << endl;

    unordered_set<string> airlinesCode;
    for (auto pair: database->getAirports()) {
        AirportPTR airport = pair.second;
        if (airport->country == country)
            for (auto flight: airport->getFlights()) {
                auto airlinecode = flight.airlineCode;
                airlinesCode.insert(airlinecode);
            }
    }
    std::cout << "Number of airlines: " << airlinesCode.size() << endl;

    priority_queue<AirportPTR> pq;
    for (auto pair: database->getAirports()) {
        AirportPTR airport = pair.second;
        if (airport->country == country) {
            pq.push(airport);
        }
    }
    std::cout << "Airports with more flights in " << country << "- top" << k << ":" << endl;
    for (int i = 0; i < k; i++) {
        std::cout << pq.top()->name << endl;
        pq.pop();
    }
}

void ListingApplication::showReachableAirports(LocalPTR local, int y) {
    string title = "=========== Reachable Airports ==========\n\n";

    for (AirportPTR airport: database->airportsWithMaxYFlights(local, y)) {
        cout << airport->name + "," + airport->city + "," + airport->country << endl;
    }
}

void ListingApplication::showReachableCities(LocalPTR local, int y) {
    string title = "=========== Reachable Cities ==========\n\n";

    for (City city: database->citiesWithMaxYFlights(local, y)) {
        cout << city.name + "," + city.country << endl;
    }
}

void ListingApplication::showReachableCountries(LocalPTR local, int y) {
    string title = "=========== Reachable Countries ==========\n\n";

    for (string country: database->countriesWithMaxYFlights(local, y)) {
        cout << country << endl;
    }
    cout << endl;
}

void ListingApplication::listArticulationPoints(){
    auto articulationPoints = database->getArticulationPoints();
    cout << "Airports that serve as articulation points:\n\n";

    for (AirportPTR airport: articulationPoints){
        cout << airport->name << "," << airport->city << "," << airport->country << endl;
    }
    cout << endl << "Total of " << articulationPoints.size() << " articulation points.";
}

