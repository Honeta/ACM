#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if ((i * i + j * j) % (i * j + 1) == 0)
                std::cout << i << ' ' << j << std::endl;
    return 0;
}