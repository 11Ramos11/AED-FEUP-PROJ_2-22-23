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
        Database/Database.h Graph/Airport/Airport.h Graph/Airport/Airport.cpp Pointers.h Graph/Locals/Local.h Graph/Locals/Coordinates.cpp Graph/Locals/Coordinates.h Graph/Locals/CityLocal.cpp Graph/Locals/CityLocal.h Graph/Locals/AirportLocal.cpp Graph/Locals/AirportLocal.h menu/Menu.cpp menu/Menu.h application/Application.cpp application/Application.h Graph/City/City.cpp Graph/City/City.h Graph/Airline/Airline.h Graph/Flight/Flight.h ListingApplication/ListingApplication.cpp ListingApplication/ListingApplication.h NumbersApplication/NumbersApplication.cpp NumbersApplication/NumbersApplication.h)
