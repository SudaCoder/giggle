#include <cstdio>

using namespace std;
long long n, ans;

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b, long long c) {
  long long ans = a / gcd(a, b) * b;
  ans = ans / gcd(ans, c) * c;
  return ans;
}

long long max(long long a, long long b) {
  return a > b ? a : b;
}

int main () {
  scanf("%lld", &n);
  ans = 0;
  long long s = max(1, n - 100);
  for (long long i = s; i <= n; i++) {
    for (long long j = i; j <= n; j++) {
      for (long long k = j; k <= n; k++) {
        ans = max(ans, lcm(i, j, k));
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}