/** @file numbersApplication.h
 *  @brief Contains the numbersApplication class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H
#define AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H

#include "../../Pointers.h"

/** @brief numbersApplication class represents the most interest/important counts.
 *
 */
class NumbersApplication {

    //! @brief Holds the database.
    DatabasePTR database;

public:

    /** Creates a new numbersApplication with a database.
     *
     * @param database of DatabasePTR type.
     */
    NumbersApplication(DatabasePTR database);

    /** @brief Prints the total number of flights.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersFlights(std::string code);

    /** @brief Prints the total number of airlines.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersAirlines(std::string code);

    /** @brief Prints the total number of cities.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersCities(std::string code);

    /** @brief Prints the total number of countries.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersCountries(std::string code);

    /** @brief  number of the reachable airports from a Local.
     *
     * A local can be am airport, a city or coordinates.
     *
     * @param local Of LocalPTR type.
     * @param y Of int type.
     * @return Void.
     */
    void numberReachableAirports(LocalPTR local, int y);

    /** @brief Prints the number of the reachable cities from a Local.
     *
     * A local can be am airport, a city or coordinates.
     *
     * @param local Of LocalPTR type.
     * @param y Of int type.
     * @return Void.
     */
    void numberReachableCities(LocalPTR local, int y);

    /** @brief Prints the number of the reachable countries from a Local.
     *
     * A local can be am airport, a city or coordinates.
     *
     * @param local Of LocalPTR type.
     * @param y Of int type.
     * @return Void.
     */
    void numberReachableCountries(LocalPTR local, int y);

    /** @brief Prints the number of connected components.
     *
     * @return Void.
     */
    void showNumberOfComponents();
};

#endif //AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H
