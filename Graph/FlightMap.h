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
#include "Airport.h"

using namespace std;

/** @brief FlightMap class to represent a flight map.
 *
 */
class FlightMap {

    //! @brief Holds all airports.
    unordered_map<string,  AirportPTR> airports;

public:

    /** Create a new FlightMap with an airport number.
     *
     * @param airportNumber Of Type int.
     */
    FlightMap();

    void setAirports(const unordered_map<string,  AirportPTR> airports);

    // Add edge from source to destination with a certain weight
    void addFlight(string originCode, string destinationCode, Airline airline);

    // Depth-First Search: example implementation
    void dfs(string code);

    // Breadth-First Search: example implementation
    void bfs(const string& code);

    list<list<AirportPTR>> getPaths(AirportPTR airportDepart, AirportPTR airportDestination);

    list<list<Flight>> bestFlights(list<list<AirportPTR>> paths, string destinationCode);
};

#endif
