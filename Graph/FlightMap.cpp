/** @file FlightMap.cpp
 *  @brief Contains the FlightMap Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "FlightMap.h"
#include "Locals/Local.h"
#include <algorithm>
#include <stack>
#include <string>

FlightMap::FlightMap() {}

void FlightMap::setAirports(const unordered_map<string, AirportPTR> airports) {
    this->airports = airports;
}

unordered_map<string, AirportPTR> FlightMap::getAirports() {
    return airports;
}

void FlightMap::setAirportsPerCity(AirportsPerCity_Set airportsPerCity) {
    this->airportsPerCity = airportsPerCity;
}

AirportsPerCity_Set FlightMap::getAirportsPerCity() {
    return airportsPerCity;
}

int FlightMap::minimumDistance(AirportPTR airportDepart, AirportPTR airportDestination, unordered_set<string> airlines){
    for (auto pair: airports) {
        AirportPTR airport = pair.second;
        airport->visited = false;
        airport->dist = 0;
    }

    queue<AirportPTR> unvisitedAirports;
    unvisitedAirports.push(airportDepart);
    airportDepart->visited = true;

    while (!unvisitedAirports.empty()) {
        AirportPTR previousAirport = unvisitedAirports.front();
        unvisitedAirports.pop();

        if (previousAirport->code == "JFK" || previousAirport->code == "EWR")
            cout << "hello";

        for (auto flight: previousAirport->flights) {

            if (airlines.find(flight.airlineCode) == airlines.end())
                continue;

            AirportPTR destination = airports[flight.destinationCode];

            if (!destination->visited) {
                destination->dist = previousAirport->dist + 1;
                unvisitedAirports.push(destination);
                destination->visited = true;

                if (flight.destinationCode == airportDestination->code)
                    return destination->dist;
            }
        }
    }
    return -1;
}

list<list<Flight>>
FlightMap::getTrajectories(AirportPTR airportDepart, AirportPTR airportDestination, unordered_set<string> airlines, int minimumFlights) {

    list<list<Flight>> paths;

    for (auto pair: airports) {
        AirportPTR airport = pair.second;
        airport->visited = false;
        airport->path = {};
        airport->dist = 0;
    }

    queue<AirportPTR> unvisitedAirports;
    unvisitedAirports.push(airportDepart);
    airportDepart->visited = true;
    airportDepart->dist = 0;

    while (!unvisitedAirports.empty()) {
        AirportPTR previousAirport = unvisitedAirports.front();
        unvisitedAirports.pop();

        if (previousAirport->code == "CLT")
            cout << "hello";

        for (auto flight: previousAirport->flights) {
            AirportPTR destination = airports[flight.destinationCode];

            if (airlines.find(flight.airlineCode) == airlines.end())
                continue;

            if (flight.destinationCode == airportDestination->code) {
                destination->path = previousAirport->path;
                destination->path.push_back(flight);
                paths.push_back(destination->path);
            }

            if (!destination->visited) {

                destination->visited = true;
                if (previousAirport->dist + 1 >= minimumFlights)
                    continue;

                unvisitedAirports.push(destination);
                destination->dist = previousAirport->dist + 1;
                destination->path = previousAirport->path;
                destination->path.push_back(flight);
            }

        }
    }
    return paths;
}

list<pair<AirportPTR, list<Flight>>> FlightMap::getFlights(LocalPTR origin, LocalPTR destination, unordered_set<string> airlines) {

    list<pair<AirportPTR, list<Flight>>> trajectoriesPairs;
    int minimum;

    for (const AirportPTR &originAirport: origin->getAirports(this))
        for (const AirportPTR &destAirport: destination->getAirports(this))
            minimum = minimumDistance(originAirport, destAirport, airlines);

    for (const AirportPTR &originAirport: origin->getAirports(this))
        for (const AirportPTR &destAirport: destination->getAirports(this)) {
            auto trajectories = getTrajectories(originAirport, destAirport, airlines, minimum);
            for (const auto &trajectory: trajectories)
                trajectoriesPairs.push_back(make_pair(originAirport, trajectory));
        }

    return trajectoriesPairs;
}

unordered_set<AirportPTR> FlightMap::reachableAirports(AirportPTR airportPtr, int y) {

    for (auto pair: airports){
        AirportPTR airport = pair.second;
        airport->visited = false;
        airport->dist = 0;
    }

    queue<AirportPTR> airportsToVisit;
    unordered_set<AirportPTR> reachableAirports;
    airportsToVisit.push(airportPtr);
    airportPtr->visited = true;

    while (!airportsToVisit.empty()) {
        auto previousAirport = airportsToVisit.front();
        airportsToVisit.pop();

        for (auto flight: previousAirport->flights) {
            auto destination = airports[flight.destinationCode];

            if (destination->visited)
                continue;

            destination->dist = previousAirport->dist + 1;

            if (destination->dist > y)
                return reachableAirports;

            airportsToVisit.push(destination);
            reachableAirports.insert(destination);
            destination->visited = true;
        }
    }
    return reachableAirports;
}

unordered_set<AirportPTR> FlightMap::airportsWithMaxYFlights(LocalPTR origin, int y){

    unordered_set<AirportPTR> airports;
    for (AirportPTR airport: origin->getAirports(this)) {

        for (AirportPTR destination: reachableAirports(airport, y)) {
            airports.insert(destination);
        }
    }
    return airports;
}

unordered_set<City, City::hashFunction> FlightMap::citiesWithMaxYFlights(LocalPTR origin, int y){

    unordered_set<City, City::hashFunction> cities;
    for (AirportPTR airport: origin->getAirports(this)) {

        for (AirportPTR destination: reachableAirports(airport, y)) {
            City city = {destination->city, airport->country};
            cities.insert(city);
        }
    }
    return cities;
}

unordered_set<string> FlightMap::countriesWithMaxYFlights(LocalPTR origin, int y){

    unordered_set<string> countriesNames;
    for (AirportPTR airport: origin->getAirports(this)) {

        auto airports = reachableAirports(airport, y);

        for (AirportPTR destination: airports) {
            string country = destination->country;
            countriesNames.insert(country);
        }
    }
    return countriesNames;
}

void
FlightMap::dfsArticulationPoints(AirportPTR airport, int &index, stack<AirportPTR> &stack, list<AirportPTR> &answer) {
    airport->visited = true;
    airport->num = airport->low = index++;
    stack.push(airport);
    airport->inStack = true;

    int children = 0;
    bool articulation = false;

    for (Flight e: airport->flights) {
        string w = e.destinationCode;
        AirportPTR destination = airports[w];
        if (destination->visited == false) {
            children++;
            dfsArticulationPoints(destination, index, stack, answer);
            airport->low = min(airport->low, destination->low);
            if (destination->low >= airport->num) articulation = true;
        } else if (airports[w]->inStack) {
            airport->low = min(airport->low, destination->num);
        }
    }
    if ((airport->num == 1 && children > 1) || (airport->num > 1 && articulation)) {
        AirportPTR w;
        do {
            w = stack.top();
            stack.pop();
            airport->inStack = false;
        } while (w != airport);
        answer.push_front(w);
    }
}

list<AirportPTR> FlightMap::articulationPoints() {
    list<AirportPTR> answer;
    for (auto pair: airports) {
        AirportPTR airport = pair.second;
        airport->visited = false;
        airport->low = 0;
        airport->num = 0;
        airport->inStack = false;
    }

    int index = 1;
    stack<AirportPTR> stack;
    for (auto pair: airports) {
        AirportPTR airport = pair.second;
        if (airport->visited == false) {
            dfsArticulationPoints(airport, index, stack, answer);
        }
    }
    return answer;
}

AirportPTR farthestNode;

void FlightMap::dfsUtil(AirportPTR airport, int &count, int &maxCount) {
    airport->visited = true;
    count++;
    for (Flight flight: airport->flights) {
        string w = flight.destinationCode;
        AirportPTR destination = airports[w];
        if (destination->visited == false) {
            if (count >= maxCount) {
                maxCount = count;
                farthestNode = destination;
            }
            dfsUtil(destination, count, maxCount);
        }
    }
}

void FlightMap::dfsDiameter(AirportPTR airport, int &maxCount) {
    int count = 0;

    for (auto pair: airports) {
        AirportPTR airport = pair.second;
        airport->visited = false;
    }
    count++;
    dfsUtil(airport, count, maxCount);
}

int FlightMap::diameter() {
    int maxCount = INT_MIN;
    AirportPTR airport;

    dfsDiameter(airport, maxCount);
    dfsDiameter(farthestNode, maxCount);

    return maxCount;
}

void FlightMap::dfs(AirportPTR airport) {
    airport->visited = true;
    for (Flight flight: airport->flights) {
        AirportPTR destination = airports[flight.destinationCode];
        if(!destination->visited)
            dfs(destination);
    }
}



int FlightMap::connectedComponents() {
    int counter = 0;
    for(auto pair: airports)
        pair.second->visited = false;

    for(auto pair: airports)
    if(!pair.second->visited) {
        counter ++;
        dfs(pair.second);
    }
    return counter;
}