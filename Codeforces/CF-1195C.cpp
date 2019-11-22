#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5 + 9;
using namespace std;
int n, a[N], b[N];
long long dp[N][2];
int main() {
  scanf("%d", &n);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i]);
  }
  printf("%lld\n", max(dp[n][0], dp[n][1]));
  return 0;
}