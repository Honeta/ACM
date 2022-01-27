#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, a[10001];
        std::cin >> n;
        for (int i = 1; i <= n; i++)
            std::cin >> a[i];
        if (a[1] == 1) {
            std::cout << n + 1 << ' ';
            for (int i = 1; i <= n; i++)
                std::cout << i << ' ';
        } else if (a[n] == 0) {            
            for (int i = 1; i <= n; i++)
                std::cout << i << ' ';
            std::cout << n + 1 << ' ';
        } else {
            for (int i = 1; i <= n; i++)
                if (a[i] == 1 && a[i - 1] == 0) {
                    for (int j = 1; j < i; j++)
                        std::cout << j << ' ';
                    std::cout << n + 1 << ' ';
                    for (int j = i; j <= n; j++)
                        std::cout << j << ' ';
                    break;
                }
        }
        std::cout << std::endl;
    }
    return 0;
}