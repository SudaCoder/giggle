// 837B
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
char s[N][N];
char s2[N][N];

int check(int n, int m) {
  if (n % 3 != 0) {
    return 0;
  }
  int d = n / 3;
  if (s[0][0] == s[d][0] || s[0][0] == s[2 * d][0] || s[d][0] == s[2 * d][0]) {
    return 0;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (s[i][j] != s[(i / d) * d][0])
        return 0;
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  if (check(n, m)) {
    puts("YES");
  } else {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        s2[j][i] = s[i][j];
    swap(n, m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        s[i][j] = s2[i][j];
    if (check(n, m)) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}