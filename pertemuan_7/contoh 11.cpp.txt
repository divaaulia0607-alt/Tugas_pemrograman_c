#include <iostream>

long long jumlahPanggilan = 0; // untuk statistik demonstrasi

long long fibonacci(int n) {
    ++jumlahPanggilan;

    if (n <= 1) {
        return n; // base case
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Berapa suku Fibonacci (0..30)? ";
    std::cin >> n;

    if (n < 0 || n > 30) {
        std::cout << "n harus 0 sampai 30 untuk demonstrasi ini.\n";
        return 1;
    }

    std::cout << "Deret: ";
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacci(i);
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << '\n';

    std::cout << "Total pemanggilan fibonacci(): " << jumlahPanggilan << '\n';
    std::cout << "Perhatikan: jumlah ini tumbuh sangat cepat (eksponensial).\n";

    return 0;
}