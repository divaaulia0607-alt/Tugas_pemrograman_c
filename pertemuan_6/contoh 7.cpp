#include <iostream>

void hitungPanggilan() {
    int biasa = 0;        // diinisialisasi ulang pada setiap panggilan
    static int statis = 0; // diinisialisasi sekali, lalu nilainya bertahan

    ++biasa;
    ++statis;

    std::cout << "biasa = " << biasa 
              << ", statis = " << statis << '\n';
}

void cetakIdSesi() {
    static int id = 100;   // id sesi yang konsisten selama program berjalan
    ++id;
    std::cout << "ID sesi berikutnya: " << id << '\n';
}

int main() {
    std::cout << "=== Demo static lokal ===\n";
    for (int i = 0; i < 4; ++i) {
        hitungPanggilan();
    }

    std::cout << "\n=== Demo id sesi ===\n";
    cetakIdSesi();
    cetakIdSesi();
    cetakIdSesi();

    return 0;
}