#include <iostream>
#define MOD 998244353
unsigned long long qpow(unsigned long long a,  unsigned long long n) {
    unsigned long long ans = 1;
    while (n) {
        if (n & 1) 
            (ans *= a) %= MOD;
        (a *= a) %= MOD; 
        n >>= 1; 
    }
    return ans;
}
int main() {
    unsigned long long n,s,d,ans;
    std::cin >> n >> s >> d;
    ans = ((s % MOD * 2) % MOD + (n % MOD) * (d % MOD)) % MOD;
    (ans *= qpow(2, n - 1)) %= MOD;
    std::cout << ans;
    return 0;
}