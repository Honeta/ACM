#include <cstdio>
#include <algorithm>

const int N = 2e5, Log4N = 20;

struct node {
    int val, lchild, rchild;
} tree[4 * N + N * Log4N];

struct item {
    int pos, val;
} a[N + 1];

int root[N + 1], val_unique[N + 1], tot, cnt_unique;

int build(int l, int r) {
    int now = ++tot;
    if (l == r) {
        tree[now].val = 0;
        return now;
    }
    int mid = l + r >> 1;
    tree[now].lchild = build(l, mid);
    tree[now].rchild = build(mid + 1, r);
    return now;
}

int update(int x, int l, int r, int target) {
    int now = ++tot;
    tree[now] = tree[x];
    if (l <= target && target <= r) {
        tree[now].val++;
        if (l == r)
            return now;
    }
    int mid = l + r >> 1;
    if (target <= mid)
        tree[now].lchild = update(tree[x].lchild, l, mid, target);
    else
        tree[now].rchild = update(tree[x].rchild, mid + 1, r, target);
    return now;
}

int query(int x, int l, int r, int st, int ed) {
    if (st <= l && r <= ed) return tree[x].val;
    int ans = 0, mid = l + r >> 1;
    if (mid >= st) ans += query(tree[x].lchild, l, mid, st, ed);
    if (mid + 1 <= ed) ans += query(tree[x].rchild, mid + 1, r, st, ed);
    return ans;
}

int main() { 
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i].pos = i;
        scanf("%d", &a[i].val);
    }       
    root[0] = build(1, n);
    std::sort(a + 1, a + n + 1, [](item x, item y){return x.val < y.val;});
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].val != a[i - 1].val) {
            ++cnt_unique;
            val_unique[cnt_unique] = a[i].val;
            root[cnt_unique] = update(root[cnt_unique - 1], 1, n, a[i].pos);
        } else {
            root[cnt_unique] = update(root[cnt_unique], 1, n, a[i].pos);
        }
    }        
    for (int i = 1; i <= m; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int st = 1, ed = cnt_unique + 1, ans = 0x7fffffff;        
        while (st < ed) {
            int mid = st + ed >> 1;
            int result = query(root[mid], 1, n, l, r);
            if (result >= k) {
                ans = std::min(ans, val_unique[mid]);
                ed = mid;
            } else {
                st = mid + 1;
            }
        }        
        printf("%d\n", ans);
    }
    auto x = -2147483648;
    return 0;
}