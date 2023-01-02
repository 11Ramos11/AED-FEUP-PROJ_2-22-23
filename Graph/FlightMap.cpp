/** @file FlightMap.cpp
 *  @brief Contains the FlightMap Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "FlightMap.h"
#include <algorithm>

FlightMap::FlightMap() {}

void FlightMap::setAirports(const unordered_map<string,  AirportPTR> airports) {
    this->airports = airports;
}

int calculateDistance(){
    return 0;
}

void FlightMap::dfs(string code) {
    // show node order
    // cout << v << " ";
    if (airports.find(code) != airports.end())
        airports[code]->visited = true;

    for (auto e : airports[code]->flights) {
        string destinationCode = e.destinationCode;
        if (!airports[code]->visited)
            dfs(destinationCode);
    }
}

void FlightMap::bfs(const string& code) {

    for (auto & [code, airport]: airports)
        airport->visited = false;

    queue<string> unvisitedNodes;
    unvisitedNodes.push(code);
    airports[code]->visited = true;

    while (!unvisitedNodes.empty()) {
        string code2 = unvisitedNodes.front();
        unvisitedNodes.pop();

        for (auto flight : airports[code2]->flights) {
            string destination = flight.destinationCode;
            if (!airports[destination]->visited) {
                unvisitedNodes.push(destination);
                airports[destination]->visited = true;
            }
        }
    }
}

list<list<AirportPTR>> FlightMap::getPaths(AirportPTR airportDepart, AirportPTR airportDestination){

    list<list<AirportPTR>> paths;
    int mininumFlights = INT_MAX;

    for (auto & [code, airport]: airports) {
        airport->visited = false;
        airport->path = {};
        airport->numFlights = 0;
    }

    queue<AirportPTR> unvisitedAirports;
    unvisitedAirports.push(airportDepart);
    airportDepart->visited = true;
    airportDepart->numFlights = 1;
    airportDepart->path.push_back(airportDepart);

    while (!unvisitedAirports.empty()) {
        AirportPTR previousAirport = unvisitedAirports.front();
        unvisitedAirports.pop();

        for (auto flight : previousAirport->flights) {
            AirportPTR destination = airports[flight.destinationCode];

            if (destination->numFlights > mininumFlights) break;

            if (!destination->visited) {
                unvisitedAirports.push(destination);
                destination->visited = true;
                destination->numFlights = previousAirport->numFlights + 1;
                destination->path = previousAirport->path;
                destination->path.push_back(destination);

                if(destination == airportDestination) {
                    mininumFlights = destination->numFlights;
                    paths.push_back(destination->path);
                }
            }
        }
    }
}

void getAllFlights(list<list<Flight>>& trajectories, string finalDestination,  list<Flight> trajectory, list<AirportPTR>::iterator airportIT){

    AirportPTR airport = *airportIT;
    auto nextAirport = airportIT; ++nextAirport;


    for (Flight flight: airport->flights) {

        auto backup = trajectory;

        if (!(flight.destinationCode == (*nextAirport)->code))
            continue;

        trajectory.push_back(flight);

        if (airport->code == finalDestination)
            trajectories.push_back(trajectory);

        else
            getAllFlights(trajectories, finalDestination, trajectory, nextAirport);


        trajectory = backup;

    }
}

list<list<Flight>> FlightMap::bestFlights(list<list<AirportPTR>> paths, string finalDestination){

    list<list<Flight>> trajectories;
    for(auto pathIT = paths.begin(); pathIT != paths.end(); pathIT++){

        list<Flight> trajectory = {};

        getAllFlights(trajectories, finalDestination, trajectory, pathIT->begin());
    }
}


int FlightMap::numDifferentCountries(AirportPTR airportPtr){
    for(auto airport: airports){
        airport.second->visited = false;
    }
    string airportcode = airportPtr->code;

    list<string> flightsCode;
    for(auto airport: airports) {
        for (auto edge: airport.second->flights) {
            string destinationCode = edge.destinationCode;
            if (destinationCode == airportcode) {
                auto airlinecode = edge.airlineCode;
                if (std::find(flightsCode.begin(),
                              flightsCode.end(), airlinecode) == flightsCode.end()){
                    flightsCode.push_back(airlinecode);
                }
            }
        }
    }
    return flightsCode.size();
}






