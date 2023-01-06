/** @file AirportLocal.cpp
 *  @brief Contains the AirportLocal Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "AirportLocal.h"
#include "..\FlightMap.h"

AirportLocal::AirportLocal(std::string code): code(code){}

list<AirportPTR> AirportLocal::getAirports(FlightMap*  flightMap) {
    list<AirportPTR> airports;
    airports.push_back(flightMap->getAirports()[code]);
    return airports;
}