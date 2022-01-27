#include <iostream>
#include <cmath>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int k;
        std::cin >> k;
        int s = sqrt(k);
        if (s * s == k) std::cout << s << " 1" << std::endl;
        else if (s * s + s + 1 >= k) std::cout << k - s * s << ' ' << s + 1 << std::endl;
        else std::cout << s + 1 << ' ' << s + 1 - (k - (s * s + s + 1)) << std::endl;
    }
    return 0;
}