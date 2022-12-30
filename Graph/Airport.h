//
// Created by Ramos on 12/30/2022.
//

#ifndef AED_FEUP_PROJ_2_22_23_AIRPORT_H
#define AED_FEUP_PROJ_2_22_23_AIRPORT_H

#include <string>
#include "FlightMap.h"

using namespace std;

struct Airline{

    string code;
    string name;
    string callSign;
    string country;
};

struct Flight {

    unordered_set<Airline> airlines;
    int destination;   // Destination node
    int distance; // An integer weight
};

struct Airport {
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;

    list<Flight> flights; // The list of outgoing flights (to other airports)
    bool visited;   // As the node been visited on a search?

    Airport( string code,string name,string city,string country,float latitude,float longitude);
    Airport(const Airport& airport);

    bool operator == (const Airport & airport) const;

    struct hashFunction;
};

#endif //AED_FEUP_PROJ_2_22_23_AIRPORT_H
