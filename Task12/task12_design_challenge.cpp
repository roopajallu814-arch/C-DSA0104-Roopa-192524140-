#include <array>
#include <iostream>
#include <cstddef>

enum class Zone {
    Inner = 0,
    Middle = 1,
    Outer = 2,
    Airport = 3
};

constexpr std::array<long long, 4> BASE_FARE_PAISE{
    1000, 2000, 3000, 6000
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(Zone zone, int hour, bool weekend) {
    int index = static_cast<int>(zone);

    if (index < 0 ||
        index >= static_cast<int>(BASE_FARE_PAISE.size())) {
        return -1;
    }

    if (hour < 0 || hour > 23) {
        return -1;
    }

    long long fare =
        BASE_FARE_PAISE[static_cast<std::size_t>(index)];

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    // Weekend discount takes priority over peak surcharge.
    if (weekend) {
        fare -= fare * WEEKEND_DISCOUNT_PERCENT / 100;
    } else if (peak) {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;
    bool active;

public:
    MonthlyPass(Zone first, Zone second, bool isActive = true)
        : firstZone(first), secondZone(second), active(isActive) {}

    bool covers(Zone zone) const {
        return active &&
               (zone == firstZone || zone == secondZone);
    }
};

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long balance)
        : balancePaise(balance >= 0 ? balance : 0) {}

    long long balance() const {
        return balancePaise;
    }

    bool deduct(long long fare) {
        if (fare < 0 ||
            balancePaise - fare < MIN_BALANCE_PAISE) {
            return false;
        }

        balancePaise -= fare;
        return true;
    }
};

int main() {
    SmartCard card(20000);  // ₹200.00

    // Monthly pass covers Inner and Airport zones.
    MonthlyPass pass(Zone::Inner, Zone::Airport);

    long long airportWeekend =
        calculateFare(Zone::Airport, 9, true);

    std::cout << "Airport weekend fare paise: "
              << airportWeekend << '\n';

    std::cout << "Airport covered by pass: "
              << (pass.covers(Zone::Airport) ? "yes" : "no")
              << '\n';

    if (!pass.covers(Zone::Airport) &&
        card.deduct(airportWeekend)) {
        std::cout << "Charged. Balance paise: "
                  << card.balance() << '\n';
    } else if (pass.covers(Zone::Airport)) {
        std::cout << "No fare charged: monthly pass covers this zone.\n";
    } else {
        std::cout << "Journey denied: minimum balance rule.\n";
    }

    return 0;
}
