#include <iostream>
#include <iomanip>

int main() {
	double n1 = 80;
	double n2 = 85;
	double n3 = 90;
	
	std::cout << "Nilai 1 : " << n1 << '\n';
	std::cout << "Nilai 2 : " << n2 << '\n';
	std::cout << "Nilai 3 : " << n3 << '\n';
	
	std::cout << std::fixed <<std::setprecision(2);
	std::cout << "Rata-rata: " << (n1 + n2 + n3) / 3.0 << '\n';
	return 0;
}