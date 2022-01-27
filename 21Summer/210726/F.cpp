#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int t1, t2;
        std::cin >> t1 >> t2;
    }
    if (n + m & 1) std::cout << "Alice";
    else std::cout << "Bob";
}