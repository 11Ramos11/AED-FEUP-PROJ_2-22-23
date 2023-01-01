/** @file FlightMap.cpp
 *  @brief Contains the FlightMap Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "FlightMap.h"

// Constructor: nr nodes and direction (default: undirected)
FlightMap::FlightMap() {}

void FlightMap::setAirports(const unordered_map<string,  Airport> airports) {
    this->airports = airports;
}

int calculateDistance(){
    return 0;
}

// Add edge from source to destination with a certain weight
void FlightMap::addFlight(string originCode, string destinationCode, Airline airline) {
    if (airports.find(originCode) == airports.end() || airports.find(destinationCode) == airports.end() ) return;

    int distance = calculateDistance();

    //airports[source].flights.push_back({airline, destination, distance});
}

// Depth-First Search: example implementation
void FlightMap::dfs(string code) {
    // show node order
    // cout << v << " ";
    if (airports.find(code) != airports.end())
        airports[code].visited = true;

    for (auto e : airports[code].flights) {
        string destinationCode = e.destinationCode;
        if (!airports[code].visited)
            dfs(destinationCode);
    }
}

// Breadth-First Search: example implementation
void FlightMap::bfs(const string& code) {

    for (auto & [code, airport]: airports)
        airport.visited = false;

    queue<string> unvisitedNodes; // queue of unvisited nodes
    unvisitedNodes.push(code);
    airports[code].visited = true;

    while (!unvisitedNodes.empty()) { // while there are still unvisited nodes
        string code2 = unvisitedNodes.front();
        unvisitedNodes.pop();
        // show node order
        //cout << u << " ";
        for (auto flight : airports[code2].flights) {
            string destination = flight.destinationCode;
            if (!airports[destination].visited) {
                unvisitedNodes.push(destination);
                airports[destination].visited = true;
            }
        }
    }
}
