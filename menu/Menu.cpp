/** @file Menu.cpp
 *  @brief Contains the Menu Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Menu.h"
#include <iostream>


using namespace std;

const string Menu::AIRPORT_LISTS = "Listings and related options to the Airports";
const string Menu::MAX_FLIGHTS_LISTS = "Listings related to a maximum number of flights";
const string Menu::GENERATE_TRAJECTORIES = "Generate flight trajectories based on origin and destination";
const string Menu::INFO_FILTERED = "Air transports filtered information";

const string Menu::INFO_BY_LOCAL = "Filtered information by Local";
const string Menu::LOCAL_CITY = "Filter a local by city";
const string Menu::LOCAL_AIRLINE = "Filter a local by its airline";
const string Menu::INFO_BY_AIRLINES = "Filtered information by Airlines";

const string Menu::QUIT_APPLICATION = "Quit the application";
const string Menu::GO_BACK = "Go Back";
const string Menu::QUIT_MESSAGE = "Thanks for using Air Transports application!";
const string Menu::INVALID_INPUT = "Invalid input! Read options and try 0, 1, 2, 3 (...)";
const string Menu::WRONG_INPUT = "That option does not exist! Read options and try 0, 1, 2, 3 (...)";

const string Menu::BY_CITY = "Check airports in a certain city";
const string Menu::BY_NUMBER = "Airport information by numbers";
const string Menu::BY_LISTS = "Airport information by listings";

const string Menu::FLIGHTS_NUMBER = "Number of flights of the airport";
const string Menu::AIRLINES_NUMBER = "Number of airlines of the airport";
const string Menu::DESTINATIONS_NUMBER = "Number of different flight destinations the airport";
const string Menu::COUNTRIES_NUMBER = "Number different countries flights of the airport";

const string Menu::TRAJECTORIES_BY_AIRPORT_CODE = "Generate trajectory by giving an Airport code";
const string Menu::TRAJECTORIES_BY_CITY_COUNTRY = "Generate trajectory by giving a city and country";
const string Menu::TRAJECTORIES_BY_COORDS = "Generate trajectory by giving coordinates";


const string Menu::AIRPORT_FLIGHTS = "List flights by airport";
const string Menu::AIRPORT_AIRLINES = "List airlines by airport";
const string Menu::AIRPORT_DESTINATIONS = "List flight destinations by airport";
const string Menu::AIRPORT_COUNTRIES = "List flight countries by airport";

const string Menu::MAX_FLIGHTS_AIRPORTS = "";
const string Menu::MAX_FLIGHTS_CITIES = "";
const string Menu::MAX_FLIGHTS_COUNTRIES = "";

Menu::Menu() {}

void Menu::getWrongMessage() {
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << WRONG_INPUT
         << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}

void Menu::getInvalidMessage() {
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << INVALID_INPUT
         << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}


void Menu::startMenu() {
    cout << "=============================================" << endl;
    cout << " Welcome to the Air Transports application!" << endl;
    cout << "=============================================" << endl;
    cout << "Click ENTER for the options MENU";
    cin.ignore();
}

void Menu::displayMenu() {

    cout << "=============================================" << endl;
    cout << "           Air Transports MENU" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << AIRPORT_LISTS << endl;
    cout << "2 - " << MAX_FLIGHTS_LISTS << endl;
    cout << "3 - " << GENERATE_TRAJECTORIES << endl;
    cout << "4 - " << INFO_FILTERED << endl;
    cout << "9 - " << QUIT_APPLICATION << endl;
    cout << "Insert option number > ";
}

void Menu::displayFilterMenu() {

    cout << "=============================================" << endl;
    cout << "         Filters MENU" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << INFO_BY_LOCAL << endl;
    cout << "2 - " << INFO_BY_AIRLINES << endl;
    cout << "9 - " << QUIT_APPLICATION << endl;
    cout << "Insert option number > ";
}

void Menu::displayLocalMenu() {

    cout << "=============================================" << endl;
    cout << "         Filter by Local MENU" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << LOCAL_CITY << endl;
    cout << "2 - " << LOCAL_AIRLINE << endl;
    cout << "9 - " << QUIT_APPLICATION << endl;
    cout << "Insert option number > ";
}


void Menu::displaySearchInfoMenu() {

    cout << endl;
    cout << "=============================================" << endl;
    cout << "      Airport Information Type Menu" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << BY_LISTS << endl;
    cout << "2 - " << BY_NUMBER << endl;
    cout << "3 - " << BY_CITY << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}


void Menu::breakLine() {
    cout << "\n" << endl;
}

void Menu::displayNumbersMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "     Check Airport information numbers" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << FLIGHTS_NUMBER << endl;
    cout << "2 - " << AIRLINES_NUMBER << endl;
    cout << "3 - " << DESTINATIONS_NUMBER << endl;
    cout << "4 - " << COUNTRIES_NUMBER << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayMaxYFlightsMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "         Max Y Flights options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << MAX_FLIGHTS_AIRPORTS << endl;
    cout << "2 - " << MAX_FLIGHTS_CITIES << endl;
    cout << "3 - " << MAX_FLIGHTS_COUNTRIES << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayListsMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "         Airport listing options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << AIRPORT_FLIGHTS << endl;
    cout << "2 - " << AIRPORT_AIRLINES << endl;
    cout << "3 - " << AIRPORT_DESTINATIONS << endl;
    cout << "4 - " << AIRPORT_COUNTRIES << endl;
    // cout << "5 - " << ALL_AIRPORTS << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayTrajectoriesMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "          Trajectories options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << TRAJECTORIES_BY_AIRPORT_CODE << endl;
    cout << "2 - " << TRAJECTORIES_BY_CITY_COUNTRY << endl;
    cout << "3 - " << TRAJECTORIES_BY_COORDS << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}
