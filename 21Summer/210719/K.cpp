#include <iostream>
#include <vector>
#include <queue>
std::vector<std::vector<int>> v;
int b[1000001], ru[1000001], ans[1000001];
std::queue<int> q;
int main() {
    int n, k;
    std::cin >> n >> k;
    int last1 = 0, last2 = 0;
    for (int i = 1; i <= k; i++) {
        int t1, t2;
        std::cin >> t1 >> t2; 
        b[t1] = t2;
    }
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            if (i == 1) continue;
            ru[i]++;
            v[i-1].push_back(i);            
        } else {
            ru[i]++;            
            v[b[i]].push_back(i);
            if (i == b[i]) continue;
            ru[b[i]]++;
            v[i].push_back(b[i] - 1);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!ru[i])
            q.push(i);
    int cnt = 0;
    while (q.size()) {
        int now = q.front();
        ans[now] = ++cnt;
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            ru[v[now][i]]--;
            if (!ru[v[now][i]])
                q.push(v[now][i]);
        }
    }
    if (cnt != n) {
        std::cout << -1;
        return 0;
     }
    for (int i = 1; i <= n; i++)
        std::cout << ans[i] << ' ';
    return 0;
}