#include <iostream>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, m;
        std::cin >> a >> b >> c >> m;
        if (a - 1 + b - 1 + c - 1 < m) {
            std::cout << "NO" << std::endl;
            continue;
        } else {
            int st = std::max(std::max(a, b), c);
            int rd = std::min(std::min(a, b), c);
            int nd = a + b + c - st - rd;
            if (st - rd - nd - 1 > m) {
                std::cout << "NO" << std::endl;
                continue;
            }
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}