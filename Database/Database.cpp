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
/*
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
        airlines.push_back({code, name, callSign, country});

    } while (true);

}*/



void Database::readAirports(){

    ifstream airportFile("../resources/airports.csv");
    string line;

    getline(airportFile, line);

    string code,name,city,country, latitude, longitude;

    do {
        getline(airportFile, code, ',');
        if (code == "") break;
        getline(airportFile, name, ',');
        getline(airportFile, city, ',');
        getline(airportFile, country, ',');
        getline(airportFile, latitude, ',');
        getline(airportFile, longitude);

      //  unordered_set<Airport, Airport::hashFunction> airports;

      //  Airport airport (code, name, city, country, stof(latitude), stof(longitude));
      //  airports.insert(airport);

      //  airportsPerCity.insert(pair<string, unordered_set<Airport, Airport::hashFunction>> (city, airports));

    } while (true);

}

void Database::read() {

    readAirports();
    readAirlines();
    std::cout << "hello";
}

