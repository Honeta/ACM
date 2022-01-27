#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
char str[MAXN];
int a[MAXN];
int n;
int len[30];
int prem[30];
int last[MAXN][30];
int main() {
    scanf("%s",str+1);
    n = strlen(str+1);
    int mx = -1;
    for(int i = 1; i <=n; i++) {
        a[i] = str[i] - 'a';
        mx = max(a[i], mx);
    }
    for(int i = 1; i <= n; i++) {
        
        last[i][a[i]] = i; 
        

        for(int j = mx; j >= 0)
    }
}