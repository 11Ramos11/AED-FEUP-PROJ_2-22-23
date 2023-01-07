
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

int main() {

    test2();

    Application app;
    app.startApplication();

    return 0;
}