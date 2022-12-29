/** @file DataBase.cpp
 *  @brief Contains the DataBase Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "DataBase.h"
#include <sstream>
#include <fstream>

using namespace std;

Database::Database() = default;

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

        airports.push_back({code, name, city, country, stof(latitude), stof(longitude)});

    } while (true);

}

void Database::read() {

    readAirports();
    std::cout << "hello";
}

