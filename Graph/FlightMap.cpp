// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#include "FlightMap.h"

// Constructor: nr nodes and direction (default: undirected)
FlightMap::FlightMap(int airportNumber) :
    airportNumber(airportNumber) {}

/*
int calculateDistance(){
    return 0;
}

// Add edge from source to destination with a certain weight
void FlightMap::addFlight(int source, int destination, Airline airline) {
    if (source<1 || source>airportNumber || destination<1 || destination>airportNumber) return;

    int distance = calculateDistance();

    //airports[source].flights.push_back({airline, destination, distance});
}

// Depth-First Search: example implementation
void FlightMap::dfs(int v) {
    // show node order
    // cout << v << " ";
    airports[v].visited = true;
    for (auto e : airports[v].flights) {
        int w = e.destination;
        if (!airports[w].visited)
            dfs(w);
    }
}

// Breadth-First Search: example implementation
void FlightMap::bfs(int v) {
    for (int i=1; i<=airportNumber; i++) airports[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    airports[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : airports[u].flights) {
            int w = e.destination;
            if (!airports[w].visited) {
                q.push(w);
                airports[w].visited = true;
            }
        }
    }
}*/
