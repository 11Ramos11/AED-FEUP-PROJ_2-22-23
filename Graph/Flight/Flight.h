/** @file Flight.h
 *  @brief Contains the Flight class declaration.
 *  @author -
 *  @bug No known bugs.
 */
#ifndef AED_FEUP_PROJ_2_22_23_FLIGHT_H
#define AED_FEUP_PROJ_2_22_23_FLIGHT_H

using namespace std;

#include <string>

/** @brief Flight struct to represent a flight.
 *
 */
struct Flight {

    //! @brief Holds the destination code of the flight.
    string destinationCode;

    //! @brief Holds the airline that can be used to the flight.
    string airlineCode;
};


#endif //AED_FEUP_PROJ_2_22_23_FLIGHT_H
