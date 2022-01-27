#include<iostream>
#include<vector>
std::vector<std::vector<int>> g,fruit;
int main()
{
    int t,n,m;
    std::cin>>n>>m;
    g.resize(n+1);
    fruit.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        fruit[i].resize(m);
        for(int j=0;j<m;j++)
        {
            int temp;
            std::cin>>temp;
            fruit[i][j]=temp;
        }
    }
        
    return 0;
}