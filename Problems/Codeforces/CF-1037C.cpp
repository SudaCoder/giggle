// 1037C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, ans;

char s[2][N];

int main() {
  scanf("%d%s%s", &n, s[0], s[1]);
  for (int i = 0; i < n; ++i) {
    if (s[0][i] == s[1][i])
      continue;
    if (i == n - 1) {
      ans++;
      continue;
    }
    if (s[0][i + 1] == s[1][i + 1] || s[0][i] == s[0][i + 1]) {
      ans++;
      continue;
    }
    ans++;
    i++;
  }
  printf("%d\n", ans);
  return 0;
}