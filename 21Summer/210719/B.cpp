#include <iostream>
const int MOD = 1e9 + 9;
long long jc[10000001], ny[10000001], pow2[10000001];
long long qpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1) (ans *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ans;
}
long long c(long long n, long long m)
{
    if (n > m || n < 0 || m < 0) return 0;
    if (n == 0 || n == m) return 1;    
    return jc[m] * ny[n] % MOD * ny[m - n] % MOD; 
}
int main() {
    jc[0] = jc[1] = 1;
    ny[0] = ny[1] = 1;
    pow2[0] = 1;
    for (int i = 1; i <= 1e7; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    for (int i = 2; i <= 1e7; i++) 
        jc[i] = 1ll * jc[i - 1] * i % MOD;
    ny[10000000] = qpow(jc[10000000], MOD - 2);
    for (int i = 1e7; i >= 2; --i)
        ny[i - 1] = ny[i] * i % MOD;
    int x, y;
    std::cin >> x >> y;
    long long ans = 0;  
    for (int i = 0; i <= x + y - 4; i++) {
        long long temp = pow2[i];
        (temp *= jc[i]) %= MOD;
        (temp *= c(i, x + y - 4)) %= MOD;
        ans ^= temp;
    }
    std::cout << ans << ' ';
    ans = 0;
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i <= x - 2; i++) 
        (sum1 += c(i, x + y - 4)) %= MOD;
    for (int i = 0; i < x - 2; i++)
        (sum2 += c(i, x + y - 4)) %= MOD;
    for (int i = x + y - 4; i >= 0; i--) {
        long long temp = pow2[x + y - 4 - i];
        (((((temp *= jc[x - 2]) %= MOD) *= jc[y - 2]) %= MOD) *= ny[i]) %= MOD;
        if (i != x + y - 4) {
            (((sum1 += c(x - 2, i)) %= MOD) *= ny[2]) %= MOD;
            ((((sum2 -= c(2 + i - y, i + 1)) += c(1 + i - y, i)) %= MOD) *= ny[2]) %= MOD;  
        }        
        (temp *= sum1 + MOD - sum2) %= MOD;
        ans ^= temp;
    }
    std::cout << ans;
    return 0;
}