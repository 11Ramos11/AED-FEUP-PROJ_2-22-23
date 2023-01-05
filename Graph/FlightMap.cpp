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

void FlightMap::setAirports(const unordered_map<string,  AirportPTR> airports) {
    this->airports = airports;
}

unordered_map<string,  AirportPTR> FlightMap::getAirports(){
    return airports;
}

void FlightMap::setAirportsPerCity(AirportsPerCity_Set airportsPerCity){
    this->airportsPerCity = airportsPerCity;
}

AirportsPerCity_Set FlightMap::getAirportsPerCity(){
    return airportsPerCity;
}

/*
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
}*/

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

list<list<AirportPTR>> FlightMap::getPaths(AirportPTR airportDepart, AirportPTR airportDestination, unordered_set<string> airlines){

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

            if (airlines.find(flight.airlineCode) == airlines.end()) continue;

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

list<list<Flight>> FlightMap::getFlights(AirportPTR airport, AirportPTR destination, unordered_set<string> airlines){
    auto paths = getPaths(airport, destination, airlines);

    auto trajectories = bestFlights(paths, destination->code);

    return trajectories;
}

list<list<Flight>> FlightMap::getFlights(Local* origin, Local* destination, unordered_set<string> airlines){

    list<list<Flight>> trajectories;

    for (AirportPTR originAirport: origin->getAirports(static_cast<FlightMapPtr>(this)))
        for (AirportPTR destAirport: destination->getAirports(static_cast<FlightMapPtr>(this)))
            for (auto trajectory: getFlights(originAirport, destAirport,airlines))
                trajectories.push_back(trajectory);

    return trajectories;
}

int FlightMap::numDifferentCountries(AirportPTR airportPtr){
    list<string> countries;
    auto airportcode = airportPtr->code;
    for(auto pair: airports) {
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

list<AirportPTR> FlightMap::reachableAirports(AirportPTR airportPtr, int y){
    queue<AirportPTR> airports_code;
    list<AirportPTR> airportsVisited;
    airports_code.push(airportPtr);
    airportPtr->visited = true;
    int count =0;
    while(!airports_code.empty()){
        auto airport = airports_code.front();
        airports_code.pop();
        for(auto edge: airport->flights){
            auto destination = edge.destinationCode;
            if(airports[destination]->visited == false){
                airports_code.push(airports[destination]);
                airportsVisited.push_back(airports[destination]);
                airports[destination]->visited = true;
                count++;
                if(count >= y) break;
            }
        }
    }
    return airportsVisited;
}

int FlightMap::airportsMaxYFlights(AirportPTR airportPtr, int y){
    return reachableAirports(airportPtr,y).size();
}

int FlightMap::citiesMaxYFlights(City city, int y){
    list<AirportPTR> allAirports;
    for(AirportPTR airportptr: airportsPerCity[city]){
        list<AirportPTR> airports = reachableAirports(airportptr,y);
        for(auto airport: airports){
            allAirports.push_back(airport);
        }
    }
    list<string> cityName;
    for(auto airport: allAirports){
        auto city = airport->city;
        if(find(cityName.begin(), cityName.end(), city) == cityName.end())
            cityName.push_back(city);
    }
    return cityName.size();
}

int FlightMap::countriesMaxYFlights(string country, int y){
    list<AirportPTR> allAirports;
    for(auto pair: airports){
        if(pair.second->country == country) {
            list<AirportPTR> airports = reachableAirports(pair.second, y);
            for (auto airport: airports) {
                allAirports.push_back(airport);
            }
        }
    }
    list<string> countryName;
    for(auto airport: allAirports){
        auto country = airport->country;
        if(find(countryName.begin(), countryName.end(), country) == countryName.end())
            countryName.push_back(country);
    }
    return countryName.size();
}

void FlightMap::dfsArticulationPoints(AirportPTR airport, int &index, stack<AirportPTR> &stack, list<AirportPTR> &answer){
    airport->visited = true;
    airport->num = airport->low = index++;
    stack.push(airport);
    airport->inStack = true;

    int children =0;
    bool articulation = false;

    for(Flight e: airport->flights){
        string w = e.destinationCode;
        AirportPTR destination = airports[w];
        if(destination->visited == false){
            children++;
            dfsArticulationPoints(destination,index, stack, answer);
            airport->low =min(airport->low, destination->low);
            if(destination->low >= airport->num) articulation= true;
        }
        else if(airports[w]->inStack){
            airport->low =min(airport->low, destination->num);
        }
    }
    if((airport->num == 1 && children > 1) || (airport->num > 1 && articulation)){
        AirportPTR w;
        do{
            w = stack.top();
            stack.pop();
            airport->inStack = false;
        }
        while (w != airport);
        answer.push_front(w);
    }
}

list<AirportPTR> FlightMap::articulationPoints() {
    list<AirportPTR> answer;
    for(auto pair: airports){
        AirportPTR airport = pair.second;
            airport->visited = false;
            airport->low = 0;
            airport->num = 0;
            airport->inStack = false;
    }

    int index =1;
    stack<AirportPTR> stack;
    for(auto pair: airports){
        AirportPTR airport = pair.second;
        if(airport->visited == false){
            dfsArticulationPoints(airport, index, stack, answer);
        }
    }
    return answer;
}


