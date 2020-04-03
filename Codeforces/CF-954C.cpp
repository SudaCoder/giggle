// 954C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], y;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i != 1) {
      int delta = abs(a[i] - a[i - 1]);
      if (delta != 1) {
        if ((y != 0 && y != delta) || delta == 0) {
          puts("NO");
          return 0;
        }
        y = delta;
      }
    }
  }
  if (y == 0) {
    puts("YES");
    puts("1 1000000000");
    return 0;
  }
  for (int i = 2; i <= n; ++i) {
    int delta = abs(a[i] - a[i - 1]);
    if (delta == 1) {
      if (min(a[i], a[i - 1]) % y == 0 && max(a[i], a[i - 1]) % y == 1) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  printf("1000000000 %d\n", y);
  return 0;
}