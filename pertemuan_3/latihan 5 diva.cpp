#include <iostream>

int main() {
    int a, b;
    std::cout << "Masukkan a dan b: ";
    std::cin >> a >> b;
    
    std::cout << "Sebelum  : a = " << a << ", b = " << b << '\n';

    int temp = a;
    a = b;
    b = temp;

    std::cout << "Sesudah  : a = " << a << ", b = " << b << '\n';
return 0;
}