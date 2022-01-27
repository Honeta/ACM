#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int n, m;
int fa[MAXN], c1[MAXN], c2[MAXN];
int u[MAXN], v[MAXN], w[MAXN];
bool vis[MAXN];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    int len = n * 2;
    long long ans = 0;
    for(int j = 0; j < 30; j++) {
        int mask = 1 << j;
        for(int i = 1; i <= len; i++) {
            fa[i] = i;
            if(i <= n) {
                c1[i] = 1;
                c2[i] = 0;
            } else {
                c1[i] = 0;
                c2[i] = 1;
            }
            vis[i] = 0;
        }

        for(int i = 1; i <= m; i++) {
            if(w[i] & mask) {
                int x = u[i];
                int y = v[i];
                int rx = u[i] + n;
                int ry = v[i] + n;

                if(find(x) == find(ry) || find(rx) == find(y)) continue;
                c1[fa[ry]] += c1[fa[x]];
                c2[fa[ry]] += c2[fa[x]];
                fa[fa[x]] = fa[ry];

                c1[fa[rx]] += c1[fa[y]];
                c2[fa[rx]] += c2[fa[y]];
                fa[fa[y]] = fa[rx];

                if(find(x) == find(rx) || find(y) == find(ry)) {
                    puts("-1");
                    return 0;
                }
            } else {
                int x = u[i];
                int y = v[i];
                int rx = u[i] + n;
                int ry = v[i] + n;

                
                if(find(x) == find(y) || find(rx) == find(ry)) continue;
                c1[fa[ry]] += c1[fa[rx]];
                c2[fa[ry]] += c2[fa[rx]];
                fa[fa[rx]] = fa[ry];

                c1[fa[x]] += c1[fa[y]];
                c2[fa[x]] += c2[fa[y]];
                fa[fa[y]] = fa[x];

                if(find(x) == find(rx) || find(y) == find(ry)) {
                    puts("-1");
                    return 0;
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= len; i++) {
            int f = find(i);
            if(c1[f] + c2[f] <= 1 || vis[f]) continue;
            vis[f] = 1;
            cnt += min(c1[f], c2[f]);
        }
        cnt = cnt >> 1;
        ans += 1ll * cnt * mask;
        //printf("%d ", cnt);
    }
    //puts("");
    printf("%lld\n", ans);
}
/*
6 6
1 3 5
5 3 3
2 6 2
4 2 1
3 2 0
2 4 1

6 6
1 4 2
6 5 0
2 5 1
3 5 3
5 3 3
2 4 3


*/