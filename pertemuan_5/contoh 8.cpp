#include <iostream>

int main() {
    int n;
    std::cout << "Masukkan bilangan bulat > 1: ";
    std::cin >> n;

    bool prima = (n > 1);

    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            prima = false;
            break;  
        }
    }

    if (prima)
        std::cout << n << " adalah bilangan PRIMA\n";
    else
        std::cout << n << " BUKAN bilangan prima\n";

    return 0;
}