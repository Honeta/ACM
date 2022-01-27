#include<bits/stdc++.h>
int cnt,n;
char s[100005];
void dfs(int x,int cnt0, int cnt1, int st) {
    if(cnt0>(n+2)/2 || cnt1>(n+2)/2) return;
    if(x==n)
    {
        printf("%s\n",s);
        if(++cnt>=100) exit(0);
        return;
    }
    s[x]='b';
    dfs(x+1,cnt0+(st^1),cnt1+st,st);
    st^=1;
    s[x]='r';
    dfs(x+1,cnt0+(st^1),cnt1+st,st);
}
int main() {
    scanf("%d", &n);
    if (n & 1)
        printf("%lld\n", 1LL * (n + 1) * (n + 1) / 4);
    else
        printf("%lld\n", 1LL * n * (n + 2) / 4);
    dfs(0,1,0,0);
}