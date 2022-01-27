#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int c, d;
        std::cin >> c >> d;
        if (c == d && c == 0) std::cout << 0 << std::endl;
        else if (c == d) std::cout << 1 << std::endl;
        else if ((c + d) / 2 * 2 == c + d) std::cout << 2 << std::endl;
        else std::cout << -1 << std::endl;
    }
    return 0;
}