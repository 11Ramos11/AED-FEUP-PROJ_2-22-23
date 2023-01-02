/** @file Data.h
 *  @brief Contains the Data class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_DATA_H
#define AED_FEUP_PROJ_2_22_23_DATA_H

#include <string>
#include <list>

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

/** @brief Flight struct to represent a flight.
 *
 */
struct Flight {

    //! @brief Holds the destination code of the flight.
    string destinationCode;

    //! @brief Holds the flight distance.
    int distance;

    //! @brief Holds the airline that can be used to the flight.
    string airlineCode;
};

struct City {

    //! @brief Holds the name of the city.
    string name;

    //! @brief Holds the name of the country that the city belongs to.
    string country;

    /** @brief Operator overload.
     *
     * Compare if two cities have the same name
     * and if they belong to the same country.
     *
     * @param city of type const City.
     * @return True if the names and the counties are equals.
     */
    bool operator == (const City& city) const {
        return name == city.name && country == city.country;
    }

    /** @brief Hash function implementation.
     *
     */
    struct hashFunction {
        size_t operator()(const City& city) const {
            return hash<string>()(city.name + city.country);
        }
    };
};

#endif //AED_FEUP_PROJ_2_22_23_DATA_H
