//
// Created by Ramos on 12/30/2022.
//

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