#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int n = 4, m = 8;

int vis[10][10];

int get(int a, int b) {
    return rand()%b + a;

}

int main() {
    srand(time(NULL));
    m = get(4, 6);
    printf("%d %d\n", n, m);
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= m; i++) {
        int x = get(1,n);
        int y = get(1,n);
        int w = get(0,7);
        while(vis[x][y] || x==y) {
            x = get(1,n);
            y = get(1,n);
        }
        vis[x][y] = 1;
        printf("%d %d %d\n", x, y, w);
    }
    
}