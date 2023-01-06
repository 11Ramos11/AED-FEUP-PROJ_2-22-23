/** @file Coordinates.h
 *  @brief Contains the Coordinates class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_COORDINATES_H
#define AED_FEUP_PROJ_2_22_23_COORDINATES_H


#include "Local.h"

/** @brief Coordinates class to represent distances.
 *
 */
class Coordinates: public Local {

private:

    //! @brief Holds the longitude.
    float longitude;

    //! @brief Holds the latitude.
    float latitude;

    //! @brief Holds the radius.
    float radius;

public:

    /** Create a new Coordinates with a longitude, a latitude and a radius.
     *
     * @param longitude Of type float.
     * @param latitude Of type float.
     * @param radius Of type float.
     */
    Coordinates(float latitude, float longitude, float radius);

    /** @brief Returns a list of airports.
     *
     * @param flightMap of FlightMapPtr type.
     * @return list<AirportPTR> of airports.
     */
    list<AirportPTR> getAirports(FlightMap* flightMap) override;
};


#endif //AED_FEUP_PROJ_2_22_23_COORDINATES_H
