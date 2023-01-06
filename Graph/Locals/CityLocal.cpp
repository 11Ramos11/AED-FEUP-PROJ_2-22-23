/** @file CityLocal.cpp
 *  @brief Contains the CityLocal Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "CityLocal.h"
#include "../FlightMap.h"

CityLocal::CityLocal(City city): city(city) {}

list<AirportPTR> CityLocal::getAirports(FlightMap*  flightMap) {

    list<AirportPTR> airports;

    for (AirportPTR airport: flightMap->getAirportsPerCity()[city])
        airports.push_back(airport);

    return airports;
}