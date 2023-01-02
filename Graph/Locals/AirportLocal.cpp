//
// Created by Ramos on 1/2/2023.
//

#include "AirportLocal.h"
#include "..\FlightMap.h"

AirportLocal::AirportLocal(std::string code): code(code){}

list<AirportPTR> AirportLocal::getAirports(FlightMapPtr flightMap) {
    list<AirportPTR> airports;
    airports.push_back(flightMap->getAirports()[code]);
}