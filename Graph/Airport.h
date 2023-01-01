//
// Created by Ramos on 12/30/2022.
//

#ifndef AED_FEUP_PROJ_2_22_23_AIRPORT_H
#define AED_FEUP_PROJ_2_22_23_AIRPORT_H

#include <string>
#include <unordered_set>
#include <list>
#include <cmath>

using namespace std;

struct Airline{

    string code;
    string name;
    string callSign;
    string country;
};

struct Flight {

    string destinationCode;   // Destination node
    int distance; // An integer weight
};

class Airport {

public:
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;

    list<Flight> flights; // The list of outgoing flights (to other airports)
    bool visited;   // As the node been visited on a search?

    Airport(string code, string name, string city, string country, float latitude, float longitude);
    Airport(const Airport& airport);

    bool operator == (const Airport & airport) const;

    struct hashFunction
    {
        size_t operator()(const Airport& airport) const;
    };

    /** @brief Calculate distance between two Airports.
     *
     * Calculate the distance between latitudes and longitudes,
     * convert latitudes to radians and apply the Haversine formula.
     *
     * @param airport1 Of Airport type.
     * @param airport2 Of Airport type.
     * @return double that corresponds to the distance.
     */
    double distanteTo(const Airport& airport) const;
};

#endif //AED_FEUP_PROJ_2_22_23_AIRPORT_H
