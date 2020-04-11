// 816B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, k, q, l, r;
int b[N], sum[N];

int main() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &l, &r);
    b[l]++;
    b[r + 1]--;
  }
  int tot = 0;
  for (int i = 1; i <= 200000; ++i) {
    tot += b[i];
    sum[i] = sum[i - 1];
    if (tot >= k)
      sum[i]++;
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    printf("%d\n", sum[r] - sum[l - 1]);
  }
  return 0;
}