#include <cstdio>

const int N = 1e5+9;
using namespace std;
int n, deg[N];

int main() {
  scanf("%d", &n);   int u, v, flag = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    deg[u]++; deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 2) {
      flag = 1; break;
    }
  }
  puts(flag ? "NO" : "YES");
  return 0;
}