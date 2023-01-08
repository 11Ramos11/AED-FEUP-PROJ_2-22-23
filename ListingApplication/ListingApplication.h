/** @file ListingApplication.h
 *  @brief Contains the ListingApplication class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
#define AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H


#include "../Pointers.h"
#include "../Graph/City/City.h"

/** @brief ListingApplication class represents the most interest/important listings.
 *
 */
class ListingApplication {

    //! @brief Holds the database.
    DatabasePTR database;

public:

    /** Creates a new ListingApplication with a database.
     *
     * @param database of DatabasePTR type.
     */
    ListingApplication(DatabasePTR database);

    /** @brief Lists the best trajectory from one local to another.
     *
     * @param origin of LocalPTR type.
     * @param destination of LocalPTR type.
     * @return Void.
     */
    void showTrajectories(LocalPTR origin, LocalPTR destination);

    /** @brief Lists the flights of an airport.
     *
     * @param airportCode of string type.
     * @return Void.
     */
    void listFlights(std::string airportCode);

    /** @brief Lists the airlines of an airport.
     *
     * @param airportCode of string type.
     * @return Void.
     */
    void listAirlines(std::string airportCode);

    /** @brief Lists the cities that an airport has flights to.
     *
     * @param airportCode of string type.
     * @return Void.
     */
    void listCities(std::string airportCode);

    /** @brief Lists the countries that an airport has flights to.
     *
     * @param code of string type.
     * @return Void.
     */
    void listCountries(std::string code);

    /** @brief Lists the airports per city.
     *
     * @param city of City type.
     * @return Void.
     */
    void listAirportsByCity(City city);

    /** @brief Lists the global statistic.
     *
     * @param k of int type.
     * @return Void.
     */
    void globalStatistic(int k);

    /** @brief Lists the statistic per country.
     *
     * @param country of string type.
     * @param k of int type.
     * @return Void.
     */
    void statisticPerCountry(std::string country, int k);

    /** @brief Lists the reachable airports from a Local.
     *
     * A local can be am airport, a city or coordinates.
     *
     * @param local Of LocalPTR type.
     * @param y Of int type.
     * @return Void.
     */
    void showReachableAirports(LocalPTR local, int y);

    /** @brief Lists the reachable cities from a Local.
     *
     * A local can be am airport, a city or coordinates.
     *
     * @param local Of LocalPTR type.
     * @param y Of int type.
     * @return Void.
     */
    void showReachableCities(LocalPTR local, int y);

    /** @brief Lists the reachable countries from a Local.
     *
     * A local can be am airport, a city or coordinates.
     *
     * @param local Of LocalPTR type.
     * @param y Of int type.
     * @return Void.
     */
    void showReachableCountries(LocalPTR local, int y);

    /** @brief Lists the articulation points.
     *
     * @return Void.
     */
    void listArticulationPoints();
};

#endif //AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
