// 814C
#include <bits/stdc++.h>
using namespace std;

const int N = 1510;

int n, q, m;
char s[N], c[10];
int ans[26][N];

int main() {
  scanf("%d%s", &n, s);
  for (int c = 0; c < 26; ++c) {
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = i; j < n; ++j) {
        if (s[j] - 'a' != c)
          ++cnt;
        ans[c][cnt] = max(ans[c][cnt], j - i + 1);
      }
    }
    for (int i = 1; i < N; ++i)
      ans[c][i] = std::max(ans[c][i], ans[c][i - 1]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %s", &m, c);
    printf("%d\n", ans[c[0] - 'a'][m]);
  }
  return 0;
}