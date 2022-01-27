#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<array>
#include<bitset>
#include<queue>
const int N=1e4+1;
std::vector<int> g[N],v[N],T;
std::stack<int> s;
std::array<int,N> dfn,low,team,sum,indeg;
std::queue<int> q;
std::bitset<N> b[N];
int n,m,ans,DFN,TEAM;
void tarjan(int x)
{
    dfn[x]=low[x]=++DFN;
    s.push(x);
    for(int to:g[x])
    {
        if(!dfn[to])
        {
            tarjan(to);
            low[x]=std::min(low[x],low[to]);
        }
        else if(!team[to])
            low[x]=std::min(low[x],dfn[to]);
    }        
    if(low[x]==dfn[x])
    {
        team[x]=++TEAM;
        ++sum[TEAM];
        while(s.top()!=x)
        {
            int temp=s.top();
            s.pop();
            team[temp]=TEAM;
            ++sum[TEAM];
        }
        s.pop();
    }
}
void scc()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        for(int to:g[i])
            if(team[i]!=team[to])
            {
                v[team[i]].push_back(team[to]);
                ++indeg[team[to]];
            }
}
void topo()
{
    for(int i=1;i<=TEAM;i++)
        if(!indeg[i])
            q.push(i);
    while(q.size())
    {
        int now=q.front();
        q.pop();
        T.push_back(now);
        for(int to:v[now])
            if(!(--indeg[to]))
                q.push(to);
    }
}
void debug()
{
    std::cout<<"indeg:";
    for(int i=1;i<=TEAM;i++)
        std::cout<<indeg[i]<<' ';
    std::cout<<std::endl;
}
int main()
{
    int _u,_v;
    std::cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        std::cin>>_u>>_v;
        g[_u].push_back(_v);
    }
    scc();
    topo();
    for(auto it=T.rbegin();it!=T.rend();++it)
    {
        b[*it].set(*it);
        if(v[*it].size())
            for(int to:v[*it])
                b[*it]|=b[to];
    }
    for(auto it=T.begin();it!=T.end();++it)
        if(v[*it].size())
            for(int to:v[*it])
                b[to]|=b[*it];
    for(int i=1;i<=TEAM;i++)
        for(int j=1;j<=TEAM;j++)
            ans+=b[i][j]*sum[i]*sum[j];
    std::cout<<ans;
    return 0;
}