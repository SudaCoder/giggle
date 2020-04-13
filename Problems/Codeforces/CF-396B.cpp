#include <cstdio>

using namespace std;

bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 1;
    }
  }
  return 0;
}

long long ___gcd(long long a, long long b) { return b ? ___gcd(b, a % b) : a; }

int t, x;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &x);
    int p = x, q = x + 1;
    for (; isPrime(p); p--)
      ;
    for (; isPrime(q); q++)
      ;
    long long up = 1LL * p * q - 2LL * (p + q) + 2 + 2LL * x;
    long long down = 2LL * p * q;
    long long gcd = ___gcd(up, down);
    printf("%lld/%lld\n", up / gcd, down / gcd);
  }
  return 0;
}