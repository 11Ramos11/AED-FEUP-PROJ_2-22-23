/** @file CityLocal.h
 *  @brief Contains the CityLocal class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_CITYLOCAL_H
#define AED_FEUP_PROJ_2_22_23_CITYLOCAL_H


#include "Local.h"
#include "../City/City.h"

/** @brief CityLocal class to represent an city local.
 *
 */
class CityLocal: public Local {

private:

    //! @brief Holds the city.
    City city;

public:

    /** Create a new CityLocal with a city.
     *
     * @param city Of Type City.
     */
    CityLocal(City city);

    /** @brief Returns a list of airports.
     *
     * @param flightMap of FlightMapPtr type.
     * @return list<AirportPTR> of airports.
     */
    list<AirportPTR> getAirports(FlightMap*  flightMap) override;
};


#endif //AED_FEUP_PROJ_2_22_23_CITYLOCAL_H
