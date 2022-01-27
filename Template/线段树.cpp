#include <cstdio>

const int N = 2e5;

struct node {
    long long val, add_tag;
} tree[N << 2];

long long a[N + 1];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].val = a[l]; 
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    tree[i].val = tree[i << 1].val + tree[i << 1 | 1].val;
}

void push_down(int i, int l, int r) {
    int mid = l + r >> 1;    
    tree[i << 1].add_tag += tree[i].add_tag;
    tree[i << 1].val += tree[i].add_tag * (mid - l + 1);
    tree[i << 1 | 1].add_tag += tree[i].add_tag;
    tree[i << 1 | 1].val += tree[i].add_tag * (r - (mid + 1) + 1);
    tree[i].add_tag = 0;
}

long long get_sum(int i, int l, int r, int st, int ed) {    
    if (st <= l && r <= ed) return tree[i].val;
    push_down(i, l, r);
    long long sum = 0;
    int mid = l + r >> 1;
    if (st <= mid) sum += get_sum(i << 1, l, mid, st, ed);
    if (mid + 1 <= ed) sum += get_sum(i << 1 | 1, mid + 1, r, st, ed);
    tree[i].val = tree[i << 1].val + tree[i << 1 | 1].val;
    return sum;
}

void add(int i, int l, int r, int st, int ed, int k) {
    if (st <= l && r <= ed) {
        tree[i].add_tag += k;
        tree[i].val += k * (r - l + 1);
        return;
    }
    push_down(i, l, r);
    int mid = l + r >> 1;
    if (st <= mid)
        add(i << 1, l, mid, st, ed, k);
    if (mid + 1 <= ed)
        add(i << 1 | 1, mid + 1, r, st, ed, k);
    tree[i].val = tree[i << 1].val + tree[i << 1 | 1].val;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, x, y, k;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            scanf("%d", &k);
            add(1, 1, n, x, y, k);
        } else {
            printf("%lld\n", get_sum(1, 1, n, x, y));
        }
    }
}