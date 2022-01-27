#include <iostream>
const long long MOD = 1e9 + 7;
long long sum[1000005], now[1000005], ans;
int main() {
    int n, temp;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> temp;
        now[i] = now[i - 1] + temp;
        sum[i] = sum[i - 1] + i;
        ans += now[i] - sum[i];
        if (ans >= MOD)
            ans %= MOD;
    }
    std::cout << ans;
    return 0;
}