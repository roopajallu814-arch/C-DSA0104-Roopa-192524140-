#include <iomanip>
#include <iostream>

int main() {
    const int journeys = 3000000;

    long long totalPaise = 0;
    double totalRupees = 0.0;

    for (int i = 0; i < journeys; ++i) {
        totalPaise += 1000;
        totalRupees += 10.0;
    }

    std::cout << "Total journeys: " << journeys << '\n';
    std::cout << "Integer total paise: " << totalPaise << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Integer total rupees: "
              << totalPaise / 100.0 << '\n';
    std::cout << "Double total rupees: "
              << totalRupees << '\n';

    return 0;
}
