// POJ-2528
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], vis[N], T, n, m, val[N], ans;
struct segtree {
  int l, r;
  int val;
  int lazy;
} tree[N << 2];

void pushup(int rt) {
  // do sth.
}

void pushdown(int rt) {
  if (tree[rt].lazy != 0) {
    tree[rt << 1].lazy = tree[rt].lazy;
    tree[rt << 1 | 1].lazy = tree[rt].lazy;
    tree[rt << 1].val = tree[rt].lazy;
    tree[rt << 1 | 1].val = tree[rt].lazy;
    tree[rt].lazy = 0;
  }
}

void build(int rt, int l, int r) {
  tree[rt].l = l;
  tree[rt].r = r;
  tree[rt].lazy = 0;
  if (l == r) {
    tree[rt].val = 0;
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}

void query(int rt) {
  if (tree[rt].l == tree[rt].r) {
    ans += vis[tree[rt].val] == 0;
    vis[tree[rt].val] = 1;
    return;
  }
  pushdown(rt);
  query(rt << 1);
  query(rt << 1 | 1);
}

void update(int rt, int ql, int qr, int val) {
  if (ql == tree[rt].l && qr == tree[rt].r) {
    tree[rt].val = val;
    tree[rt].lazy = val;
    return;
  }
  int mid = tree[rt].l + tree[rt].r >> 1;
  pushdown(rt);
  if (qr <= mid)
    update(rt << 1, ql, qr, val);
  else if (ql > mid)
    update(rt << 1 | 1, ql, qr, val);
  else {
    update(rt << 1, ql, mid, val);
    update(rt << 1 | 1, mid + 1, qr, val);
  }
  pushup(rt);
}

int main() {
  scanf("%d", &T);
  vis[0] = 1;
  while (T--) {
    scanf("%d", &n);
    m = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      val[++m] = a[i];
      val[++m] = b[i];
      val[++m] = b[i] + 1;
      vis[i] = 0;
    }
    sort(val + 1, val + m + 1);
    m = unique(val + 1, val + m + 1) - val - 1;
    build(1, 1, m);
    for (int i = 1; i <= n; ++i) {
      a[i] = lower_bound(val + 1, val + m + 1, a[i]) - val;
      b[i] = lower_bound(val + 1, val + m + 1, b[i]) - val;
      update(1, a[i], b[i], i);
    }
    ans = 0;
    query(1);
    printf("%d\n", ans);
  }
  return 0;
}
