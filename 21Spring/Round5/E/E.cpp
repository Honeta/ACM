#include<iostream>
#include<vector>
#include<algorithm>
int dfs(int x,int fa,int d,std::vector<std::vector<int>> &g)
{
    int maxd=0;
    if(g[x].empty())return d;
    for(int i=0;i<g[x].size();i++)
        if(g[x][i]!=fa)
            maxd=std::max(maxd,dfs(g[x][i],x,d+1,g));
    if(maxd-d==d-1)
    {
        std::cout<<maxd-d;
        exit(0);
    }
    if(maxd-d==d)
    {
        std::cout<<d-1;
        exit(0);
    }
    if(maxd-d+1==d-1)
    {
        std::cout<<maxd-d;
        exit(0);
    }
    return maxd;
}
int main()
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> g;
    g.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        std::cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,1,g);
    return 0;
}