/** @file Coordinates.cpp
 *  @brief Contains the Coordinates Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Coordinates.h"
#include "../FlightMap.h"

Coordinates::Coordinates(float longitude, float latitude, float radius):
    longitude(longitude), latitude(latitude), radius(radius){}

list<AirportPTR> Coordinates::getAirports(FlightMapPtr flightMap) {
    list<AirportPTR> airports;

    for (auto pair: flightMap->getAirports()) {
        AirportPTR airport = pair.second;
        if (airport->distanceTo(longitude, latitude) < radius)
            airports.push_back(airport);
    }
    return airports;
}