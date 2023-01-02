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

//! @brief Redefinition of shared pointers of FlightMaps for ease of use.
typedef std::shared_ptr<FlightMap> FlightMapPtr;

//! @brief Redefinition of shared pointers of Airports for ease of use.
typedef std::shared_ptr<Airport> AirportPTR;

#endif //AED_FEUP_PROJ_2_22_23_POINTERS_H
