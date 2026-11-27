#include <iostream>

int main() {
	int n;
    int suku = 3;
    int ganjil = 0;
    int jumlah = 0;
    float rataRata;
    
    std::cout << "Masukkan angka: ";
    std::cin >> n;
    
    if (n < 1 || n > 20) {
        return 0;
    }
    
    std::cout << "Deret : ";
    
    for (int i = 1; i <= n; i++) {
    	std::cout << suku << " ";
    	
    	jumlah += suku;
    	if (suku % 3 != 0) {
    		ganjil++;
        }
        
        suku += 10;
    }
        
        rataRata = (float)jumlah / n;
        
        std::cout << "\nJumlah    : " << jumlah;
        std::cout << "\nRata-rata : " << rataRata;
        std::cout << "\nGanjil    : " << ganjil;
        
        return 0;
}