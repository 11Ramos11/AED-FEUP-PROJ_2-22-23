
#include "application/Application.h"
#include "Graph/Locals/Coordinates.h"

void test1(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);

    LocalPTR origin = make_shared<AirportLocal>("OPO");
    LocalPTR destination = make_shared<AirportLocal>("ORD");

    listingApplication.showTrajectories(origin, destination);
}

void test2(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);


    LocalPTR origin = make_shared<Coordinates>(Coordinates(41.24, -8.67, 5));
    LocalPTR destination = make_shared<Coordinates>(Coordinates(38.771, -9.13, 5));

    listingApplication.showTrajectories(origin, destination);
}

int main() {

    test2();

    Application app;
    app.startApplication();

    return 0;
}