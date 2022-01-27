#include <iostream>
#include <string.h>
const int MOD = 998244353;
int t, n, m, a, b, ans1[500001], ans2[500001];
int jc[500001], ny[500001];
int qpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return ans;
}
int Comb(int x, int y) {return 1LL * jc[x] * ny[y] % MOD * ny[x - y] % MOD;}
void process_small(int n, int a, int ans[]) {    
    int f[1001], f_bak[1001];
    memset(f, 0, sizeof(f));
    f[a] = 1;
    for (int k = 1; k <= t; k++) {
        memcpy(f_bak, f, sizeof(f));
        f[1] = f_bak[2];
        f[n] = f_bak[n - 1];
        ans[k] = (f[1] + f[n]) % MOD;
        for (int i = 2; i < n; i++) {
            f[i] = (f_bak[i - 1] + f_bak[i + 1]) % MOD;
            (ans[k] += f[i]) %= MOD;
        }            
    }
}
void process_large(int n, int a, int ans[]) {
    int f1 = 0, fn = 0;
    for (int k = 1; k <= t; k++) {
        
        ans[k] = (ans[k - 1] * 2 - f1 - fn) % MOD;
    }
}
int main() {    
    std::cin >> t >> n >> m >> a >> b;
    jc[0] = 1;
    for (int i = 1; i <= t; i++)
        jc[i] = jc[i - 1] * i;
    ny[t] = qpow(jc[t], MOD - 2);
    for (int i = t - 1; i >= 1; i--)
        ny[i] = (ny[i + 1] * (i + 1)) % MOD;
    if (n <= 1000) process_small(n, a, ans1);
    else process_large(n, a, ans1);
    if (m <= 1000) process_small(m, b, ans2);
    else process_large(m, b, ans2);
    return 0;
}