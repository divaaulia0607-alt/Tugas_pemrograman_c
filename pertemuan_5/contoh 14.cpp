#include <iostream>

int main() {
    int n;
    std::cout << "Masukkan bilangan desimal >= 0: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Bilangan harus >= 0.\n";
        return 1;
    }

    if (n == 0) {
        std::cout << "Biner: 0\n";
        return 0;
    }

    int pangkat = 1;
    while (pangkat <= n / 2) {
        pangkat *= 2;
    }

    std::cout << "Biner: ";
    while (pangkat >= 1) {
        std::cout << n / pangkat;  
        n %= pangkat;
        pangkat /= 2;
    }
    std::cout << '\n';

    return 0;
}