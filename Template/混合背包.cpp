#include <cstdio>
#include <algorithm>

const int T = 1000, N = 1e4;

int w[N + 1], v[N + 1], c[N + 1], ans[T + 1];

int main() {    
    int t1, t2, t3, t4;
    scanf("%d:%d%d:%d", &t1, &t2, &t3, &t4);
    int t, n;
    t = t3 * 60 + t4 - (t1 * 60 + t2);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &w[i], &v[i], &c[i]);
    for (int i = 1; i <= t; i++)
        ans[i] = -0x7fffffff;
    for (int i = 1; i <= n; i++)
        switch (c[i]) {
            case 0: 
                for (int j = w[i]; j <= t; j++)
                    if (ans[j - w[i]] >= 0)
                        ans[j] = std::max(ans[j], ans[j - w[i]] + v[i]);
                break;
            case 1:
                for (int j = t; j >= w[i]; j--)
                    if (ans[j - w[i]] >= 0)
                        ans[j] = std::max(ans[j], ans[j - w[i]] + v[i]);
                break;
            default:
                for (int k = 1; k <= c[i]; k++)
                    for (int j = t; j >= w[i]; j--)
                        if (ans[j - w[i]] >= 0)
                            ans[j] = std::max(ans[j], ans[j - w[i]] + v[i]);
        }
    for (int i = 1; i <= t; i++)
        ans[i] = std::max(ans[i], ans[i - 1]);
    printf("%d", ans[t]);
}