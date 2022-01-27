#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y;
        std::cin >> x >> y;
        if (x == y) {
            std::cout << x << std::endl;
        } else if (x < y) {
            
        } else {
            std::cout << x + y << std::endl;
        }
    }
}