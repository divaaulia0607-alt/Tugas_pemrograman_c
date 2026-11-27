#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_BARANG = 100;

void menuUtama() {
    cout << "\n========================================\n";
    cout << "       PROGRAM KASIR TOKO SEDERHANA     \n";
    cout << "========================================\n";
    cout << "1. Transaksi Baru\n";
    cout << "2. Keluar\n";
    cout << "Pilihan Anda: ";
}

int inputBarang(string namaBarang[], long hargaSatuan[], int jumlah[], long subtotal[], int *totalJenis) {
    char lanjut;
    int i = 0;

    do {
        cout << "\n--- Data Barang ke-" << (i + 1) << " ---\n";
        cout << "Nama barang   : ";
        cin >> ws; 
        getline(cin, namaBarang[i]);

        do {
            cout << "Harga satuan  : Rp";
            cin >> hargaSatuan[i];
            if (hargaSatuan[i] < 1000 || hargaSatuan[i] > 100000000) {
                cout << "[Error] Harga harus di antara Rp1.000 - Rp100.000.000!\n";
            }
        } while (hargaSatuan[i] < 1000 || hargaSatuan[i] > 100000000);

        do {
            cout << "Jumlah barang : ";
            cin >> jumlah[i];
            if (jumlah[i] < 1 || jumlah[i] > 1000) {
                cout << "[Error] Jumlah barang harus di antara 1 - 1.000!\n";
            }
        } while (jumlah[i] < 1 || jumlah[i] > 1000);

        subtotal[i] = hargaSatuan[i] * jumlah[i];
        i++;
        *totalJenis = i;

        if (i >= MAX_BARANG) {
            cout << "Kapasitas barang sudah penuh!\n";
            break;
        }

        cout << "Tambah barang lagi? (y/t): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}

long hitungSubtotalTotal(long subtotal[], int totalJenis) {
    long total = 0;
    for (int idx = 0; idx < totalJenis; idx++) {
        total += subtotal[idx];
    }
    return total;
}

long hitungBesarDiskon(long totalSubtotal) {
    long diskon = 0;
    if (totalSubtotal >= 500000) {
        diskon = totalSubtotal * 0.15; 
    } else if (totalSubtotal >= 250000) {
        diskon = totalSubtotal * 0.10; 
    } else if (totalSubtotal >= 100000) {
        diskon = totalSubtotal * 0.05; 
    } else {
        diskon = 0; 
    }
    return diskon;
}

long hitungPajakNilai(long setelahDiskon) {
    return (long)(setelahDiskon * 0.11);
}

long prosesBayar(long totalTagihan) {
    long bayar;
    cout << "\n----------------------------------------\n";
    cout << "Total yang harus dibayar: Rp" << totalTagihan << endl;
    do {
        cout << "Masukkan uang bayar     : Rp";
        cin >> bayar;
        if (bayar < totalTagihan) {
            cout << "[Peringatan] Uang pembayaran kurang! Silakan ulangi.\n";
        }
    } while (bayar < totalTagihan);
    return bayar;
}

void cetakStrukBelanja(string namaBarang[], long hargaSatuan[], int jumlah[], long subtotal[], int totalJenis, long subTotalTotal, long diskon, long pajak, long totalAkhir, long bayar, long kembalian) {
    cout << "\n========================================\n";
    cout << "              STRUK KASIR TOKO          \n";
    cout << "========================================\n";
    
    for (int k = 0; k < totalJenis; k++) {
        cout << "- " << namaBarang[k] << endl;
        cout << "  " << jumlah[k] << " x Rp" << hargaSatuan[k] 
             << " = Rp" << subtotal[k] << endl;
    }
    
    cout << "----------------------------------------\n";
    cout << "Subtotal     : Rp" << subTotalTotal << endl;
    cout << "Diskon       : Rp" << diskon << endl;
    cout << "Pajak (11%)  : Rp" << pajak << endl;
    cout << "----------------------------------------\n";
    cout << "Total Akhir  : Rp" << totalAkhir << endl;
    cout << "Bayar        : Rp" << bayar << endl;
    cout << "Kembalian    : Rp" << kembalian << endl;
    cout << "========================================\n";
    cout << "        TERIMA KASIH TELAH BELANJA      \n";
    cout << "========================================\n";
}

int main() {
    int pilihanMenu;

    do {
        menuUtama();
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            string namaBarang[MAX_BARANG];
            long hargaSatuan[MAX_BARANG];
            int jumlah[MAX_BARANG];
            long subtotal[MAX_BARANG];
            int totalJenis = 0;

            inputBarang(namaBarang, hargaSatuan, jumlah, subtotal, &totalJenis);

            long subTotalTotal = hitungSubtotalTotal(subtotal, totalJenis);
            long diskon = hitungBesarDiskon(subTotalTotal);
            long setelahDiskon = subTotalTotal - diskon;
            long pajak = hitungPajakNilai(setelahDiskon);
            long totalAkhir = setelahDiskon + pajak;

            long bayar = prosesBayar(totalAkhir);
            long kembalian = bayar - totalAkhir;

            cetakStrukBelanja(namaBarang, hargaSatuan, jumlah, subtotal, totalJenis, subTotalTotal, diskon, pajak, totalAkhir, bayar, kembalian);

        } else if (pilihanMenu == 2) {
            cout << "\nProgram selesai. Terima kasih!\n";
        } else {
            cout << "\nPilihan tidak valid, coba lagi.\n";
        }

    } while (pilihanMenu != 2);

    return 0;
}