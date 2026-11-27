#include <iostream>

int main() {
    int tinggi = 5;

    for (int baris = 1; baris <= tinggi; ++baris) {
        for (int kolom = 1; kolom <= baris; ++kolom) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for (int baris = 1; baris <= tinggi; ++baris) {
        for (int spasi = 1; spasi <= tinggi - baris; ++spasi) {
            std::cout << ' ';
        }

        for (int bintang = 1; bintang <= 2 * baris - 1; ++bintang) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}