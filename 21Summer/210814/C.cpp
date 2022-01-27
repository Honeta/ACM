#include <iostream>
const int MOD = 998244353;
int main() {
    int n, a[500001];
    long long ans;
    std::cin >> n;
    for (int i = 1; i <= n; i++) 
        std::cin >> a[i];
    ans = a[1] + 1;
    for (int i = 2; i <= n; i++) {
        ans = ans * (ans + a[i] - a[i - 1]) / 2 % MOD;
    }
    std::cout << ans;
    return 0;
}