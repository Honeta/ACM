#include <iostream>
int ans[200001];
int main() {
    long long n, m;
    std::cin >> n >> m;
    ans[n] = ans[n - 1] = 1;
    for (int i = n - 2; i >= 1; i--)
        ans[i] = (ans[i + 1] << 1LL) % m;
    for (int i = n; i >= 2; i--)
        for (int j = 2; j <= i; j++)
            (ans[i / j] += ans[i]) %= m;
    std::cout << ans[1] << std::endl;
    return 0;
}