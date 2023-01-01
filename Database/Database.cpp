/** @file DataBase.cpp
 *  @brief Contains the DataBase Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "DataBase.h"
#include <sstream>
#include <fstream>
#include <unordered_set>

using namespace std;

Database::Database() = default;

void Database::readAirlines(){

    ifstream airlineFile("../resources/airlines.csv");
    string line;

    getline(airlineFile, line);

    string code,name,callSign,country;

    do {
        getline(airlineFile, code, ',');
        if (code == "") break;
        getline(airlineFile, name, ',');
        getline(airlineFile, callSign, ',');
        getline(airlineFile, country);
        airlines.insert(pair<string, Airline>(code,{code, name, callSign, country}));

    } while (true);

}



void Database::readAirports(){

    ifstream airportFile("../resources/airports.csv");
    string line;

    getline(airportFile, line);

    string code,name,cityName,country, latitude, longitude;

    do {
        getline(airportFile, code, ',');
        if (code == "") break;
        getline(airportFile, name, ',');
        getline(airportFile, cityName, ',');
        getline(airportFile, country, ',');
        getline(airportFile, latitude, ',');
        getline(airportFile, longitude);


        AirportPTR airport {new Airport (
                code, name, cityName, country, stof(latitude), stof(longitude))};

        City city {cityName, country};
        if (airportsPerCity.find(city) != airportsPerCity.end())
            airportsPerCity[city].insert(airport);

        else {
            unordered_set<Airport, Airport::hashFunction> airports;
            airports.insert(airport);
            airportsPerCity.insert(pair<City, unordered_set<Airport, Airport::hashFunction>> (city, airports));
        }
        this->airports.insert(pair<string, Airport>(code, airport));

    } while (true);

}

void Database::readFlights() {
    ifstream flightsFile("../resources/flights.csv");
    string line;

    getline(flightsFile, line);

    string originCode,destinationCode,companyCode;

    do {
        getline(flightsFile, originCode, ',');
        if (originCode == "") break;
        getline(flightsFile, destinationCode, ',');
        getline(flightsFile, companyCode);


    } while (true);
}

void Database::read() {

    readAirports();
    readAirlines();


    for (Airport airport: airportsPerCity[{"London", "Canada"}])
        std::cout << airport.name << ',' << airport.country << endl;
}

