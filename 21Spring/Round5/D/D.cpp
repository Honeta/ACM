#include <iostream>
#include <vector>
#include <algorithm>
void dp(int now, int fa, int n, std::vector<std::vector<int>> &g, std::vector<std::vector<int>> &f)
{
    if(fa != 0 && g[now].size() == 1)
    {
        for(int i = 1; i < n; i++)
            f[now][i + n - 1] = i;
        return;
    }        
    std::vector<int> sigma_backward(n - 1), delta_max(n - 1);
    int sigma_forward = 0;
    for(auto it = g[now].begin(); it != g[now].end(); ++it)
    {
        int to = *it;
        if(to == fa)
            continue;
        dp(to, now, n, g, f);
        for(int i = -n + 2; i < 0; i++)
            f[now][i + n - 1] += f[to][i - 1 + n - 1];
        f[now][-n + 1 + n - 1] += f[to][0 + n - 1];
        for(int i = 0; i < n; i++)
        {
            sigma_forward += f[to][0 + n - 1];
            sigma_backward[i] += f[to][-i + n - 1];
            delta_max[i] = std::max(delta_max[i], f[to][i + 1 + n - 1] - f[to][0 + n - 1]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        f[now][i + n - 1] = sigma_forward - delta_max[i];
        if(i > 0)
            f[now][i + n - 1] = std::min(f[now][i + n - 1], sigma_backward[i] + i);
    }
    for(int i = n - 2; i > -n; i--)
        f[now][i + n - 1] = std::min(f[now][i + n - 1], f[now][i + 1 + n - 1]);
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1), f(n + 1, std::vector<int>(n * 2 - 1));
    for(int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp(1, 0, n, g, f);
    std::cout << f[1][0 + n - 1];
    return 0;
}