#include <iostream>
#include <vector>
#include <algorithm>
struct node{int no, w;};
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int> > g(n + 1);
        std::vector<node> a;
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            int temp;
            std::cin >> temp;
            a.push_back({i, temp});
        }
        std::sort(a.begin(), a.end(), [](node x, node y){return x.w > y.w;});
    }
    return 0;
}