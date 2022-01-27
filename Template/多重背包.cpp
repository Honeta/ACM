#include <cstdio>
#include <algorithm>

const int T = 1000, M = 100;

int w[M + 1], v[M + 1], c[M + 1], ans[T + 1];

int main() {
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &w[i], &v[i], &c[i]);
    for (int i = 1; i <= t; i++)
        ans[i] = -0x7fffffff;
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= c[i]; k++)
            for (int j = t; j >= w[i]; j--)
                if (ans[j - w[i]] >= 0)
                    ans[j] = std::max(ans[j], ans[j - w[i]] + v[i]);
    for (int i = 1; i <= t; i++)
        ans[i] = std::max(ans[i], ans[i - 1]);
    printf("%d", ans[t]);
    return 0;
}