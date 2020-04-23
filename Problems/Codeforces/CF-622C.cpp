// 622C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N], fa[N];
int l, r, x;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == a[i - 1])
      fa[i] = fa[i - 1];
    else
      fa[i] = i;
  }
  while (m--) {
    scanf("%d%d%d", &l, &r, &x);
    if (fa[l] == fa[r]) {
      if (a[l] == x)
        puts("-1");
      else
        printf("%d\n", l);
    } else {
      if (a[l] != x)
        printf("%d\n", l);
      else if (a[r] != x)
        printf("%d\n", r);
      else
        printf("%d\n", fa[r] - 1);
    }
  }
  return 0;
}