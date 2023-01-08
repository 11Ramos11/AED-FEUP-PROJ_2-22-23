/** @file Coordinates.cpp
 *  @brief Contains the Coordinates Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Coordinates.h"
#include "../FlightMap.h"

Coordinates::Coordinates(float latitude, float longitude, float radius):
    latitude(latitude), longitude(longitude), radius(radius){}

list<AirportPTR> Coordinates::getAirports(FlightMap*  flightMap) {
    list<AirportPTR> airports;
    auto allAirports = flightMap->getAirports();

    for (auto pair: allAirports) {
        AirportPTR airport = pair.second;
        int distance = airport->distanceTo(latitude, longitude);
        
        if (distance < radius)
            airports.push_back(airport);
    }
    return airports;
}