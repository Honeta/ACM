#include<iostream>
#include<vector>
#define MOD 998244353
void dfs(int x,int fa,int root)
{
    
}
int main()
{
    int n,k;
    std::cin>>n>>k;
    std::vector<int> w,cntmax[5001],cntmin[5001];
    std::vector<std::vector<int>> g;
    w.resize(n+1);
    g.resize(n+1);
    for(int i=1;i<=n;i++)
        std::cin>>w[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return 0;
}