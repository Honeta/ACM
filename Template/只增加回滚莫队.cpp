#include <cstdio>
#include <algorithm>

const int N = 2e5, M = 2e5, BLOCK = 447;

struct query {
    int i, l, r;
    bool operator<(query x) {
        return (l - 1)/BLOCK != (x.l - 1)/BLOCK ? (l - 1)/BLOCK < (x.l - 1)/BLOCK : r < x.r;
    }
} q[M + 1];

int a[N + 1], b[N + 1], left[N + 1], right[N + 1], rightr[N + 1], ans_r, ans_all, ans[M + 1];
int left_delta[N + 1], right_delta[N + 1], rightr_delta[N + 1], left_delta_cnt, right_delta_cnt, rightr_delta_cnt;

void add(int i, int flag) {    
    if (flag == 1) {
        if (!left[a[i]]) {
            left[a[i]] = i;
            left_delta[++left_delta_cnt] = a[i];
        }
        if (!right[a[i]]) right_delta[++right_delta_cnt] = a[i];
        if (!rightr[a[i]]) rightr_delta[++rightr_delta_cnt] = a[i];
        right[a[i]] = rightr[a[i]] = i;
        ans_r = std::max(ans_r, right[a[i]] - left[a[i]]);  
    } else {
        if (!right[a[i]]) {
            right[a[i]] = i;
            right_delta[++right_delta_cnt] = a[i];
        }
        ans_all = std::max(ans_all, right[a[i]] - i);
    }    
}

void calc(int l, int r) {
    int first[N + 1];
    for (int i = l; i <= r; ++i)
        first[a[i]] = 0;
    for (int i = l; i <= r; i++) {
        if (!first[a[i]]) first[a[i]] = i;
        else ans_all = std::max(ans_all, i - first[a[i]]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    int n_unique = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + n_unique + 1, a[i]) - b;    
    scanf("%d", &m);
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
                for (int j = 1; j <= left_delta_cnt; ++j)
                    left[left_delta[j]] = 0;
                for (int j = 1; j <= rightr_delta_cnt; ++j)
                    rightr[rightr_delta[j]] = 0;
                for (int j = 1; j <= right_delta_cnt; ++j)
                    right[right_delta[j]] = 0;
                r = l - 1;
                ans_r = left_delta_cnt = rightr_delta_cnt = right_delta_cnt= 0;
            }
            flag = false;
            for (int j = 1; j <= right_delta_cnt; ++j)
                right[right_delta[j]] = 0;
            for (int j = 1; j <= rightr_delta_cnt; ++j)
                right[rightr_delta[j]] = rightr[rightr_delta[j]];
            right_delta_cnt = rightr_delta_cnt;
            while (r < q[i].r) add(++r, 1); 
            ans_all = ans_r;          
            while (l > q[i].l) add(--l, -1);
        }
        ans[q[i].i] = ans_all;
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);        
}