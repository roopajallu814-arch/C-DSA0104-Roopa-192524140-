#include <iostream>
using namespace std;

int main() {
    double baseFare = 20.0;
    int journeys = 3;

    double totalFare = baseFare + 5 * journeys;
    double groupedFare = (baseFare + 5) * journeys;

    cout << "Metro Fare - Operators and Precedence" << endl;
    cout << "Base Fare: Rs. " << baseFare << endl;
    cout << "Number of Journeys: " << journeys << endl;
    cout << "Fare using precedence: Rs. " << totalFare << endl;
    cout << "Fare using parentheses: Rs. " << groupedFare << endl;

    return 0;
}
