// 729C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct car {
  int c, v;
  bool operator<(const car &rhs) const { return c < rhs.c; }
} a[N];

int n, k, s, t;
int g[N];

bool check(int mid) {
  int v = a[mid].v, time = 0;
  for (int i = 1; i < k; ++i) {
    int d = g[i + 1] - g[i];
    if (d > v)
      return 0;
    time += max(d, 2 * d - (v - d));
  }
  return time <= t;
}

int main() {
  scanf("%d%d%d%d", &n, &k, &s, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].c, &a[i].v);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].v = max(a[i].v, a[i - 1].v);
  }
  for (int i = 1; i <= k; ++i)
    scanf("%d", &g[i]);
  g[++k] = 0;
  g[++k] = s;
  sort(g + 1, g + k + 1);
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = a[mid].c;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}