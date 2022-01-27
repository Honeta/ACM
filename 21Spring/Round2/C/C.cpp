#include<iostream>
#include<vector>
#include<queue>
#include<array>
const int N=1e5+1;
std::vector<int> g[N];
std::queue<int> q;
std::array<int,N> d;
std::array<bool,N> vis;
int main()
{
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    q.push(1);
    while(q.size())
    {
        int now=q.front();
        q.pop();
        if(now==n)break;
        for(auto it=g[now].begin();it!=g[now].end();++it)
            if(!vis[*it])
            {
                vis[*it]=1;
                d[*it]=d[now]+1;
                q.push(*it);
            }
    }
    std::cout<<d[n]-1;
    return 0;
}