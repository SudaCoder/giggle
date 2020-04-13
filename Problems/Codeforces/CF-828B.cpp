// 828B
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
char s[N][N];
int n, m, minx = 100, maxx, miny = 100, maxy, cnt;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == 'B') {
        cnt++;
        maxx = max(maxx, i);
        minx = min(minx, i);
        maxy = max(maxy, j);
        miny = min(miny, j);
      }
    }
  }
  if (cnt == 0) {
    puts("1");
    return 0;
  }
  int len = max(maxx - minx + 1, maxy - miny + 1);
  if (len > n || len > m) {
    puts("-1");
    return 0;
  }
  printf("%d\n", len * len - cnt);
  return 0;
}