#include <cstdio>

const int N = 1e6, M = 1e6, Log4N = 22;

struct node {
    int val, lchild, rchild;
} tree[4 * N + M * Log4N];

int a[N + 1], root[M + 1], tot;

int build(int l, int r) {
    int now = ++tot;
    if (l == r) {
        tree[now].val = a[l];
        return now;
    }
    int mid = l + r >> 1;
    tree[now].lchild = build(l, mid);
    tree[now].rchild = build(mid + 1, r);
    return now;
}

int update(int x, int l, int r, int target, int val) {
    int now = ++tot;
    tree[now] = tree[x];
    if (l == r) {
        tree[now].val = val;
        return now;
    }
    int mid = l + r >> 1;
    if (target <= mid)
        tree[now].lchild = update(tree[x].lchild, l, mid, target, val);
    else
        tree[now].rchild = update(tree[x].rchild, mid + 1, r, target, val);
    return now;
}

int query(int x, int l, int r, int target) {
    if (l == r) return tree[x].val;
    int mid = l + r >> 1;
    if (target <= mid)
        return query(tree[x].lchild, l, mid, target);
    else
        return query(tree[x].rchild, mid + 1, r, target);
}

int main() { 
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    root[0] = build(1, n);
    for (int i = 1; i <= m; i++) {
        int ver, op, target, val;
        scanf("%d%d%d", &ver, &op, &target);
        if (op == 1) {
            scanf("%d", &val);
            root[i] = update(root[ver], 1, n, target, val); 
        } else {
            root[i] = ++tot;
            tree[root[i]] = tree[root[ver]];
            printf("%d\n", query(root[i], 1, n, target));
        }        
    }
    return 0;
}