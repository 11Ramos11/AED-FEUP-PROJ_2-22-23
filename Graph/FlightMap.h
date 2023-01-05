/** @file FlightMap.h
 *  @brief Contains the FlightMap class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_FLIGHTMAP_H
#define AED_FEUP_PROJ_2_22_23_FLIGHTMAP_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include "Airport/Airport.h"
#include "Locals/Local.h"
#include "City/City.h"

using namespace std;

//! @brief Redefinition of the name for ease of use.
typedef unordered_map<City,  unordered_set<AirportPTR, Airport::hashFunction>, City::hashFunction> AirportsPerCity_Set;

/** @brief FlightMap class to represent a flight map.
 *
 */
class FlightMap {

    //! @brief Holds all airports.
    unordered_map<string,  AirportPTR> airports;

    //! @brief Holds the airports per city.
    AirportsPerCity_Set airportsPerCity;

public:

    /** Create a new FlightMap.
     *
     * Does nothing.
     */
    FlightMap();

    /** @brief Sets the airports to the given argument.
     *
     * @param airports of const unordered_map<string,  AirportPTR> type.
     * @return Void.
     */
    void setAirports(const unordered_map<string,  AirportPTR> airports);

    /** @brief Returns the airports.
     *
     * @return unordered_map<string,  AirportPTR> of airports.
     */
    unordered_map<string,  AirportPTR> getAirports();

    /** @brief Returns the airports per city.
     *
     * @return AirportsPerCity_Set of airports.
     */
    AirportsPerCity_Set getAirportsPerCity();

    /** @brief Sets the airportsPerCity to the given argument.
     *
     * @param airports of const unordered_map<City,  unordered_set<AirportPTR>> type.
     * @return Void.
     */
    void setAirportsPerCity(AirportsPerCity_Set airportsPerCity);

    /** @brief Depth-First Search implementation.
     *
     * @param code of string type.
     * @return Void.
     */
    void dfs(string code);

    /** @brief Breadth-First Search implementation.
     *
     * @param code of const string type.
     * @return Void.
     */
    void bfs(const string& code);

    /** @brief Returns all lists with minors airport paths.
     *
     * It uses BFS implementation.
     *
     * @param airportDepart of AirportPTR type.
     * @param airportDestination of AirportPTR type.
     * @return One or more lists with the minors airport paths.
     */
    list<list<AirportPTR>> getPaths(AirportPTR airportDepart, AirportPTR airportDestination, unordered_set<string> airlines);

    /** @brief Returns the best set of flights that can be used to fly from one airport to another.
     *
     * It uses the return of the "getPaths" method and leach all the lists, keeping only the best of the best ones.
     *
     * @param paths of list<list<AirportPTR>> type.
     * @param destinationCode of string type.
     * @return The best set of flights.
     */
    list<list<Flight>> bestFlights(list<list<AirportPTR>> paths, string destinationCode);

    /** @brief Represents the number of different countries of the flights that arrived at the airport.
     *
     * @param airportPtr of AirportPTR type.
     * @return Number of different countries.
     */
    int numDifferentCountries(AirportPTR airportPtr);

    /** @brief Represents the minor flights using an specific airport.
     *
     * @param airport of AirportPTR type.
     * @param destination of AirportPTR type.
     * @param airlines of unordered_set<string> type.
     * @return list<list<Flight>> of flights.
     */
    list<list<Flight>> getFlights(AirportPTR airport, AirportPTR destination, unordered_set<string> airlines);

    /** @brief Represents the minor flights using an specific local.
     *
     * The local can be an airport, a city or a pair of coordinates.
     *
     * @param origin of Local type.
     * @param destination of Local type.
     * @param airlines of unordered_set<string> type.
     * @return list<list<Flight>> of flights.
     */
    list<list<Flight>> getFlights(Local* origin, Local* destination, unordered_set<string> airlines);

    /** @brief Represents all airports that can be reachable from another specific one.
     *
     * It uses the BFS implementation.
     *
     * @param airportPtr of AirportPTR type.
     * @param y of int type.
     * @return list<AirportPTR> of airports.
     */
    list<AirportPTR> reachableAirports(AirportPTR airportPtr, int y);

    /** @brief Represents the number of reachable airports , using a maximum number of flights.
     *
     * It uses the "reachableAirports" method.
     *
     * @param airportPtr of AirportPTR type.
     * @param y of int type.
     * @return Number of airports.
     */
    int airportsMaxYFlights(AirportPTR airportPtr, int y);

    /** @brief Represents the number of reachable cities , using a maximum number of flights.
     *
     * It uses the "reachableAirports" method.
     *
     * @param city of City type.
     * @param y of int type.
     * @return Number of cities.
     */
    int citiesMaxYFlights(City city, int y);

    /** @brief Represents the number of reachable countries, using a maximum number of flights.
     *
     * It uses the "reachableAirports" method.
     *
     * @param country of string type.
     * @param y of int type.
     * @return Number of countries.
     */
    int countriesMaxYFlights(string country, int y);
};

#endif
