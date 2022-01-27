#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
struct good {int c, w, v;};
int a[201][201], f[201];
char b[201][201];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        memset(f, 0, sizeof(f));
        std::vector<good> v[201];
        int n, m, k;
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d %c", &a[i][j], &b[i][j]);
        for (int j = 1; j <= m; j++) {
            int sum_p = 0, sum_n = 0;
            for (int i = n; i >= 1; i--) {
                if (b[i][j] == 'Y') {
                    sum_p += a[i][j];
                } else {
                    v[j].push_back({sum_n + 1, sum_n, sum_p});
                    sum_n++;
                    sum_p += a[i][j];
                    v[j].push_back({sum_n, sum_n, sum_p});
                }                
            }     
            if (b[1][j] == 'Y')
                v[j].push_back({sum_n + 1, sum_n, sum_p});       
        }
        for (int i = 1; i <= m; i++)
            for (int j = k; j >= 0; j--)
                for (auto x : v[i])
                    if (j >= x.c)
                        f[j] = std::max(f[j], f[j - x.w] + x.v);
        std::cout << f[k] << std::endl;
    }    
    return 0;
}