#include <iostream>
const int MOD = 998244353;
long long ans, n, p[5001], cnt[5001], inv[5001];
long long f[5001][5001];
int qpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % n;
        y >>= 1;
    }
    return ans;
}
int main() {    
    std::cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    for (int i = 1; i <= n; i++) 
        std::cin >> p[i];
    for (int i = n; i >= 1; i--) {
        long long sum = 0, cnt = 0;
        for (int j = n; j >= 0; j--)
            if (p[j] > i) {
                cnt++;
                sum = (sum + f[i][p[j]]) % MOD;
            } else {
                f[p[j]][i] = 1 + sum * inv[cnt] % MOD;
            }
    }
    for (int i = 1; i <= n; i++)
        (ans += f[0][i]) %= MOD;
    (ans *= inv[n]) %= MOD;
    std::cout << ans;
    return 0;
}