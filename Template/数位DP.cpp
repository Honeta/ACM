#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 13;

int num[N + 1], cnt;
long long f[N + 1][2][N + 1][2];

long long dp(int k, bool limit, int sum, bool zero, int target) {
    if (k == cnt + 1) return sum;
    if (f[k][limit][sum][zero] != -1) 
        return f[k][limit][sum][zero];
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        if (limit && i > num[k]) break;
        ans += dp(k + 1, limit && i == num[k], 
            sum + (!(zero && i == 0) && i == target), 
            zero && i == 0, target);
    }
    f[k][limit][sum][zero] = ans;
    return ans;
}

long long solve(long long x, int target) {
    cnt = 0;
    while (x) {
        num[++cnt] = x % 10;
        x /= 10;
    }
    std::reverse(num + 1, num + cnt + 1);
    memset(f, -1, sizeof(f));
    return dp(1, true, 0, true, target);
}

int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    for (int i = 0; i <= 9; i++)
        printf("%lld ", solve(b, i) - solve(a - 1, i));
}