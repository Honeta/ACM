#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    if ((n * m - 1) & 1) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}