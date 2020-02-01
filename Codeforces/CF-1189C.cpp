#include <cstdio>
const int N = 1e5+9;
using namespace std;
int a[N];
int main() {
  int n, q, l, r; scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]); a[i] += a[i-1];
  }
  scanf("%d", &q);
  while(q--) {
    scanf("%d %d", &l, &r);
    printf("%d\n", (a[r] - a[l-1])/10);
  }
  return 0;
}