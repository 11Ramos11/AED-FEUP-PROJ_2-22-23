/** @file Application.h
 *  @brief Contains the Application class implementation.
 *  @author -
 *  @bug No known bugs.
 */

/** @file Application.cpp
 *  @brief Contains the Application class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Application.h"
#include "../Graph/Locals/Coordinates.h"
#include <stdexcept>      // std::invalid_argument


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


void Application::airportNumbersMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    airportNumbersSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case FLIGHTS: {
                string ucCode;
                cout << "Type the UC code relative to the class:";
                cin >> ucCode;
                string classCode;
                cout << "Type class code to list:";
                cin >> classCode;
                break;
            }
            case DIFFERENT_AIRLINES: {
                string ucCode;
                cout << "Type the UC code to check:";
                cin >> ucCode;
                break;
            }
            case CITY: {
                char year;
                cout << "Type the year to check (1, 2 or 3):";
                cin >> year;
                break;
            }
            case BY_COUNTRIES: {
                char year;
                cout << "Type the year to check (1, 2 or 3):";
                cin >> year;
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
                cout << "1.Aeroporto\n2.Cidade\n3.Coordenadas\n\n";
                int option2;
                cin >> option2;
                switch (option2){
                    case 1: {
                        string airportCode;
                        cout << "airportCode\n";
                        std::cin >> airportCode;
                        LocalPTR local = LocalPTR(new AirportLocal(airportCode));
                        listingApplication.showTrajectories(local);
                        break;
                    }
                    case 2: {
                        string cityName, countryName;
                        cout << "cityName\n";
                        std::cin >> cityName;
                        cout << "countryName\n";
                        std::cin >> countryName;
                        LocalPTR local = LocalPTR(new CityLocal({cityName, countryName}));
                        listingApplication.showTrajectories(local);
                        break;
                    }
                    case 3 : {
                        float latitude, longitude, radius;

                        cout << "latitude\n";
                        std::cin >> latitude;
                        cout << "longitude\n";
                        std::cin >> longitude;
                        cout << "radius\n";
                        std::cin >> radius;

                        LocalPTR local = LocalPTR(new Coordinates(longitude, latitude, radius));
                        listingApplication.showTrajectories(local);
                        break;
                    }
                    default:

                        cout << "noob";
                }
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

string validStudentCode() {
    string studentCode;
    cin >> studentCode;
    while (!is_number(studentCode)) {
        cout << "Type a valid numeric value for the student code > ";
        cin >> studentCode;
    }
    return studentCode;
}




