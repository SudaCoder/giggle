// 1061C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int n, a[N], cnt[N], ans = 0;

int main() {
  scanf("%d", &n);
  cnt[0] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    vector<int> cur;
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        cur.push_back(j);
        if (j != a[i] / j)
          cur.push_back(a[i] / j);
      }
    }
    sort(cur.begin(), cur.end());
    for (int i = cur.size() - 1; i >= 0; --i) {
      int it = cur[i];
      cnt[it] += cnt[it - 1];
      cnt[it] %= mod;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans = (ans + cnt[i]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}