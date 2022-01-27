#include <iostream>
#include <algorithm>
#include <vector>
const int INF = -0x7fffffff;
int n, m, k, f[202][202], pre;
char c[202][202];
long long tot[202][202], sum[202][202], dp[202][202][2], dp_sum[202][202][2];
std::vector<int> n_list[202];
int main() {
    std::cin >> n >> m >> k;    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> f[i][j] >> c[i][j];
            dp_sum[j][i][0] = dp_sum[j][i][1] = INF;
        }
    for (int i = 1; i <= n; i++)
        dp_sum[0][i][0] = dp_sum[0][i][1] = INF;           
    for (int j = 1; j <= m; j++)
        for (int i = n; i >= 1; i--) {
            if (c[i][j] == 'N')
                break;
            pre += f[i][j];
        }
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++) {
            if (i == n)
                n_list[j].push_back(n + 1);
            sum[j][i] = sum[j][i + 1] + f[i][j];
            if (c[i][j] == 'N')
                n_list[j].push_back(i);
        }   
    for (int j = 1; j <= m; j++)
        for (auto it = n_list[j].begin() + 1; it != n_list[j].end(); ++it) {
            tot[j][*it] = tot[j][*(it - 1)] + 1;
            dp[j][*it][1] = dp[j][*(it - 1)][0] + f[*it][j];
            if (it + 1 != n_list[j].end())
                dp[j][*it][0] = dp[j][*it][1] + sum[j][*(it + 1) + 1] - sum[j][*it];
            else
                dp[j][*it][0] = dp[j][*it][1] + sum[j][1] - sum[j][*it];
        }
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= k; i++) {
            if (dp_sum[j - 1][i][0] >= 0) {
                dp_sum[j][i][1] = dp_sum[j - 1][i][1]; 
                dp_sum[j][i][0] = dp_sum[j - 1][i][0];
            }
            for (auto it = n_list[j].begin() + 1; it != n_list[j].end(); ++it) 
                if (i >= tot[j][*it] && dp_sum[j - 1][i - tot[j][*it]][0] >= 0) {
                    using std::max;
                    if (j > 1 && i > tot[j][*it])
                        dp_sum[j][i][1] = max(dp_sum[j][i][1], dp_sum[j - 1][i - tot[j][*it]][1] + dp[j][*it][0]);
                    dp_sum[j][i][1] = max(dp_sum[j][i][1], dp_sum[j - 1][i - tot[j][*it]][0] + dp[j][*it][1]);
                    dp_sum[j][i][0] = max(dp_sum[j][i][0], dp_sum[j - 1][i - tot[j][*it]][0] + dp[j][*it][0]);
                }
        }
    std::cout << dp_sum[m][k][1] + pre;  
    return 0;
}