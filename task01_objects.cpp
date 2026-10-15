
#include <iostream>
#include <string>
using namespace std;

class MetroCard {
public:
    string cardHolder;
    int cardId;
    double balance;

    void displayDetails() {
        cout << "Metro Smart Card Details" << endl;
        cout << "Card Holder: " << cardHolder << endl;
        cout << "Card ID: " << cardId << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    MetroCard card;

    card.cardHolder = "Roopa";
    card.cardId = 1001;
    card.balance = 500.0;

    card.displayDetails();

    return 0;
}
