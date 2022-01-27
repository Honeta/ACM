#include <iostream>
#include <vector>
#include <queue>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> v[n + 1], ru(n + 1), sum(n + 1);
        std::queue<int> q;
        for (int i = 1; i <= n; i++) {
            int k;
            std::cin >> k;
            while (k--) {
                int temp;
                std::cin >> temp;
                v[temp].push_back(i);
                ru[i]++;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!ru[i]) {
                sum[i] = 1;
                q.push(i);
            }                
        int cnt = 0;
        while (q.size()) {
            int now = q.front();
            q.pop();
            ++cnt;
            for (auto x : v[now]) {
                ru[x]--; 
                if (x < now) sum[x] = std::max(sum[x], sum[now] + 1);
                else sum[x] = std::max(sum[x], sum[now]);               
                if (!ru[x]) q.push(x);
            }
        }
        if (cnt < n) {
            std::cout << -1 << std::endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = std::max(ans, sum[i]);
        std::cout << ans << std::endl;
    }
    return 0;
}