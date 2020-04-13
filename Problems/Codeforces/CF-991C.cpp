// 991C
#include <bits/stdc++.h>
using namespace std;

long long n;

bool check(long long k) {
  long long now = n, tot = 0;
  while (now) {
    tot += min(k, now);
    now -= min(k, now);
    now -= now / 10;
  }
  return tot * 2 >= n;
}

int main() {
  cin >> n;
  long long l = 1, r = n, ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}