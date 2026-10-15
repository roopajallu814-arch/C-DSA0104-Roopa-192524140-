#include <iostream>

constexpr long long MIN_BALANCE_PAISE = 5000;

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long initialBalance)
        : balancePaise(initialBalance >= 0 ? initialBalance : 0) {}

    long long balance() const {
        return balancePaise;
    }

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 &&
               balancePaise - farePaise >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) {
            return false;
        }

        balancePaise -= farePaise;
        return true;
    }
};

int main() {
    SmartCard card(10000);

    if (card.deduct(3600)) {
        std::cout << "Journey allowed." << '\n';
    } else {
        std::cout << "Journey denied." << '\n';
    }

    std::cout << "Remaining balance: Rs "
              << card.balance() / 100 << "."
              << (card.balance() % 100 < 10 ? "0" : "")
              << card.balance() % 100 << '\n';

    return 0;
}
