#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 1000, M = 1000;

struct item {int w, v;};

int ans[M + 1];
std::vector<item> v[N + 1];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v[c].push_back({a, b});
    }
    for (int i = 1; i <= m; i++)
        ans[i] = -0x7fffffff;    
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (auto x : v[i])
                if (j >= x.w && ans[j - x.w] >= 0)
                    ans[j] = std::max(ans[j], ans[j - x.w] + x.v);
    for (int i = 1; i <= m; i++)
        ans[i] = std::max(ans[i], ans[i - 1]);
    printf("%d", ans[m]);
}