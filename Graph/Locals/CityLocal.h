//
// Created by Ramos on 1/2/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_CITYLOCAL_H
#define AED_FEUP_PROJ_2_22_23_CITYLOCAL_H


#include "Local.h"

class CityLocal: public Local {

private:

    City city;

public:

    CityLocal(City city);

    list<AirportPTR> getAirports(FlightMapPtr flightMap) override;
};


#endif //AED_FEUP_PROJ_2_22_23_CITYLOCAL_H
