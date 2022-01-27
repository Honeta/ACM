#include <iostream>
#include <bitset>
#define INF 0x7fffffff
int d1[2001][2001], d2[2001][2001];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d1[i][j] = d2[i][j] = INF;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        d1[u][v] = d2[u][v] = w;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && d1[i][k] != INF && d1[k][j] != INF && d1[i][k] + d1[k][j] < d1[i][j])
                    d1[i][j] = d1[i][k] + d1[k][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (i != j && d2[i][k] != INF && d2[k][j] != INF && d2[i][k] + d2[k][j] < d2[i][j])
                    d2[i][j] = d2[i][k] + d2[k][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cout << "d1[" << i << "][" << j << "] = " << d1[i][j] << "; "
                      << "d2[" << i << "][" << j << "] = " << d2[i][j] << std::endl;
            if (d1[i][j] == d2[i][j])
                ++ans;
        }
    std::cout << ans;
    return 0;
}