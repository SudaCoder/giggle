//137(HDU-1166)
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;


int a[N], T, n;
struct segtree {
    int l, r;
    int val;
    int lazy;
}tree[N << 2];

void pushup(int rt) {
    //do sth.
    tree[rt].val = tree[rt << 1].val + tree[rt << 1 | 1].val;
}

void pushdown(int rt) {
    //do sth.
}

void build(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    //tree[rt].lazy = 0;
    if (l == r) {
        tree[rt].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

int query(int rt, int ql, int qr) {
    if (ql == tree[rt].l && qr == tree[rt].r)
        return tree[rt].val;
    int mid = tree[rt].l + tree[rt].r >> 1;
    pushdown(rt);
    if (qr <= mid)
        return query(rt << 1, ql, qr);
    else if (ql > mid)
        return query(rt << 1 | 1, ql, qr);
    else
        return query(rt << 1, ql, mid) + query(rt << 1 | 1, mid + 1, qr); //
}

void update(int rt, int pos, int val) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].val += val;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    pushdown(rt);
    if (pos <= mid)
        update(rt << 1, pos, val);
    else
        update(rt << 1 | 1, pos, val);
    pushup(rt);
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        printf("Case %d:\n", cas);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        build(1, 1, n);
        char com[10];
        int l, r;
        while (1) {
            scanf("%s", com);
            if (com[0] == 'E') break;
            scanf("%d%d", &l, &r);
            if (com[0] == 'A') {
                update(1, l, r);
            }
            else if (com[0] == 'S') {
                update(1, l, -r);
            }
            else {
                printf("%d\n", query(1, l, r));
            }
        }
    }
    return 0;
}