// 1077C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

map<int, int> cnt;

int n, a[N], vis[N], ans;
long long sum;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; ++i) {
    long long temp = sum - a[i];
    if (temp % 2 == 1 || temp > 2000000)
      continue;
    temp /= 2;
    if ((a[i] != temp && cnt[temp] != 0) || cnt[temp] >= 2) {
      vis[i] = 1;
      ans++;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    if (vis[i])
      printf("%d ", i);
  }
  return 0;
}