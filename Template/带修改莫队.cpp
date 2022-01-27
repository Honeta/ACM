#include <cstdio>
#include <algorithm>

const int N = 133333, M = 133333, K = 1e6, BLOCK = 2609;

struct query {
    int i, l, r, t;
    bool operator<(query x) {
        return (l - 1)/BLOCK != (x.l - 1)/BLOCK ? (l - 1)/BLOCK < (x.l - 1)/BLOCK : ((r - 1)/BLOCK != (x.r - 1)/BLOCK ? (r - 1)/BLOCK < (x.r - 1)/BLOCK : i < x.i);
    }
} q[M + 1];
struct edit {
    int pos, from, to;
} e[M + 1];

int a[N + 1], b[N + 1], cnt[K + 1], ans_tmp, ans[M + 1], cnt_query;

void move(int i, int sign) {
    cnt[a[i]] += sign;
    if (sign == 1 && cnt[a[i]] == 1) ++ans_tmp;
    if (sign == -1 && cnt[a[i]] == 0) --ans_tmp;
}

void edit(int i, int sign, bool flag) {
    if (sign == 1) {
        if (flag) {
            if (cnt[e[i].to] == 0) ++ans_tmp;
            if (cnt[e[i].from] == 1) --ans_tmp;
            ++cnt[e[i].to];
            --cnt[e[i].from];
        }      
        a[e[i].pos] = e[i].to;
    } else {
        if (flag) {
            if (cnt[e[i].from] == 0) ++ans_tmp;
            if (cnt[e[i].to] == 1) --ans_tmp;
            ++cnt[e[i].from];
            --cnt[e[i].to];
        }     
        a[e[i].pos] = e[i].from;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }        
    for (int i = 1; i <= m; i++) {
        char op;
        do {
            scanf("%c", &op);
        } while (op != 'Q' && op != 'R');        
        if (op == 'Q') {
            q[++cnt_query].t = i;
            q[cnt_query].i = cnt_query;
            scanf("%d%d", &q[cnt_query].l, &q[cnt_query].r);
        } else {
            scanf("%d%d", &e[i].pos, &e[i].to);
            e[i].from = b[e[i].pos];
            b[e[i].pos] = e[i].to;
        }
    }        
    std::sort(q + 1, q + cnt_query + 1);
    int l = q[1].l, r = q[1].r, t = 0;
    while (t < q[1].t)
        if (e[++t].pos)
            edit(t, 1, false);
    for (int i = l; i <= r; i++) move(i, 1);    
    ans[q[1].i] = ans_tmp;
    for (int i = 2; i <= cnt_query; i++) {             
        while (l < q[i].l) move(l++, -1);
        while (l > q[i].l) move(--l, 1);
        while (r > q[i].r) move(r--, -1);
        while (r < q[i].r) move(++r, 1);
        while (t < q[i].t)
            if (e[++t].pos)
                edit(t, 1, l <= e[t].pos && e[t].pos <= r);
        while (t > q[i].t) {
            if (e[t].pos)
                edit(t, -1, l <= e[t].pos && e[t].pos <= r);
            --t;
        }                            
        ans[q[i].i] = ans_tmp;
    }
    for (int i = 1; i <= cnt_query; i++)
        printf("%d\n", ans[i]);
}