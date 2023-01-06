/** @file NumbersApplication.h
 *  @brief Contains the NumbersApplication class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H
#define AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H

#include "../Pointers.h"

/** @brief NumbersApplication class represents the most interest/important counts.
 *
 */
class NumbersApplication {

    //! @brief Holds the database.
    DatabasePTR database;

public:

    /** Creates a new NumbersApplication with a database.
     *
     * @param database of DatabasePTR type.
     */
    NumbersApplication(DatabasePTR database);

    /** @brief Print the total number of flights.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersFlights(std::string code);

    /** @brief Print the total number of airlines.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersAirlines(std::string code);

    /** @brief Print the total number of cities.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersCities(std::string code);

    /** @brief Print the total number of countries.
     *
     * @param code of string type.
     * @return an int number.
     */
    int numbersCountries(std::string code);
};


#endif //AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H
