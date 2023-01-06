/** @file Application.cpp
 *  @brief Contains the Application class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Application.h"
#include "../Graph/Locals/Coordinates.h"
#include <stdexcept>


Application::Application() {}


void Application::startApplication() {
    database->read();
    startMenu();
}

void Application::startMenu() {
    menu.startMenu();
    menu.breakLine();
    displayMenu();
}

void Application::safeInput(string &option, int &safeOption) {
    try {
        cin >> option;
        safeOption = stoi(option);
    }
    catch (const invalid_argument &ia) {
        menu.breakLine();
        menu.getInvalidMessage();
        menu.breakLine();
        safeOption = 0;
    }
}

void Application::menuSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayMenu();
        safeInput(option, safeOption);
    }
}

void Application::airportListMenuSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayListsMenu();
        safeInput(option, safeOption);
    }
}


void Application::airportNumbersSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayNumbersMenu();
        safeInput(option, safeOption);
    }
}

void Application::filtersMenuSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayFilterMenu();
        safeInput(option, safeOption);
    }
}

void Application::trajectoriesMenuSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayTrajectoriesMenu();
        safeInput(option, safeOption);
    }
}

void Application::airportNumbersMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    airportNumbersSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case FLIGHTS: {
                string airportCode;
                cout << "Type the Airport code to check flights total number:";
                cin >> airportCode;
                cout << numbersApplication.numbersFlights(airportCode) << endl;
                break;
            }
            case DIFFERENT_AIRLINES: {
                string airportCode;
                cout << "Type the Airport code to check all airlines operating:";
                cin >> airportCode;
                cout << numbersApplication.numbersAirlines(airportCode) << endl;
                break;
            }
            case CITY: {
                string airportCode;
                cout << "Type the Airport code to check all flights cities:";
                cin >> airportCode;
                cout << numbersApplication.numbersCities(airportCode) << endl;
                break;
            }
            case BY_COUNTRIES: {
                string airportCode;
                cout << "Type the Airport code to check the number of countries to flight:";
                cin >> airportCode;
                cout << numbersApplication.numbersCountries(airportCode) << endl;
                break;
            }
            default: {
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
            }
        }
        menu.breakLine();
        safeOption = 0;
        airportNumbersSafety(option, safeOption);
    }
    safeOption = 0;
}

void Application::airportListMenu(int &oldOption) {
    string option;
    menu.displayListsMenu();
    int safeOption;
    safeInput(option, safeOption);

    while (safeOption != QUIT) {
        switch (safeOption) {
            case FLIGHTS: {
                string airportCode;
                cout << "Type the Airport code to check all flights:";
                cin >> airportCode;
                listingApplication.listFlights(airportCode);
                break;
            }
            case DIFFERENT_AIRLINES: {
                string airportCode;
                cout << "Type the Airport code to check all flights:";
                cin >> airportCode;
                listingApplication.listAirlines(airportCode);
                break;
            }
            case CITY: {
                string airportCode;
                cout << "Type the Airport code to check all flights:";
                cin >> airportCode;
                listingApplication.listCities(airportCode);
                break;
            }

            case BY_COUNTRIES: {
                string airportCode;
                cout << "Type the Airport code to check all flights:";
                cin >> airportCode;
                listingApplication.listCountries(airportCode);
                break;
            }
            default: {
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
            }
        }
        menu.breakLine();
        safeOption = 0;
        airportListMenuSafety(option, safeOption);
    }
    oldOption = 0;
    cout << menu.QUIT_MESSAGE << endl;
}

void Application::optionFilter(int &option) {
    while (option != QUIT) {
        switch (option) {
            case AIRPORT_LISTS: {
                airportListMenu(option);
                break;
            }
            case AIRPORT_NUMBERS: {
                airportNumbersMenu(option);
                break;
            }
            case AIRPORT_BY_CITY: {
                string city;
                cout << "Type name of city to check airports:";
                cin >> city;
                listingApplication.listAirportsByCity(city);
                break;
            }
            default: {
                menu.breakLine();
                menu.getWrongMessage();
                break;
            }
        }
        menu.breakLine();
        menu.displaySearchInfoMenu();
        cin >> option;
    }
    option = 0;
}

void Application::displayTrajectoriesMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    trajectoriesMenuSafety(option, safeOption);
    bool fail = 0;
    while (safeOption != QUIT) {
        LocalPTR origin, destination;
        switch (safeOption) {
            case BY_AIRPORT_CODE: {
                string airportCode;
                cout << "Origin Airport Code: ";
                std::cin >> airportCode;
                origin = LocalPTR(new AirportLocal(airportCode));
                break;
            }
            case BY_CITY_COUNTRY: {
                string cityName, countryName;
                cout << "Origin City Name: ";
                std::cin >> cityName;
                cout << "Origin Country Name: ";
                std::cin >> countryName;
                origin = LocalPTR(new CityLocal({cityName, countryName}));
                break;
            }
            case BY_COORDINATES: {
                float latitude, longitude, radius;
                cout << "Origin Latitude: ";
                std::cin >> latitude;
                cout << "Origin Longitude: ";
                std::cin >> longitude;
                cout << "Origin Radius: ";
                std::cin >> radius;
                origin = LocalPTR(new Coordinates(longitude, latitude, radius));
                break;
            }
            default:
                fail = 1;
                menu.breakLine();
                menu.getWrongMessage();
                break;
        }
        switch (safeOption) {
            case BY_AIRPORT_CODE: {
                string airportCode;
                cout << "Destiny Airport Code: ";
                std::cin >> airportCode;
                destination = LocalPTR(new AirportLocal(airportCode));
                break;
            }
            case BY_CITY_COUNTRY: {
                string cityName, countryName;
                cout << "Destiny City Name: ";
                std::cin >> cityName;
                cout << "Destiny Country Name: ";
                std::cin >> countryName;
                destination = LocalPTR(new CityLocal({cityName, countryName}));
                break;
            }
            case BY_COORDINATES: {
                float latitude, longitude, radius;
                cout << "Destiny Latitude: ";
                std::cin >> latitude;
                cout << "Destiny Longitude: ";
                std::cin >> longitude;
                cout << "Destiny Radius: ";
                std::cin >> radius;
                destination = LocalPTR(new Coordinates(longitude, latitude, radius));
                break;
            }
            default: {
                fail = 1;
                menu.breakLine();
                menu.getWrongMessage();
                break;
            }
        }
        if (!fail)
            listingApplication.showTrajectories(origin, destination);
        menu.breakLine();
        safeOption = 0;
        trajectoriesMenuSafety(option, safeOption);
    }
    oldOption = 0;
    cout << menu.QUIT_MESSAGE << endl;
}

void Application::displayMenu() {
    string option;
    int safeOption = 0;
    menuSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case AIRPORT_LISTS: {
                string option;
                menu.displaySearchInfoMenu();
                safeInput(option, safeOption);
                optionFilter(safeOption);
                break;
            }
            case MAX_FLIGHT_LISTS: {

                break;
            }
            case GENERATE_TRAJECTORIES: {
                string option;
                displayTrajectoriesMenu(safeOption);
                break;
            }
            case FILTERS: {
                string option;
                menu.displayFilterMenu();
                safeInput(option, safeOption);
                break;
            }
            default:
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
        }
        menu.breakLine();
        menuSafety(option, safeOption);
    }
    cout << menu.QUIT_MESSAGE << endl;
}

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


