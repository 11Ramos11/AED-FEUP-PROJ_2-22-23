//
// Created by Ramos on 1/2/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_AIRPORTLOCAL_H
#define AED_FEUP_PROJ_2_22_23_AIRPORTLOCAL_H


#include "Local.h"

class AirportLocal: public Local {

private:
    string code;

public:

    AirportLocal(string code);

    list<AirportPTR> getAirports(FlightMapPtr flightMap) override;
};


#endif //AED_FEUP_PROJ_2_22_23_AIRPORTLOCAL_H
