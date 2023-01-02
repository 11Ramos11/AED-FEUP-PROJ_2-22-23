//
// Created by Ramos on 1/2/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_COORDINATES_H
#define AED_FEUP_PROJ_2_22_23_COORDINATES_H


#include "Local.h"

class Coordinates: public Local {

private:

    float longitude;
    float latitude;
    float radius;

public:

    Coordinates(float longitude, float latitude, float radius);

    list<AirportPTR> getAirports(FlightMapPtr flightMap) override;
};


#endif //AED_FEUP_PROJ_2_22_23_COORDINATES_H
