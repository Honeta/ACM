#include <iostream>
#include <algorithm>
const long long MOD = 1e9 + 7;
long long dfs(int x, int fa, int n, int root)
{
    if(x > root && )
    long long sum = 0, min = 0x7fffffff;
    for(int i = 1; i < x; i++)
        (sum += dfs(i, x, n, root)) %= MOD;
    return sum;
}
int main()
{
    int n;
    long long a[2001];
    std::cin >> n;
    for(int i = 1; i <= n; i++)
        std::cin >> a[i];
    return 0;
}