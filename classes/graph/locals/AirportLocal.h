/** @file AirportLocal.h
 *  @brief Contains the AirportLocal class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_AIRPORTLOCAL_H
#define AED_FEUP_PROJ_2_22_23_AIRPORTLOCAL_H

#include "Local.h"

/** @brief AirportLocal class to represent an airport local.
 *
 */
class AirportLocal: public Local {

private:

    //! @brief Holds the airport code.
    string code;

public:

    /** Create a new AirportLocal with a code.
     *
     * @param code Of Type string.
     */
    AirportLocal(string code);

    /** @brief Returns a list of airports.
     *
     * @param flightMap of FlightMap type.
     * @return list<AirportPTR> of airports.
     */
    list<AirportPTR> getAirports(FlightMap*  flightMap) override;
};

#endif //AED_FEUP_PROJ_2_22_23_AIRPORTLOCAL_H
