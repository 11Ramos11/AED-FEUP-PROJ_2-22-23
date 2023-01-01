/** @file Pointers.h
 *  @brief Contains the Pointers class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_2_22_23_POINTERS_H
#define AED_FEUP_PROJ_2_22_23_POINTERS_H

#include <memory>

class Airport; class FlightMap;

typedef std::shared_ptr<FlightMap> FlightMapPtr;
typedef std::shared_ptr<Airport> AirportPTR;

#endif //AED_FEUP_PROJ_2_22_23_POINTERS_H
