/** @file Local.h
 *  @brief Contains the Local class declaration.
 *  @author -
 *  @bug No known bugs.
 */
#ifndef AED_FEUP_PROJ_2_22_23_LOCAL_H
#define AED_FEUP_PROJ_2_22_23_LOCAL_H


#include "../Airport/Airport.h"

/** @brief Local class to represent a local.
 *
 */
class Local {

public:

    /** @brief Returns a list of airports.
     *
     * @param flightMap of FlightMapPtr type.
     * @return list<AirportPTR> of airports.
     */
    virtual list<AirportPTR > getAirports(FlightMapPtr flightMap) = 0;
};


#endif //AED_FEUP_PROJ_2_22_23_LOCAL_H
