#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "i = " << i << '\n';
    }

    std::cout << '\n';

    for (int i = 5; i >= 1; --i) {
        std::cout << "Turun: " << i << '\n';
    }

    std::cout << '\n';

    for (int i = 2; i <= 10; i += 2) {
        std::cout << "genap: " << i << '\n';
    }

    std::cout << '\n';

    for (int i = 0, j = 10; i < j; ++i, --j) {
        std::cout << "i=" << i << " j=" << j << '\n';
    }

    return 0;
}