// 1073D
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long T, ans;
int n, a[N], mn = 1e9;

void get(long long T, long long &tot, int &cnt) {
  tot = 0;
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (T >= a[i]) {
      T -= a[i];
      tot += a[i];
      cnt++;
    }
  }
}

int main() {
  scanf("%d%lld", &n, &T);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mn = min(mn, a[i]);
  }
  while (T >= mn) {
    long long tot;
    int cnt;
    get(T, tot, cnt);
    ans += (T / tot) * cnt;
    T %= tot;
  }
  printf("%lld\n", ans);
  return 0;
}