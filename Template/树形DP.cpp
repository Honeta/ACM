#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int N = 5000;

int n, f[N + 1][N << 1 | 1];
std::vector<int> g[N + 1];

void dp(int now, int fa) {    
    for (auto x : g[now])        
        if (x != fa)
            dp(x, now);            
    for (int k = -n + 1; k <= 0; k++) {
        int sum = 0;
        for (auto x : g[now])        
            if (x != fa)
                sum += f[x][-k + n];  
        for (auto x : g[now])        
            if (x != fa)
                f[now][k + n] = std::min(f[now][k + n], sum - f[x][-k + n] + f[x][k - 1 + n]);
    }        
    for (int k = 1; k <= n; k++) {
        int sum = 0;
        for (auto x : g[now])   
            if (x != fa)
                sum += f[x][k - 1 + n];
        f[now][k + n] = std::min(f[now][k + n], sum);  
    }
    for (int k = -n; k <= -1; k++) {
        int sum = 0;
        for (auto x : g[now])
            if (x != fa)
                sum += f[x][-k + n];
        f[now][k + n] = std::min(f[now][k + n], sum - k);
    }
    for (int k = -n + 1; k <= n; k++)
        f[now][k + n] = std::min(f[now][k + n], f[now][k - 1 + n]);           
}

int main() {
    memset(f, 0x3f, sizeof(f));
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp(1, 0);
    std::cout << f[1][0 + n];
    return 0;
}