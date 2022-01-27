#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        while (n--) {
            char m;
            std::cin >> m;
            if (m == 'D') std::cout << 'U';
            else if (m == 'U') std::cout << 'D';
            else std::cout << m;
        }
        std::cout << std::endl;
    }
    return 0;
}