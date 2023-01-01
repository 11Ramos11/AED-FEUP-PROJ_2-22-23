// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include "Airport.h"

using namespace std;


class FlightMap {

    //! @brief Holds all airports.
    unordered_map<string,  Airport> airports;

public:
    // Constructor: nr nodes and direction (default: undirected)
    FlightMap();

    void setAirports(const unordered_map<string,  Airport> airports);

    // Add edge from source to destination with a certain weight
    void addFlight(string originCode, string destinationCode, Airline airline);

    // Depth-First Search: example implementation
    void dfs(string code);

    // Breadth-First Search: example implementation
    void bfs(const string& code);
};

#endif
