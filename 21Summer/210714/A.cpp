#include <iostream>
#include <vector>
#define MOD 998244353
int main() {
    int n,m;
    double ans;
    std::vector<long long> v;
    long long deg[1000001],sum[1000001];
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int t1,t2;
        std::cin >> t1 >> t2;
        deg[t1]++;
        deg[t2]++;
    }
    for (int i = 1; i <= n; i++) {
        sum[deg[i]]++;
        if (sum[deg[i]] == 1)
            v.push_back(deg[i]);
    }
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size(); j++)
            if (i != j) {
                ans += (sum[v[i]] * sum[v[j]] / 2) * (v[i] ^ v[j]) * (v[i] + v[j]);
                while (ans >= MOD)
                    ans -= MOD;
            } else {

            }  
    return 0;
}