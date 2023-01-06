//
// Created by Alberto on 05/01/2023.
//

#ifndef AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H
#define AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H

#include "../Pointers.h"

class NumbersApplication {

    DatabasePTR database;

public:

    NumbersApplication(DatabasePTR database);

    int numbersFlights(std::string code);

    int numbersAirlines(std::string code);

    int numbersCities(std::string code);

    int numbersCountries(std::string code);
};


#endif //AED_FEUP_PROJ_2_22_23_NUMBERSAPPLICATION_H
