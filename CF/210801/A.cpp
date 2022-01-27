#include <iostream>
#include <cmath>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        bool flag = 0;
        int temp;
        std::cin >> temp;
        if (temp == 5)
            std::cout << 2 << ' ' << 4 << std::endl;
        else
            std::cout << 2 << ' ' << temp / 2 << std::endl;          
    }
}