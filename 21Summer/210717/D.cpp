#include <iostream>
#include <array>
int main() {
    int n, m, temp;
    std::cin >> n;
    std::array<std::array<int, 2001>, 2001> a;
    std::array<int, 2001> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            std::cin >> a[i][j];
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
        b[i] = 1;
    }
    return 0;
}