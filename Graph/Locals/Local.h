//
// Created by Ramos on 1/2/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_LOCAL_H
#define AED_FEUP_PROJ_2_22_23_LOCAL_H


#include "../Airport.h"

class Local {

public:

    virtual list<AirportPTR > getAirports(FlightMapPtr flightMap) = 0;
};


#endif //AED_FEUP_PROJ_2_22_23_LOCAL_H
