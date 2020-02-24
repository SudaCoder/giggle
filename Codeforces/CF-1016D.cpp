#include <cstdio>
#define ll long long
const int N = 1e3;
using namespace std;
int n, m;
ll a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  ll row = 0, col = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    row ^= a[i];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &b[i]);
    col ^= b[i];
  }
  if (row != col)
    return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      printf("0 ");
    }
    printf("%lld\n", a[i]);
  }
  for (int i = 1; i < m; i++) {
    printf("%lld ", b[i]);
  }
  printf("%lld\n", row ^ a[n] ^ b[m]);
  return 0;
}