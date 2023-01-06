/** @file Airline.h
 *  @brief Contains the Airline class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_AIRLINE_H
#define AED_FEUP_PROJ_2_22_23_AIRLINE_H

#include <string>

using namespace std;

/** @brief Airline struct to represent a airline.
 *
 */
struct Airline{

    //! @brief Holds the airline code.
    string code;

    //! @brief Holds the airline name.
    string name;

    //! @brief Holds the airline call sign.
    string callSign;

    //! @brief Holds the country that the airline belongs to.
    string country;
};


#endif //AED_FEUP_PROJ_2_22_23_AIRLINE_H
