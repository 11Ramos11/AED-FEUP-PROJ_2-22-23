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
#include <unordered_set>
#include "Airport.h"

using namespace std;

/** @brief FlightMap class to represent a flight map.
 *
 */
class FlightMap {

    //! @brief Holds the number of airports.
    int airportNumber;

    //! @brief Holds the possible airports.
    vector<Airport> airports;

public:

    /** Create a new FlightMap with an airport number.
     *
     * @param airportNumber Of Type int.
     */
    FlightMap(int airportNumber);

    // Add edge from source to destination with a certain weight
    void addFlight(int src, int dest, Airline airline);

    // Depth-First Search: example implementation
    void dfs(int v);

    // Breadth-First Search: example implementation
    void bfs(int v);
};

#endif
