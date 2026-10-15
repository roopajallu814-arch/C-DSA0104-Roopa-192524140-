#include <iostream>
using namespace std;

int main() {
    int journeys = 3;
    double farePerJourney = 25.50;

    double totalFare = journeys * farePerJourney;
    int roundedFare = totalFare;

    cout << "Implicit Type Conversion" << endl;
    cout << "Number of Journeys: " << journeys << endl;
    cout << "Fare Per Journey: Rs. " << farePerJourney << endl;
    cout << "Total Fare: Rs. " << totalFare << endl;
    cout << "Total Fare Converted to int: " << roundedFare << endl;

    return 0;
}
