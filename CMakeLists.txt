cmake_minimum_required(VERSION 3.24)
project(AED_FEUP_PROJ_2_22_23)

set(CMAKE_CXX_STANDARD 14)

include_directories(-)

add_executable(AED_FEUP_PROJ_2_22_23
        main.cpp
        Graph/FlightMap.cpp
        Graph/FlightMap.h
        resources/airlines.csv
        resources/airports.csv
        resources/flights.csv
        Database/Database.cpp
        Database/Database.h Graph/Airport.h Graph/Airport.cpp Graph/Data.h Graph/Pointers.h)
