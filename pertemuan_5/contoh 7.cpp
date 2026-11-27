#include <iostream>

int main() {
    std::cout << "Loop tanpa break/continue : ";
    for (int i = 1; i <= 5; ++i) std::cout << i << ' ';
    std::cout << "\n";

    std::cout << "continue pada i == 3      : ";
    for (int i = 1; i <= 5; ++i) {
        if (i == 3) continue;  
        std::cout << i << ' ';
    }
    std::cout << "\n";

    std::cout << "break pada i == 3         : ";
    for (int i = 1; i <= 5; ++i) {
        if (i == 3) break;  
        std::cout << i << ' ';
    }
    std::cout << "\n\n";

    std::cout << "Nested loop, continue di loop dalam:\n";
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (j == 2) continue;  
            std::cout << "(" << i << "," << j << ") ";
        }
        std::cout << '\n';
    }

    return 0;
}