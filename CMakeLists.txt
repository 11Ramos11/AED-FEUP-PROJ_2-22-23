cmake_minimum_required(VERSION 3.24)
project(AED_FEUP_PROJ_2_22_23)

set(CMAKE_CXX_STANDARD 14)

include_directories(-)

add_executable(AED_FEUP_PROJ_2_22_23
        main.cpp
        classes/graph/FlightMap.cpp
        classes/graph/FlightMap.h
        resources/airlines.csv
        resources/airports.csv
        resources/flights.csv
        classes/database/Database.cpp
        classes/database/Database.h classes/graph/airport/Airport.h classes/graph/airport/Airport.cpp Pointers.h classes/graph/locals/Local.h classes/graph/locals/Coordinates.cpp classes/graph/locals/Coordinates.h classes/graph/locals/CityLocal.cpp classes/graph/locals/CityLocal.h classes/graph/locals/AirportLocal.cpp classes/graph/locals/AirportLocal.h classes/menu/Menu.cpp classes/menu/Menu.h classes/application/Application.cpp classes/application/Application.h classes/graph/city/City.cpp classes/graph/city/City.h classes/graph/airline/Airline.h classes/graph/flight/Flight.h classes/listingApplication/ListingApplication.cpp classes/listingApplication/ListingApplication.h classes/numbersApplication/NumbersApplication.cpp classes/numbersApplication/NumbersApplication.h)
