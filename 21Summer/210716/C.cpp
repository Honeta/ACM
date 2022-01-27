#include <iostream>
#include <algorithm>
#include <vector>
#define INF -1000000000
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::vector<int> w[2],v[2],sum[2];        
        std::vector<long long> ans1, ans2;
        long long ans = 0;
        std::cin >> n >> m;
        w[0].resize(n + 1);
        v[0].resize(n + 1);
        sum[0].resize(n + 1);
        w[1].resize(m + 1);
        v[1].resize(m + 1);
        sum[1].resize(m + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> w[0][i] >> v[0][i];
            sum[0][i] = sum[0][i-1] + w[0][i];
        }            
        for (int i = 1; i <= m; i++) {
            std::cin >> w[1][i] >> v[1][i];
            sum[1][i] = sum[1][i-1] + w[1][i];
        }
        ans1.resize(sum[0][n] + 1);
        ans2.resize(sum[1][m] + 1);  
        std::fill(ans1.begin() + 1, ans1.end(), INF); 
        std::fill(ans2.begin() + 1, ans2.end(), INF); 
        for (int i = 1; i <= n; i++)
            for (int j = sum[0][i]; j >= w[0][i]; j--)
                if (ans1[j - w[0][i]] != INF)
                    ans1[j] = std::max(ans1[j], ans1[j - w[0][i]] + v[0][i]);    
        for (int i = 1; i <= m; i++)
            for (int j = sum[1][i]; j >= w[1][i]; j--)
                if (ans2[j - w[1][i]] != INF)
                    ans2[j] = std::max(ans2[j], ans2[j - w[1][i]] + v[1][i]);           
        for (int i = 0; i <= std::min(sum[0][n], sum[1][m]); i++)
            if (ans1[i] != INF && ans2[i] != INF)
                ans = std::max(ans, ans1[i] + ans2[i]);
        std::cout << ans << std::endl;
    }
    return 0;
}