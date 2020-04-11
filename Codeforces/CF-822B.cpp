// 822B
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m, ans = 1e9, pos = -1;
char s[N], t[N];

int main() {
  scanf("%d%d%s%s", &n, &m, s, t);
  for (int i = 0; i + n - 1 < m; ++i) {
    int temp = 0;
    for (int j = 0; j < n; ++j) {
      if (s[j] != t[i + j])
        temp++;
    }
    if (temp < ans) {
      ans = temp;
      pos = i;
    }
  }
  printf("%d\n", ans);
  for (int j = 0; j < n; ++j) {
    if (s[j] != t[pos + j])
      printf("%d ", j + 1);
  }
  puts("");
  return 0;
}