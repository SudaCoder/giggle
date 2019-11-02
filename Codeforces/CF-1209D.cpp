#include <bits/stdc++.h>
using ll = long long;
const int N = 1e5 + 9;
using namespace std;
int n, k, x, y;
int fa[N];

void init() {
  for (int i = 1; i <= n; i++)
    fa[i] = i;
}

int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }

void Union(int x, int y) { fa[Find(x)] = Find(y); }

int main() {
  scanf("%d%d", &n, &k);
  init();
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x, &y);
    Union(x, y);
  }
  int ans = k - n;
  for (int i = 1; i <= n; i++) {
    if (Find(i) == i) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}