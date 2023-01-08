
#include "application/Application.h"
#include "Graph/Locals/Coordinates.h"

void test1() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR origin = make_shared<CityLocal>(City("Moscow", "Russia"));
    LocalPTR destination = make_shared<Coordinates>(40.6894, -74.0444, 40);

    listingApplication.showTrajectories(origin, destination, false, {"AAL", "BAW"});
}

void test2() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR origin = make_shared<CityLocal>(City("Moscow", "Russia"));
    LocalPTR destination = make_shared<Coordinates>(40.6894, -74.0444, 40);

    listingApplication.showTrajectories(origin, destination, true, {"AAL", "BAW"});
}

void test3() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR origin = make_shared<Coordinates>(Coordinates(48.8584, 2.2944, 30));
    LocalPTR destination = make_shared<Coordinates>(Coordinates(40.6894, -74.0444, 30));

    listingApplication.showTrajectories(origin, destination, false, {});
}

void test4() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR local = make_shared<AirportLocal>("OPO");

    //listingApplication.numberReachableCountries(local, 1);
}

void test6() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    listingApplication.listAirportsByCity({"Porto", "Portugal"});
}

void test7() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    auto n = database->getFlightMapPtr()->articulationPoints();

    cout << endl << "Number of articulation points: " << n.size() << endl << endl;
}

void test8() {
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    auto n = database->getFlightMapPtr()->connectedComponents();

    cout << "Number of components: " << n << endl << endl;
}

int main() {

    Application app;
    app.startApplication();

    return 0;
}