#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n % 3 == 1) std::cout << n / 3 + 1 << ' ' << n / 3 << std::endl;
        else if (n % 3 == 2) std::cout << n / 3 << ' ' << n / 3 + 1 << std::endl;
        else std::cout << n / 3 << ' ' << n / 3 << std::endl;
    }
    return 0;
}