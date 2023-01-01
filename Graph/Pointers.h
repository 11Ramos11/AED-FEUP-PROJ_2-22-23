//
// Created by Ramos on 1/1/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_POINTERS_H
#define AED_FEUP_PROJ_2_22_23_POINTERS_H

#include <memory>

class Airport; class FlightMap;

typedef std::shared_ptr<FlightMap> FlightMapPtr;
typedef std::shared_ptr<Airport> AirportPTR;

#endif //AED_FEUP_PROJ_2_22_23_POINTERS_H
