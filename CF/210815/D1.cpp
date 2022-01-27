#include <iostream>
#include <vector>
#include <utility>
int r1[1001], r2[1001];
int getfa1(int x) {return r1[x] == x ? r1[x] : getfa1(r1[x]);}
int getfa2(int x) {return r2[x] == x ? r2[x] : getfa2(r2[x]);}
void merge1(int x, int y) {r1[getfa1(x)] = getfa1(y);} 
void merge2(int x, int y) {r2[getfa2(x)] = getfa2(y);}
int main() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++)
        r1[i] = r2[i] = i;
    for (int i = 1; i <= m1; i++) {
        int u, v;
        std::cin >> u >> v;
        merge1(u, v);
    }
    for (int i = 1; i <= m2; i++) {
        int u, v;
        std::cin >> u >> v;
        merge2(u, v);
    }
    int cnt = 0;
    std::vector<std::pair<int, int>> v;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (getfa1(i) != getfa1(j) && getfa2(i) != getfa2(j)) {
                ++cnt;
                v.push_back({i, j});
                merge1(i, j);
                merge2(i, j);
            }
    std::cout << cnt << std::endl;
    for (auto x : v)
        std::cout << x.first << ' ' << x.second << std::endl;
    return 0;
}