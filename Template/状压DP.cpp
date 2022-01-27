#include <cstdio>
#include <algorithm>

const int N = 9;

bool valid[1 << N];
int cnt[1 << N];
long long f[N + 1][1 << N][N * N + 1], ans;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < (1 << n); i++) {
        valid[i] = !(i & (i << 1));
        if (!valid[i]) continue;
        for (int k = 0; k < n; k++)
            if ((i & (1 << k)))
                ++cnt[i];
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (valid[j])
                for (int k = cnt[j]; k <= std::min(i * n, m); k++)
                    for (int l = 0; l < (1 << n); l++)
                        if (valid[l] && !(j & l) && !(j & (l << 1)) && !((j << 1) & l))
                            f[i][j][k] += f[i - 1][l][k - cnt[j]];
    for (int i = 0; i < (1 << n); i++)
        ans += f[n][i][m];
    printf("%lld", ans);
}