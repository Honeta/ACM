#include <iostream>
#include <stack>
#include <utility>
int n, c[1001];
std::stack<std::pair<int, int>> s;
long long f[1001], ans;
int main() {    
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        if (i & 1) {
            s.push({i, c[i]});
        } else {
            while (s.size() && c[i]) {
                if (s.top().second > c[i]) {
                    f[i] += 1;
                    ans += c[i];
                    s.top().second -= c[i];
                    c[i] = 0;
                } else if (s.top().second == c[i]) {
                    f[i] = f[s.top().first - 1] + 1;
                    ans += f[s.top().first - 1] + 1 + s.top().second;
                    c[i] -= s.top().second;
                    s.pop();
                } else {
                    ans += f[s.top().first - 1] + s.top().second;
                    c[i] -= s.top().second;
                    s.pop();
                }
            }
            if (c[i] && s.empty()) f[i] = 0; 
        }        
    }
    std::cout << ans << std::endl;
    return 0;
}