#include <iostream>
#include <string>
using namespace std;

int main() {
    int cardId = 1001;
    string passengerName = "Roopa";
    double balance = 450.50;
    char cardType = 'M';
    bool cardActive = true;

    cout << "Metro Card Data Types" << endl;
    cout << "Card ID: " << cardId << endl;
    cout << "Passenger: " << passengerName << endl;
    cout << "Balance: Rs. " << balance << endl;
    cout << "Card Type: " << cardType << endl;
    cout << "Active: " << boolalpha << cardActive << endl;

    return 0;
}
