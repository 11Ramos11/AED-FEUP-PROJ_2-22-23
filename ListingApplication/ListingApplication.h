//
// Created by Ramos on 1/5/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
#define AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H


#include "../application/Pointers.h"

class ListingApplication {

    DatabasePTR database;

public:

    ListingApplication(DatabasePTR database);

    void listFlights(std::string code);

    void listAirlines(std::string code);

    void listCities(std::string code);

    void listCountries(std::string code);

    void listAirportsByCity(std::string city);


};


#endif //AED_FEUP_PROJ_2_22_23_LISTINGAPPLICATION_H
