#include <iostream>
#include <vector>
std::vector<std::vector<int>> g;
std::vector<int> ssize, a, w;
void dfs(int x) {
    ssize[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        dfs(g[x][i]);
        ssize[x] += ssize[g[x][i]];
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    g.resize(n + 1);
    ssize.resize(n + 1);
    a.resize(n + 1);
    w.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        int temp;
        std::cin >> temp;
        a[i] = temp;
    }
    for (int i = 1; i <= n; i++) {
        int temp;
        std::cin >> temp;
        w[i] = temp;
    }
    while (m--) {
        int temp;
        std::cin >> temp;
    }
    return 0;
}