#include <iostream>
#include <limits>

int main() {
    int hour{};

    std::cout << "Enter hour (0-23): ";

    while (!(std::cin >> hour) || hour < 0 || hour > 23) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
        }

        std::cout << "Invalid hour. Enter an integer from 0 to 23: ";
    }

    std::cout << "Accepted hour: " << hour << '\n';

    return 0;
}
