// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
#include "Airport.h"

using namespace std;


class FlightMap {

    int airportNumber;  // Graph size (vertices are numbered from 1 to n)
    vector<Airport> airports; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    FlightMap(int airportNumber);

    // Add edge from source to destination with a certain weight
    void addFlight(int src, int dest, Airline airline);

    // Depth-First Search: example implementation
    void dfs(int v);

    // Breadth-First Search: example implementation
    void bfs(int v);
};

#endif
