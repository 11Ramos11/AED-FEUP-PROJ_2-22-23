//
// Created by Ramos on 1/5/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
#define AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H


#include "../Pointers.h"

class ListingApplication {

    DatabasePTR database;

public:

    ListingApplication(DatabasePTR database);

    void showTrajectories(LocalPTR origin, LocalPTR destination);

    void listFlights(std::string code);

    void listAirlines(std::string code);

    void listCities(std::string code);

    void listCountries(std::string code);

    void listAirportsByCity(std::string city);

    /** @brief Listing the global statistic.
     *
     * @param k of int type.
     * @return Void.
     */
    void GlobalStatistic(int k);

    /** @brief Listing the statistic per country.
     *
     * @param country of string type.
     * @param k of int type.
     * @return Void.
     */
    void statisticPerCountry(std::string country, int k);
};


#endif //AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
