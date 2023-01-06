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

void FlightMap::bfs(const string &code) {

    for (auto pair: airports)
        pair.second->visited = false;

    queue<string> unvisitedNodes;
    unvisitedNodes.push(code);
    airports[code]->visited = true;

    while (!unvisitedNodes.empty()) {
        string code2 = unvisitedNodes.front();
        unvisitedNodes.pop();

        for (auto flight: airports[code2]->flights) {
            string destination = flight.destinationCode;
            if (!airports[destination]->visited) {
                unvisitedNodes.push(destination);
                airports[destination]->visited = true;
            }
        }
    }
}

int FlightMap::mininumDistance(AirportPTR airportDepart, AirportPTR airportDestination){
    for (auto pair: airports){
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

        if (previousAirport->code == "CDG")
            cout << "hello";

        for (auto flight: previousAirport->flights){


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

list<list<AirportPTR>>
FlightMap::getPaths(AirportPTR airportDepart, AirportPTR airportDestination, unordered_set<string> airlines) {

    list<list<AirportPTR>> paths;
    int minimumFlights = mininumDistance(airportDepart, airportDestination);

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
    airportDepart->path.push_back(airportDepart);

    while (!unvisitedAirports.empty()) {
        AirportPTR previousAirport = unvisitedAirports.front();
        unvisitedAirports.pop();

        for (auto flight: previousAirport->flights) {
            AirportPTR destination = airports[flight.destinationCode];

            // if (airlines.find(flight.airlineCode) == airlines.end()) continue;

            if (flight.destinationCode == airportDestination->code) {
                destination->path = previousAirport->path;
                destination->path.push_back(destination);
                paths.push_back(destination->path);
                break;
            }

            if (!destination->visited) {

                destination->visited = true;
                if (previousAirport->dist + 1 == minimumFlights)
                    continue;

                unvisitedAirports.push(destination);
                destination->dist = previousAirport->dist + 1;
                destination->path = previousAirport->path;
                destination->path.push_back(destination);
            }

        }
    }

    return paths;
}

void getAllFlights(list<list<Flight>> &trajectories, string finalDestination, list<Flight> trajectory,
                   list<AirportPTR>::iterator airportIT) {

    AirportPTR airport = *airportIT;
    auto nextAirport = airportIT;
    ++nextAirport;


    for (Flight flight: airport->flights) {

        auto backup = trajectory;

        if (!(flight.destinationCode == (*nextAirport)->code))
            continue;

        trajectory.push_back(flight);

        if ((*nextAirport)->code == finalDestination)
            trajectories.push_back(trajectory);

        else
            getAllFlights(trajectories, finalDestination, trajectory, nextAirport);


        trajectory = backup;

    }
}

list<list<Flight>> FlightMap::bestFlights(list<list<AirportPTR>> paths, string finalDestination) {

    list<list<Flight>> trajectories;
    for (auto pathIT = paths.begin(); pathIT != paths.end(); pathIT++) {

        list<Flight> trajectory = {};

        getAllFlights(trajectories, finalDestination, trajectory, pathIT->begin());
    }

    return trajectories;
}

list<list<Flight>> FlightMap::getFlights(AirportPTR airport, AirportPTR destination, unordered_set<string> airlines) {
    auto paths = getPaths(airport, destination, airlines);

    auto trajectories = bestFlights(paths, destination->code);

    return trajectories;
}

list<list<Flight>> FlightMap::getFlights(LocalPTR origin, LocalPTR destination, unordered_set<string> airlines) {

    list<list<Flight>> trajectories;

    for (const AirportPTR& originAirport: origin->getAirports(this))
        for (const AirportPTR& destAirport: destination->getAirports(this))
            for (const auto& trajectory: getFlights(originAirport, destAirport, airlines))
                trajectories.push_back(trajectory);

    return trajectories;
}

int FlightMap::numDifferentCountries(AirportPTR airportPtr) {
    list<string> countries;
    auto airportcode = airportPtr->code;
    for (auto pair: airports) {
        for (auto edge: pair.second->flights) {
            string destinationCode = edge.destinationCode;
            if (destinationCode == airportcode) {
                auto country = pair.second->country;
                if (std::find(countries.begin(),
                              countries.end(), country) == countries.end()) {
                    countries.push_back(country);
                }
            }
        }
    }
    return countries.size();
}

list<AirportPTR> FlightMap::reachableAirports(AirportPTR airportPtr, int y) {
    queue<AirportPTR> airports_code;
    list<AirportPTR> airportsVisited;
    airports_code.push(airportPtr);
    airportPtr->visited = true;
    int count = 0;
    while (!airports_code.empty()) {
        auto airport = airports_code.front();
        airports_code.pop();
        for (auto edge: airport->flights) {
            auto destination = edge.destinationCode;
            if (airports[destination]->visited == false) {
                airports_code.push(airports[destination]);
                airportsVisited.push_back(airports[destination]);
                airports[destination]->visited = true;
                count++;
                if (count >= y) break;
            }
        }
    }
    return airportsVisited;
}

int FlightMap::airportsMaxYFlights(AirportPTR airportPtr, int y) {
    return reachableAirports(airportPtr, y).size();
}

int FlightMap::citiesMaxYFlights(City city, int y) {
    list<AirportPTR> allAirports;
    for (AirportPTR airportptr: airportsPerCity[city]) {
        list<AirportPTR> airports = reachableAirports(airportptr, y);
        for (auto airport: airports) {
            allAirports.push_back(airport);
        }
    }
    list<string> cityName;
    for (auto airport: allAirports) {
        auto city = airport->city;
        if (find(cityName.begin(), cityName.end(), city) == cityName.end())
            cityName.push_back(city);
    }
    return cityName.size();
}

int FlightMap::countriesMaxYFlights(string country, int y) {
    list<AirportPTR> allAirports;
    for (auto pair: airports) {
        if (pair.second->country == country) {
            list<AirportPTR> airports = reachableAirports(pair.second, y);
            for (auto airport: airports) {
                allAirports.push_back(airport);
            }
        }
    }
    list<string> countryName;
    for (auto airport: allAirports) {
        auto country = airport->country;
        if (find(countryName.begin(), countryName.end(), country) == countryName.end())
            countryName.push_back(country);
    }
    return countryName.size();
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
