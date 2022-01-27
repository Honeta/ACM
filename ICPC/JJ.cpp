#include <bits/stdc++.h>
using namespace std;
int a[4];
bool check() {
    return a[0] % 10 == 0 && a[1] % 10 == 0 && a[2] % 10 == 0 && a[3] % 10 == 0;
}

struct node {
    int st[4];
    node() = default;
    node(int a,int b, int c, int d) {
        st[0] = a;
        st[1] = b;
        st[2] = c;
        st[3] = d;
    }
    bool operator == (const node &B) const{
        for(int i = 0; i < 4; i++) {
            if(st[i] != B.st[i])return 0;
        }
        return 1;
    }
};
int vis[10][10][10][10];
int bfs(node delta) {
    memset(vis, -1, sizeof(vis));
    queue<node>q;
    q.push(delta);
    vis[delta.st[0]][delta.st[1]][delta.st[2]][delta.st[3]] = 0;
    while(!q.empty()) {
        node u = q.front();
        if(u == node(0,0,0,0)) {
            return vis[u.st[0]][u.st[1]][u.st[2]][u.st[3]];
        }
        q.pop();
        for(int i = 0; i < 4; i ++) {
            for(int j = i; j < 4; j++) {
                node v;
                v = u;
                for(int k = i; k <= j; k++) {
                    v.st[k] = u.st[k]+1;
                    if(v.st[k] >= 10) v.st[k] -= 10;
                }
                if(vis[v.st[0]][v.st[1]][v.st[2]][v.st[3]] == -1) {
                    vis[v.st[0]][v.st[1]][v.st[2]][v.st[3]] = vis[u.st[0]][u.st[1]][u.st[2]][u.st[3]] + 1;
                    q.push(v);
                }
                for(int k = i; k <= j; k++) {
                    v.st[k] = u.st[k]-1;
                    if(v.st[k] < 0) v.st[k] += 10;
                }
                if(vis[v.st[0]][v.st[1]][v.st[2]][v.st[3]] == -1) {
                    vis[v.st[0]][v.st[1]][v.st[2]][v.st[3]] = vis[u.st[0]][u.st[1]][u.st[2]][u.st[3]] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    freopen("jj.txt","w",stdout);
    printf("a[10][10][10][10]={");
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++) {
                    if(i==9 && j==9 && k==9 && l==9)
                    printf("%d};\n",bfs(node(i,j,k,l)));
                    else printf("%d,",bfs(node(i,j,k,l)));
                    //cout  << bfs(node(i,j,k,l)) << endl;                     
                }
                    
                        

}