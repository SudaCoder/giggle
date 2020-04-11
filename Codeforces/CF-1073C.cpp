// 1073C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

char s[N];

int n, x, y, sumx[N], sumy[N], ans;

bool judge(int len) {
  for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
    // 1...i-1, i...j, j+1...n
    int dx = sumx[i - 1] - sumx[0] + sumx[n] - sumx[j];
    int dy = sumy[i - 1] - sumy[0] + sumy[n] - sumy[j];
    if (len >= abs(dx - x) + abs(dy - y))
      return true;
  }
  return false;
}

int main() {
  scanf("%d%s%d%d", &n, s + 1, &x, &y);
  if (n < abs(x) + abs(y) || (n - x - y) % 2 == 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    sumx[i] = sumx[i - 1];
    sumy[i] = sumy[i - 1];
    if (s[i] == 'R')
      sumx[i]++;
    else if (s[i] == 'L')
      sumx[i]--;
    else if (s[i] == 'U')
      sumy[i]++;
    else if (s[i] == 'D')
      sumy[i]--;
  }
  int l = 0, r = n;
  while (l <= r) {
    int mid = l + r >> 1;
    if (judge(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}