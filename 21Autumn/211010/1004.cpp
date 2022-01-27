#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x;
        std::cin >> x;
        if (x == 1) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}