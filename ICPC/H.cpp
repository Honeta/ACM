#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int n ,m;
int u[MAXN], v[MAXN], w[MAXN];

struct edge{
    int u, v, w, id;
}e[MAXN];
int dfn[MAXN], low[MAXN], sizze[MAXN];
vector<int>to[MAXN], ee;
int cnt;
int father[MAXN];
bool brd[MAXN];

void tarjan(int u, int fa) {
    sizze[u] = 1;
    father[u] = fa;
    low[u] = dfn[u] = ++ cnt;
    for(auto v:to[u]) {
        if(!dfn[v]) {
            tarjan(v,u);
            sizze[u] += sizze[v];
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                brd[v] = 1;
            }
        } else if(dfn[v] < dfn[u] && v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main () {
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        e[i].id=i;
        to[e[i].u].emplace_back(e[i].v);
        to[e[i].v].emplace_back(e[i].u);
        
    }
    sort(e + 1, e + m + 1, [](edge x, edge y){return x.w < y.w;});
    for (int i = 1 ;i <= m; i++) 
        if (brd[e[i].v] && sizze[e[i].v] % 2 == 1) {
            printf("")
        }

}