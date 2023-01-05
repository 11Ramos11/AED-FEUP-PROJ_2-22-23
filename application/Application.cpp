//
// Created by Alberto on 04/01/2023.
//

/** @file Application.cpp
 *  @brief Contains the Application class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Application.h"
#include <stdexcept>      // std::invalid_argument


Application::Application() {}


void Application::startApplication() {
    database.read();
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


void Application::airportNumbersMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    airportNumbersSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case BY_FLIGHTS: {
                string ucCode;
                cout << "Type the UC code relative to the class:";
                cin >> ucCode;
                string classCode;
                cout << "Type class code to list:";
                cin >> classCode;
                break;
            }
            case BY_AIRLINES: {
                string ucCode;
                cout << "Type the UC code to check:";
                cin >> ucCode;
                break;
            }
            case BY_DESTINATIONS: {
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
            case BY_FLIGHTS: {
                string airportCode;
                cout << "Type the Airport code to check all flights:";
                cin >> airportCode;
                break;
            }
            case BY_AIRLINES: {
                string ucCode;
                cout << "Type UC code to list:";
                cin >> ucCode;
                break;
            }
            case BY_DESTINATIONS: {
                char year;
                cout << "Type year number (1, 2 or 3) to list:";
                cin >> year;
                break;
            }

            case BY_COUNTRIES: {
                string ucCode;
                cout << "Type UC code to list:";
                cin >> ucCode;
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




