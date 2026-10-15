
#include <iomanip>
#include <iostream>

enum class Zone {
    Inner,
    Middle,
    Outer
};

constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(Zone zone, bool peak) {
    long long fare = 0;

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
    }

    if (peak) {
        fare += fare * 20 / 100;
    }

    return fare;
}

bool processJourney(long long& balance, long long fare) {
    if (fare < 0 || balance - fare < MIN_BALANCE_PAISE) {
        return false;
    }

    balance -= fare;
    return true;
}

int main() {
    long long balance = 10000;

    struct Test {
        Zone zone;
        bool peak;
    };

    Test tests[] = {
        {Zone::Inner, false},
        {Zone::Outer, true},
        {Zone::Middle, false}
    };

    for (const Test& test : tests) {
        long long fare = calculateFare(test.zone, test.peak);

        if (processJourney(balance, fare)) {
            std::cout << "Fare Rs "
                      << fare / 100 << '.'
                      << std::setw(2) << std::setfill('0')
                      << fare % 100
                      << std::setfill(' ');
        } else {
            std::cout << "Denied (low balance)";
        }

        std::cout << " balance Rs "
                  << balance / 100 << '\n';
    }

    return 0;
}
