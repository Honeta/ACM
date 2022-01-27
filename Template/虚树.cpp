#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

const int N = 2.5e5, K = 2.5e5, LogN = 18;

struct edge {
    int to;
    long long w;
};

int dfn[N + 1], dfn_time, fa[N + 1][LogN + 1];
long long d[N + 1], min_w[N + 1][LogN + 1], a[K], f[N + 1];
bool flag[N + 1];
std::vector<edge> g[N + 1], tree[N + 1];

void dfs(int x, long long now_min, int depth) {
    d[x] = depth;
    dfn[x] = ++dfn_time;
    for(int i = 1; (1 << i) <= d[x]; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        min_w[x][i] = std::min(min_w[x][i - 1], min_w[fa[x][i - 1]][i - 1]);
    }
    for (auto nxt : g[x])
        if (nxt.to != fa[x][0]) {
            fa[nxt.to][0] = x;
            min_w[nxt.to][0] = nxt.w;
            dfs(nxt.to, std::min(now_min, nxt.w), depth + 1);
        }
}

int get_lca(int x, int y) {
    if (d[x] < d[y]) std::swap(x, y);
    while (d[x] > d[y])
        x = fa[x][int(log2(d[x] - d[y]))];
    if (x == y) return x;
    for (int i = log2(d[x]); i >= 0; --i) {
        if (fa[x][i] == fa[y][i]) continue;
        x = fa[x][i];
        y = fa[y][i];
    }
    return fa[x][0];
}

int get_min(int x, int y) {
    long long ans = 1LL << 50;
    if (d[x] < d[y]) std::swap(x, y);
    while (d[x] > d[y]) {
        ans = std::min(ans, min_w[x][int(log2(d[x] - d[y]))]);
        x = fa[x][int(log2(d[x] - d[y]))];
    }
    return ans;
}

void dp(int x) {
    f[x] = 0;
    for (auto nxt : tree[x]) {
        dp(nxt.to);
        if (flag[nxt.to]) f[x] += nxt.w;
        else f[x] += std::min(f[nxt.to], nxt.w);
    }
    tree[x].clear();    
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0x7fffffff, 0);
    int m;
    scanf("%d", &m);
    while (m--) {
        int k;
        scanf("%d", &k);
        for (int i = 1; i <= k; i++) {
            scanf("%lld", &a[i]);
            flag[a[i]] = true;
        }            
        std::sort(a + 1, a + k + 1, [](int x, int y){return dfn[x] < dfn[y];});
        std::vector<int> s;
        s.push_back(1);
        for (int i = 1; i <= k; i++) {
            int lca = get_lca(a[i], s.back());
            if (lca == s.back()) {
                s.push_back(a[i]);
            } else {
                while (dfn[lca] < dfn[s.back()] && dfn[lca] < dfn[s[s.size() - 2]]) {
                    tree[s[s.size() - 2]].push_back({s.back(), get_min(s.back(), s[s.size() - 2])});
                    s.pop_back();
                }
                if (dfn[lca] > dfn[s[s.size() - 2]]) { 
                    tree[lca].push_back({s.back(), get_min(lca, s.back())});
                    s.pop_back();
                    s.push_back(lca);
                    s.push_back(a[i]);
                } else {
                    tree[lca].push_back({s.back(), get_min(lca, s.back())});
                    s.pop_back();
                    s.push_back(a[i]);
                }
            }
        }
        while (s.size() > 1) {
            tree[s[s.size() - 2]].push_back({s.back(), get_min(s.back(), s[s.size() - 2])});
            s.pop_back();
        }
        dp(1);
        printf("%lld\n", f[1]);
        for (int i = 1; i <= k; i++)
            flag[a[i]] = false;
    }
}