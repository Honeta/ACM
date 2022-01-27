#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int n, m;
int fa[MAXN], c1[MAXN], c2[MAXN];
int u[MAXN], v[MAXN], w[MAXN];
bool vis[MAXN];

int s[MAXN];
int ans = 1e8;

int sum() {
    int ret = 0;
    for(int i = 1; i <= n; i++) ret += s[i];
    return ret;
}
bool check() {
    for(int i = 1 ; i <= m; i++) {
        int x = u[i];
        int y = v[i];
        if((s[x]^s[y]) != w[i])return 0;
    }
    return 1;
}

void dfs(int dep) {
    if(dep == n + 1) {
        if(check()) {
            ans = min(ans, sum());
            if(sum() == 11) {
                for(int i = 1; i <= n; i++)
                printf("%d ",s[i]); 
                puts("");
            }
        }
    } else {
        for (int i = 0; i < 8; i++) {
            s[dep] = i;
            dfs(dep + 1);
        }            
    }
}

int main() {
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    dfs(1);
    if(ans == 1e8) puts("-1");
    else printf("%d\n", ans);
}