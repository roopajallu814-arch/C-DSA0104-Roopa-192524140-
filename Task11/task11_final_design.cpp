#include <iostream>

enum class Zone {
    Inner,
    Middle,
    Outer
};

constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;

long long calculateFare(Zone zone, bool peak) {
    long long fare;

    switch (zone) {
        case Zone::Inner:
            fare = 1000;
            break;
        case Zone::Middle:
            fare = 2000;
            break;
        case Zone::Outer:
            fare = 3000;
            break;
        default:
            return -1;
    }

    if (peak) {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 &&
           balance - fare >= MIN_BALANCE_PAISE;
}

int main() {
    long long balance = 10000;

    long long fare = calculateFare(Zone::Outer, true);

    if (canTravel(balance, fare)) {
        balance -= fare;
        std::cout << "Journey approved.\n";
    } else {
        std::cout << "Journey denied.\n";
    }

    std::cout << "Fare in paise: " << fare << '\n';
    std::cout << "Remaining balance in paise: "
              << balance << '\n';

    return 0;
}
