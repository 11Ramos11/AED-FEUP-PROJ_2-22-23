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

    /** @brief Print the number of airports that exists in database.
     *
     */
    void numAirportsRede();

    /** @brief Print the number of airports per country.
     *
     */
    void numAirportsPerCountry(std::string country);
};


#endif //AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
