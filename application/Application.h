/** @file Application.cpp
 *  @brief Contains the Application Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_APPLICATION_H
#define AED_FEUP_PROJ_2_22_23_APPLICATION_H

#include "../menu/Menu.h"
#include "../Database/Database.h"
#include "../Graph/Locals/AirportLocal.h"
#include "../Graph/Locals/CityLocal.h"
#include "../Pointers.h"
#include "../ListingApplication/ListingApplication.h"

using namespace std;

/** @brief Initializes and manages all the components of the application.
 *
 * Intended to be instanced once.
 * Manages the interaction between the user and the application.
 */
class Application {
private:

    //! @brief Creates the initial menu options.
    enum {

        AIRPORT_LISTS = 1,
        AIRPORT_NUMBERS = 2,
        MAX_FLIGHT_LISTS = 2,
        AIRPORT_BY_CITY = 3,
        GENERATE_TRAJECTORIES = 3,
        FILTERS = 4,
        QUIT = 9
    };

    //! @brief Creates the airport numbers options.
    enum {
        FLIGHTS = 1, DIFFERENT_AIRLINES = 2, CITY = 3, BY_COUNTRIES = 4
    };

    //! @brief enum for the trajectories generations..
    enum {
        BY_AIRPORT_CODE = 1, BY_CITY_COUNTRY = 2, BY_COORDINATES = 3
    };


    //! @brief Initialization of the database.
    DatabasePTR database = DatabasePTR(new Database());

    ListingApplication listingApplication = ListingApplication(database);

    //! @brief Initialization of the menu.
    Menu menu;

    /** @brief Starts the menu.
     *
     * @return Void.
     */
    void startMenu();

    /** @brief Covers wrong inputs in the menu.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void safeInput(string &option, int &safeOption);

    /** @brief Display the menu if the menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void menuSafety(string &option, int &safeOption);


    /** @brief Display the listing menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void airportListMenuSafety(string &option, int &safeOption);

    /** @brief Display the occupation menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void airportNumbersSafety(string &option, int &safeOption);


    /** @brief Display the filter option menu (by local or airlines).
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void filtersMenuSafety(string &option, int &safeOption);

    /** @brief Display the trajectories menu if the given menu option is correct.
   *
   * Checks if the safeOption argument is correct for that specific menu.
   * Then, safeInput method is used with both arguments to cover wrong inputs.
   *
   * @param option Of type string, by reference.
   * @param safeOption Of type int, by reference.
   * @return Void.
   */
    void trajectoriesMenuSafety(string &option, int &safeOption);

    /** @brief Display the menu of the possible with possible trajectories
     *
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void displayTrajectoriesMenu(int &safeOption);


    /** @brief Reads what the user wants to know the occupation of and shows it.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * @param oldOption Of type string, by reference.
     * @return Void.
     */
    void airportNumbersMenu(int &oldOption);

    /** @brief Reads what the user wants to get the listing of and shows it.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void airportListMenu(int &oldOption);

    /** @brief Filters through multiple menu options based on argument value.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void optionFilter(int &option);


    /** @brief Main menu that will be the root to reach all other menus.
     *
     * Menu responsible for displaying all other menus depending on user interaction,
     * and where it is possible to exit the application successfully.
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @return Void.
     */
    void displayMenu();

public:

    //! @brief Does nothing.
    Application();

    /** @brief Starts the application.
     *
     * @return Void.
     */
    void startApplication();
};

/** @brief Checks if a string represents a number.
 *
 * @return True if the string represents a number, false if otherwise.
 */
bool is_number(const std::string &s);


/** @brief Reads user input until it its a valid numeric value.
 *
 * @return User input of string type.
 */
string validStudentCode();


#endif //AED_FEUP_PROJ_2_22_23_APPLICATION_H
