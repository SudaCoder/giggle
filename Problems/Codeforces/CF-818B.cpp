// 818B
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m, l[N], a[N], pos[N], flag;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d", &l[i]);
  for (int i = 1; i < m; ++i) {
    int x = l[i + 1] - l[i];
    if (x <= 0)
      x += n;
    if (pos[x] != 0 && pos[x] != l[i]) {
      flag = 1;
      break;
    }
    if (a[l[i]] != 0 && a[l[i]] != x) {
      flag = 1;
      break;
    }
    pos[x] = l[i];
    a[l[i]] = x;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      for (int j = 1; j <= n; ++j) {
        if (pos[j] == 0) {
          pos[j] = i;
          a[i] = j;
          break;
        }
      }
    }
  }
  if (flag == 1) {
    puts("-1");
  } else {
    for (int i = 1; i <= n; ++i)
      printf("%d ", a[i]);
    puts("");
  }
  return 0;
}