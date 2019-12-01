#include <cstdio>
#include <iostream>
#include <utility>
#include <unordered_map>
using ll = long long;
using namespace std;
const int MX = 1e5+9;
int n, k, x;
unordered_map<int, int> mp;

pair<int, int> trans(int x) {
  int a = 1, b = 1, cnt;
  for (int i = 2; i * i <= x; i++) {
    cnt = 0;
    while(x % i == 0) {
      cnt ++; x /= i;
    }
    cnt %= k;
    if (cnt) {
      for (int j = 0; j < cnt; j++) {
        a *= i;
      }
      for (int j = cnt; j < k; j++) {
        b *= i;
      }
    }
  }
  if (x > 1) {
    a *= x;
    for (int j = 1; j < k && b <= MX; j++) {
      b *= x;
    }
  }
  if (b >= MX) b = -1;
  return make_pair(a, b);
}

int main() {
  scanf("%d %d", &n, &k);
  ll ans = 0;
  for (int i = 0 ; i < n; i++) {
    scanf("%d", &x);
    pair<int, int> ab = trans(x);
    ans += mp[ab.first];
    if (ab.second > 0)
      mp[ab.second]++;
  }
  printf("%lld\n", ans);
  return 0;
}