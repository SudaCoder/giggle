// 1096(HDU-2838)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], n;
long long ans = 0;
struct segtree {
  int l, r;
  int val;
  long long sum;
  int lazy;
} tree[N << 2];

void pushup(int rt) {
  tree[rt].val = tree[rt << 1].val + tree[rt << 1 | 1].val;
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  // do sth.
}

void pushdown(int rt) {
  // do sth.
}

void build(int rt, int l, int r) {
  tree[rt].l = l;
  tree[rt].r = r;
  // tree[rt].lazy = 0;
  if (l == r) {
    tree[rt].val = 0;
    tree[rt].sum = 0;
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

long long query1(int rt, int ql, int qr) {
  if (ql == tree[rt].l && qr == tree[rt].r)
    return tree[rt].sum;
  int mid = tree[rt].l + tree[rt].r >> 1;
  pushdown(rt);
  if (qr <= mid)
    return query1(rt << 1, ql, qr);
  else if (ql > mid)
    return query1(rt << 1 | 1, ql, qr);
  else
    return query1(rt << 1, ql, mid) + query1(rt << 1 | 1, mid + 1, qr); //
}

void update(int rt, int pos, int val) {
  if (tree[rt].l == tree[rt].r) {
    tree[rt].val += val;
    tree[rt].sum += tree[rt].l;
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
  scanf("%d", &n);
  build(1, 1, 100000);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] != 100000) {
      ans += 1LL * query(1, a[i] + 1, 100000) * a[i];
      ans += query1(1, a[i] + 1, 100000);
    }
    update(1, a[i], 1);
  }
  printf("%lld\n", ans);
  return 0;
}
