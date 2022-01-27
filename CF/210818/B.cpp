#include <iostream>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if ((b > a && b < a * 2) || (b < a && a < b * 2))
            std::cout << "-1" << std::endl;
        else if ((a > b && c > 2 * (a - b)) || (a < b && c > 2 * (b - a)))
            std::cout << "-1" << std::endl;
        else if ((a > b && c > a - b) || (b > a && c > b - a))
            std::cout << c - std::abs(b - a) << std::endl;
        else
            std::cout << c + std::abs(b - a)  << std::endl;
    }
    return 0;
}