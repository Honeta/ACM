#include <cstdio>
#include <algorithm>

const int N = 1e5, M = 1e5, BLOCK = 316;

struct query {
    int i, l, r;
    bool operator<(query x) {
        return (l - 1)/BLOCK != (x.l - 1)/BLOCK ? (l - 1)/BLOCK < (x.l - 1)/BLOCK : r < x.r;
    }
} q[M + 1];

int a[N + 1], b[N + 1], cnt[N + 1], cntr[N + 1];
long long ans_r, ans_all, ans[M + 1];
int cnt_delta[N + 1], cntr_delta[N + 1], cnt_delta_cnt, cntr_delta_cnt;

void add(int i, int flag) {    
    if (flag == 1) {
        if (!cnt[a[i]]) cnt_delta[++cnt_delta_cnt] = a[i];
        if (!cntr[a[i]]) cntr_delta[++cntr_delta_cnt] = a[i];
        ++cnt[a[i]];
        ++cntr[a[i]];
        ans_r = std::max(ans_r, 1LL * b[a[i]] * cnt[a[i]]);
    } else {
        if (!cnt[a[i]])
            cnt_delta[++cnt_delta_cnt] = a[i];
        ++cnt[a[i]];
        ans_all = std::max(ans_all, 1LL * b[a[i]] * cnt[a[i]]);
    }    
}

void calc(int l, int r) {
    int cnt[N + 1];
    for (int i = l; i <= r; ++i)
        cnt[a[i]] = 0;
    for (int i = l; i <= r; i++) {
        ++cnt[a[i]];
        ans_all = std::max(ans_all, 1LL * b[a[i]] * cnt[a[i]]);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    int n_unique = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + n_unique + 1, a[i]) - b;
    for (int i = 1; i <= m; i++) {
        q[i].i = i;
        scanf("%d%d", &q[i].l, &q[i].r);
    }        
    std::sort(q + 1, q + m + 1);
    int l, r;
    bool flag = true;
    for (int i = 1; i <= m; i++) {
        if ((q[i].l - 1) / BLOCK == (q[i].r - 1) / BLOCK) {
            ans_all = 0;
            calc(q[i].l, q[i].r);
            flag = true;
        } else {            
            l = ((q[i].l - 1) / BLOCK + 1) * BLOCK + 1;
            if (flag || (q[i].l - 1) / BLOCK != (q[i - 1].l - 1) / BLOCK) {
                for (int j = 1; j <= cntr_delta_cnt; ++j)
                    cntr[cntr_delta[j]] = 0;
                for (int j = 1; j <= cnt_delta_cnt; ++j)
                    cnt[cnt_delta[j]] = 0;
                r = l - 1;
                ans_r = cntr_delta_cnt = cnt_delta_cnt= 0;
            }
            flag = false;
            for (int j = 1; j <= cnt_delta_cnt; ++j)
                cnt[cnt_delta[j]] = cntr[cnt_delta[j]];
            cnt_delta_cnt = cntr_delta_cnt;
            while (r < q[i].r) add(++r, 1); 
            ans_all = ans_r;          
            while (l > q[i].l) add(--l, -1);
        }
        ans[q[i].i] = ans_all;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);        
}