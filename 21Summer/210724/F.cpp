#include <iostream>
#include <cmath>
int main() {
    int n, m;
    std::cin >> n >> m;
    if (m > pow(13, n)) {
        std::cout << 0;
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= 13; i++)
        for (int j = 1; j < i; j++)
            for (int k = 1; k <= 13; k++)
                if (k % i && k * j % i == 0) 
                    for (int l = 1; l <= 13; l++)
                        if (k * j / i + l == 24 || k * j / i - l == 24 || (l % i && k * j / i * l == 24) || k * j / i / l == 24) {
                            ++ans;
                            std::cout << j << ' ' << i << ' ' << k << ' ' << l << std::endl;
                        }
    std::cout << ans << std::endl;
    return 0;
}