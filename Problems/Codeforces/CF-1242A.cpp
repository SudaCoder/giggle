#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
ll n;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  scanf("%lld", &n);
  if (n == 1) {
    return puts("1"), 0;
  }
  vector<ll> d;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      d.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1)
    d.push_back(n);
  ll ans = d[0];
  for (int i = 1; i < d.size(); i++) {
    ans = gcd(ans, d[i]);
  }
  printf("%lld\n", ans);
  return 0;
}