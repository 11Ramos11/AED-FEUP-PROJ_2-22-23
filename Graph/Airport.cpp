/** @file Airport.cpp
 *  @brief Contains the Airport Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude):
code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}

Airport::Airport(const Airport& airport) {
    this->code = airport.code;
    this->name = airport.name;
    this->city = airport.city;
    this->country = airport.country;
    this->latitude = airport.latitude;
    this->longitude = airport.longitude;
}

bool Airport::operator == (const Airport& airport) const
{
    return this->code == airport.code;
}

size_t Airport::hashFunction::operator()(const Airport &airport) const {

    return hash<string>()(airport.code);
}

const double distanceBetweenAirports(Airport airport1, Airport airport2){

    double distanceLat = (airport2.latitude - airport1.latitude) * M_PI / 180.0;
    double distanceLon = (airport2.longitude - airport1.longitude) * M_PI / 180.0;

    airport1.latitude = (airport1.latitude) * M_PI / 180.0;
    airport2.latitude = (airport2.latitude) * M_PI / 180.0;
    double a = pow(sin(distanceLat / 2), 2) + pow(sin(distanceLon / 2), 2) *
            cos(airport1.latitude) * cos(airport2.latitude);
    double earthRadius = 6371;
    double b = 2 * asin(sqrt(a));
    return earthRadius * b;
}
