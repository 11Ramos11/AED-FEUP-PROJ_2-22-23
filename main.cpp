
#include "application/Application.h"
#include "Graph/Locals/Coordinates.h"

void test1(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);

    LocalPTR origin = make_shared<AirportLocal>("OPO");
    LocalPTR destination = make_shared<AirportLocal>("LIS");

    listingApplication.showTrajectories(origin, destination);
}

void test2(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR destination = make_shared<CityLocal>(City("London", "United Kingdom"));
    LocalPTR origin = make_shared<CityLocal>(City("Porto", "Portugal"));

    listingApplication.showTrajectories(origin, destination);
}

void test3(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR origin = make_shared<Coordinates>(Coordinates(48.8584, 2.2944, 30));
    LocalPTR destination = make_shared<Coordinates>(Coordinates(40.6894, -74.0444, 30));

    listingApplication.showTrajectories(origin, destination);
}

void test4(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR local = make_shared<AirportLocal>("OPO");

    listingApplication.numberReachableCountries(local, 1);
}

void test6(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


   listingApplication.listAirportsByCity({"Porto", "Portugal"});
}

void test7(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    auto n = database->getFlightMapPtr()->articulationPoints();

    cout << "Number of articulation points: " << n.size() << endl << endl;
}

int main() {

    test7();

    Application app;
    app.startApplication();

    return 0;
}