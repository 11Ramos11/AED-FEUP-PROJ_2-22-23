//
// Created by Ramos on 1/2/2023.
//

#include "CityLocal.h"
#include "../FlightMap.h"

list<AirportPTR> CityLocal::getAirports(FlightMapPtr flightMap) {

    list<AirportPTR> airports;

    for (AirportPTR airport: flightMap->getAirportsPerCity()[city])
        airports.push_back(airport);

    return airports;
}