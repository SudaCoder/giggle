// POJ-3264
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

int a[N], n, m;
struct segtree {
  int l, r;
  int val[2];
  int lazy;
} tree[N << 2];

void pushup(int rt) {
  // do sth.
  tree[rt].val[0] = min(tree[rt << 1].val[0], tree[rt << 1 | 1].val[0]);
  tree[rt].val[1] = max(tree[rt << 1].val[1], tree[rt << 1 | 1].val[1]);
}

void pushdown(int rt) {
  // do sth.
}

void build(int rt, int l, int r) {
  tree[rt].l = l;
  tree[rt].r = r;
  // tree[rt].lazy = 0;
  if (l == r) {
    tree[rt].val[0] = a[l];
    tree[rt].val[1] = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}

int query(int rt, int ql, int qr) {
  if (ql == tree[rt].l && qr == tree[rt].r)
    return tree[rt].val[0];
  int mid = tree[rt].l + tree[rt].r >> 1;
  pushdown(rt);
  if (qr <= mid)
    return query(rt << 1, ql, qr);
  else if (ql > mid)
    return query(rt << 1 | 1, ql, qr);
  else
    return min(query(rt << 1, ql, mid), query(rt << 1 | 1, mid + 1, qr)); //
}

int query1(int rt, int ql, int qr) {
  if (ql == tree[rt].l && qr == tree[rt].r)
    return tree[rt].val[1];
  int mid = tree[rt].l + tree[rt].r >> 1;
  pushdown(rt);
  if (qr <= mid)
    return query1(rt << 1, ql, qr);
  else if (ql > mid)
    return query1(rt << 1 | 1, ql, qr);
  else
    return max(query1(rt << 1, ql, mid), query1(rt << 1 | 1, mid + 1, qr)); //
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  build(1, 1, n);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query1(1, l, r) - query(1, l, r));
  }
  return 0;
}