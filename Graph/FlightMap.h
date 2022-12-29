// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


struct Airline{

    string code;
    string name;
    string callSign;
    string country;
};

struct Flight {

    Airline airline;
    int destination;   // Destination node
    int distance; // An integer weight
};

struct Airport {

        string code;
        string name;
        string city;
        string country;
        float latitude;
        float longitude;

        list<Flight> flights; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
};

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
