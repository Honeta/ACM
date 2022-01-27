#include <iostream>
int main() {
    int t, xo[300004];
    xo[0] = 0;
    xo[1] = 0;
    for (int i = 1; i <= 300000; i++)
        xo[i + 1] = xo[i] ^ i;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        int temp = xo[a];
        if (temp == b) std::cout << a << std::endl;
        else if ((temp ^ b) == a) std::cout << a + 2 << std::endl;
        else std::cout << a + 1 << std::endl;
    }
    return 0;
}