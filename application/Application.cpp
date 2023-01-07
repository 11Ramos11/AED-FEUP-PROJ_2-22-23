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

void Application::localMenuSafety(string &option, int &safeOption, string typeLocal) {
    while (!safeOption) {
        menu.displayLocalMenu(typeLocal);
        safeInput(option, safeOption);
    }
}

void Application::statisticsMenuSafety(std::string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayStatisticsMenu();
        safeInput(option, safeOption);
    }
}


void Application::maxYFlightsMenuSafety(std::string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayMaxYFlightsMenu();
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

void Application::displayMaxYFlightsMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    bool fail = 0;
    maxYFlightsMenuSafety(option, safeOption);
    while (safeOption != QUIT) {
        int y;
        cout << "Type the desired maximum number of flights:";
        cin >> y;
        LocalPTR local;
        getLocal(safeOption, fail, local, "Target");
        if (!fail) {
            switch (safeOption) {
                case MAX_AIRPORTS: {
                    listingApplication.numberReachableAirports(local, y);
                    listingApplication.showReachableAirports(local, y);
                    break;
                }
                case MAX_CITIES: {
                    listingApplication.numberReachableCities(local, y);
                    listingApplication.showReachableCities(local, y);
                    break;
                }
                case MAX_COUNTRIES: {
                    listingApplication.numberReachableCountries(local, y);
                    listingApplication.showReachableCountries(local, y);
                    break;
                }
                default: {
                    menu.breakLine();
                    menu.getWrongMessage();
                    safeOption = 0;
                    break;
                }
            }
        }
        menu.breakLine();
        safeOption = 0;
        maxYFlightsMenuSafety(option, safeOption);
    }
    oldOption = 0;
    cout << menu.QUIT_MESSAGE << endl;
}


void Application::airportListMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    airportListMenuSafety(option, safeOption);
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
                string city, country;
                cout << "Type the name of city to check airports:";
                cin.ignore();
                getline(cin, city);
                cout << "Type the name of its country:";
                getline(cin, country);
                listingApplication.listAirportsByCity({city, country});
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
    localMenuSafety(option, safeOption, "Origin");
    bool fail = 0;
    while (safeOption != QUIT) {
        LocalPTR origin, destination;
        getLocal(safeOption, fail, origin, "Origin");
        safeOption = 0;
        localMenuSafety(option, safeOption, "Destination");
        getLocal(safeOption, fail, destination, "Destination");
        if (!fail)
            listingApplication.showTrajectories(origin, destination);
        menu.breakLine();
        safeOption = 0;
        localMenuSafety(option, safeOption, "Origin");
    }
    oldOption = 0;
    cout << menu.QUIT_MESSAGE << endl;
}

void Application::getLocal(int safeOption, bool &fail, LocalPTR &local, string typeLocal) {
    switch (safeOption) {
        case Application::BY_AIRPORT_CODE: {
            string airportCode;
            cout << typeLocal << " Airport Code: ";
            cin >> airportCode;
            local = LocalPTR(new AirportLocal(airportCode));
            break;
        }
        case Application::BY_CITY_COUNTRY: {
            string city, country;
            cout << typeLocal << " City Name: ";
            cin.ignore();
            getline(cin, city);
            cout << typeLocal << " Country Name: ";
            getline(cin, country);
            local = LocalPTR(new CityLocal({city, country}));
            break;
        }
        case Application::BY_COORDINATES: {
            float latitude, longitude, radius;
            cout << typeLocal << " Latitude: ";
            cin >> latitude;
            cout << typeLocal << " Longitude: ";
            cin >> longitude;
            cout << typeLocal << " Radius: ";
            cin >> radius;
            local = LocalPTR(new Coordinates(latitude, longitude, radius));
            break;
        }
        default:
            fail = 1;
            this->menu.breakLine();
            this->menu.getWrongMessage();
            break;
    }
}

void Application::displayStatisticsMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    statisticsMenuSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case GLOBAL_STATISTICS: {
                int k;
                cout << "Type the range of results: ";
                cin >> k;
                listingApplication.globalStatistic(k);
                break;
            }
            case STATISTICS_BY_COUNTRY: {
                string country;
                int k;
                cout << "Type a country name to check its air transport statistics:";
                cin.ignore();
                getline(cin, country);
                cout << "Type the range of results: ";
                cin >> k;
                listingApplication.statisticPerCountry(country, k);
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
        statisticsMenuSafety(option, safeOption);
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
                string option;
                displayMaxYFlightsMenu(safeOption);
                break;
            }
            case GENERATE_TRAJECTORIES: {
                string option;
                displayTrajectoriesMenu(safeOption);
                break;
            }
            case STATISTICS: {
                string option;
                displayStatisticsMenu(safeOption);
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


