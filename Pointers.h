/** @file Pointers.h
 *  @brief Contains the Pointers class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_POINTERS_H
#define AED_FEUP_PROJ_2_22_23_POINTERS_H

#include <memory>


//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Airport;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class FlightMap;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Database;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Local;

//! @brief Redefinition of shared pointers of FlightMaps for ease of use.
typedef std::shared_ptr<FlightMap> FlightMapPtr;

//! @brief Redefinition of shared pointers of Airports for ease of use.
typedef std::shared_ptr<Airport> AirportPTR;

//! @brief Redefinition of shared pointers of database for ease of use.
typedef std::shared_ptr<Database> DatabasePTR;

//! @brief Redefinition of shared pointers of Local for ease of use.
typedef std::shared_ptr<Local> LocalPTR;

#endif //AED_FEUP_PROJ_2_22_23_POINTERS_H
