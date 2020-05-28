// POJ-2352
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 32004;

int n, ans[N];
struct segtree {
  int l, r;
  int val;
  int lazy;
} tree[N << 2];

struct star {
  int x, y;
  bool operator<(const star &rhs) const {
    if (x == rhs.x)
      return y < rhs.y;
    return x < rhs.x;
  }
} a[N];

void pushup(int rt) {
  // do sth.
  tree[rt].val = tree[rt << 1].val + tree[rt << 1 | 1].val;
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
  scanf("%d", &n);
  build(1, 1, 32001);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].x++;
    a[i].y++;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[query(1, 1, a[i].y)]++;
    update(1, a[i].y, 1);
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
