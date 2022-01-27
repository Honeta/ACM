#include <cstdio>
#include <algorithm>
#include <cmath>
char s[200001];
size_t v[200001][26], last[26], nxt[200001][20];
int main() {
    int m, n, q;
    scanf("%d%d", &m, &n);
    scanf("%s", s + 1);
    for (int i = 0; i < 26; i++)
        last[i] = n + 1;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < m; j++) 
            nxt[i][0] = std::max(last[j], nxt[i][0]);
        last[s[i] - 'a'] = i;
    }
    nxt[n + 1][0] = n + 1;
    for (int j = 1; j <= 19; j++)     
        for (int i = 0; i <= n + 1; i++)      
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    scanf("%d", &q);        
    while (q--) {
        int l, r, ans = 0;
        scanf("%d%d", &l, &r);
        --l;
        while (l <= r) {
            int i;
            for (i = 19; i > 0 && nxt[l][i] > r; --i);
            l = nxt[l][i];
            ans += (1 << i);
        }
        printf("%d\n", ans);
    }
    return 0;
}