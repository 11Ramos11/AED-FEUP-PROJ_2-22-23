
#include "application/Application.h"

void test1(){
    DatabasePTR database = make_shared<Database>();
    database->read();
    ListingApplication listingApplication(database);

    LocalPTR origin = make_shared<AirportLocal>("OPO");
    LocalPTR destination = make_shared<AirportLocal>("ORD");

    listingApplication.showTrajectories(origin, destination);
}

int main() {

    Application app;
    app.startApplication();

    return 0;
}