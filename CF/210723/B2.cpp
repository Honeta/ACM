#include <string>
#include <vector>
#include <iostream>
#include <map>
int main() {
    int t;
    std::cin >> t;
    while (t--) {                
        int n, k;
        std::cin >> n >> k;
        std::vector<int> m(n + 1), cnt(k + 1), v;
        std::vector<std::map<int, int>> vis(n + 1);
        int ans = 0, tot = 0;
        for (int i = 1; i <= n; i++) {
            int temp;
            std::cin >> temp;
            v.push_back(temp);
            m[temp]++;
            if (m[temp] <= k) ans++;
        }
        ans -= ans % k;
        for (int i = 0; i < v.size(); i++) {
            if (tot == ans) {
                std::cout << 0 << ' ';
                continue;
            }
            for (int j = 1; j <= k; j++) {
                if (!vis[v[i]][j] && cnt[j] < ans / k) {
                    vis[v[i]][j] = 1;
                    cnt[j]++;
                    tot++;
                    std::cout << j << ' ';
                    break;
                }
                if (j == k) std::cout << 0 << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}