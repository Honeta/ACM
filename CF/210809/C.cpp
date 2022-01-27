#include <iostream>
const long long MOD = 1e9 + 7;
long long qpow(long long a, long long n)
{
    long long ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * 1LL * a) % MOD;
        }
        a = (a * 1LL * a) % MOD;
        n >>= 1;
    }
    return ans;
}
int main() {    
    long long p[200001];
    p[0] = 1;
    for (int i = 1; i <= 200000; i++) 
        p[i] = p[i - 1] * 2 % MOD;
    int t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        long long ans = 0;
        if (n & 1) {
            ans = qpow(p[n - 1] + 1, k) % MOD;
        } else {
            long long temp = 1;
            for (int i = 1; i <= k; i++) {
                if (i > 1)
                    temp = temp * 1LL * (p[n - 1] - 1) % MOD;
                (ans += p[k - i] * 1LL * temp % MOD) %= MOD;
            }                
            (ans += qpow(p[n - 1] - 1, k) % MOD) %= MOD;
        }
        std::cout << ans << std::endl;
    } 
    return 0;
}