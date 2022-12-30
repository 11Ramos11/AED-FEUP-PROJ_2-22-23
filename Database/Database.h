/** @file DataBase.h
 *  @brief Contains the DataBase class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_DATABASE_H
#define AED_FEUP_PROJ_22_23_DATABASE_H

#include <set>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../Graph/Airport.h"

/** @brief Database class to read all input files and store all information.
 *
 *  Intended to be instanced once and creates a database
 *  for use within the app.
 *  Holds prototype functions to read the following input files:
 *  "classes.csv", "classes_per_uc.csv" and "student_classes.csv".
 *  And stores their data accordingly.
 */
class Database {

private:

    unordered_map<string,  unordered_set<Airport, Airport::hashFunction>> airportsPerCity;

    /** @brief Reads airports input file and stores them accordingly.
     *
     *  Reads the file "classes_per_uc.csv" and for each line
     *  it read a UC code and a class code.
     *  If the UC code corresponds to a new UC, it creates
     *  a new UC object and adds it to the vector of UCs.
     *  With each class code read, a new class is added to the
     *  vector of classes with the UC mentioned in the same line.
     *
     *  @return Void.
     */
    void readAirports();


    void readAirlines();

public:

    /** @brief Does nothing.
     *
     */
    Database();

    /** @brief Stores all the information of the database.
     *
     * @return Void.
     */
    void read();
};

#endif //AED_FEUP_PROJ_22_23_DATABASE_H
