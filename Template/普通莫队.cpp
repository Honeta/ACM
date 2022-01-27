#include <cstdio>
#include <algorithm>

const int N = 5e4, M = 5e4, K = 5e4, BLOCK = 223;

struct query {
    int i, l, r;
    bool operator<(query x) {
        return (l - 1)/BLOCK != (x.l - 1)/BLOCK ? (l - 1)/BLOCK < (x.l - 1)/BLOCK : r < x.r;
    }
} q[M + 1];

int a[N + 1], cnt[K + 1];
long long ans_tmp, ans[M + 1];

void move(int i, int sign) {
    ans_tmp -= cnt[a[i]] * cnt[a[i]];
    cnt[a[i]] += sign;
    ans_tmp += cnt[a[i]] * cnt[a[i]];
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        q[i].i = i;
        scanf("%d%d", &q[i].l, &q[i].r);
    }        
    std::sort(q + 1, q + m + 1);
    int l = q[1].l, r = q[1].r;
    for (int i = l; i <= r; i++) move(i, 1);
    ans[q[1].i] = ans_tmp;
    for (int i = 2; i <= m; i++) {
        while (l < q[i].l) move(l++, -1);
        while (l > q[i].l) move(--l, 1);
        while (r > q[i].r) move(r--, -1);
        while (r < q[i].r) move(++r, 1);
        ans[q[i].i] = ans_tmp;
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
}