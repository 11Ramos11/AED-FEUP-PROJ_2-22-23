/** @file DataBase.h
 *  @brief Contains the DataBase class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_DATABASE_H
#define AED_FEUP_PROJ_2_22_23_DATABASE_H

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../Graph/FlightMap.h"

struct City {
    string name;
    string country;

    bool operator == (const City& city) const {
        return name == city.name && country == city.country;
    }

    struct hashFunction {
        size_t operator()(const City& city) const {
            return hash<string>()(city.name + city.country);
        }
    };
};

/** @brief Database class to read all input files and store all information.
 *
 *  Intended to be instanced once and creates a database
 *  for use within the app.
 *  Holds prototype functions to read the following input files:
 *  "airlines.csv", "airports.csv" and "flights.csv".
 *  Stores their data accordingly.
 */
class Database {

private:

    //! @brief Holds all airports per city.
    unordered_map<City,  unordered_set<Airport, Airport::hashFunction>, City::hashFunction> airportsPerCity;

    //! @brief Holds all airports..
    unordered_map<string,  Airport> airports;

    //! @brief Holds all airlines.
    unordered_map<string,  Airline> airlines;

    /** @brief Reads airlines input file and stores them accordingly.
     *
     *  Reads the file "airlines.csv" and for each line
     *  it read a Airline code, name, its call sign and country.
     *
     *  @return Void.
     */
    void readAirlines();

    /** @brief Reads airports input file and stores them accordingly.
     *
     *  Reads the file "airports.csv" and for each line
     *  it read a Airport code and name, a name of the city and country that belongs to
     *  and its latitude and longitude.
     *  If the Airport (name of the city, name of the country) corresponds to a new Airport,
     *  it creates a new Airport object and adds it to the unordered_map of airports.
     *
     *  @return Void.
     */
    void readAirports();

public:

    /** @brief Does nothing.
     *
     */
    Database();

    /** @brief Stores all the information of the database.
     *
     * @return Void.
     */
    void read();
};

#endif //AED_FEUP_PROJ_22_23_DATABASE_H
