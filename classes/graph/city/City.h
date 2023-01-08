/** @file city.h
 *  @brief Contains the city class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_CITY_H
#define AED_FEUP_PROJ_2_22_23_CITY_H

#include <string>

using namespace std;

/** @brief city struct to represent a city.
 *
 */
struct City {

    //! @brief Holds the name of the city.
    string name;

    //! @brief Holds the name of the country that the city belongs to.
    string country;

    /** Create a new city with a name and a country.
     *
     * @param name Of string type.
     * @param country Of string type.
     */
    City(string name, string country);

    /** @brief Operator overload.
     *
     * Compare if two cities have the same name
     * and if they belong to the same country.
     *
     * @param city of type const city, by reference.
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

#endif //AED_FEUP_PROJ_2_22_23_CITY_H
