#include <iostream>
int n, k, c, p[100001], ext[100001];
int main() {    
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> p[i];
    std::cin >> c;
    for (int i = 1; i <= n; i++)
        if (p[i] < c/k || ext[p[i] - c/k])
            ext[p[i]] = 1;
    for (int i = c - c / k; i < c; ++i)
        if (ext[i]) {
            std::cout << 1;
            return 0;
        }
    std::cout << 0;
    return 0;
}