#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int g[N][N], n;
long long dp[10 + (1 << 24)];
char mp[N][N];

int main() {
  // reverse the matrix, left bottom -> right top, the result will not change
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i)
      scanf("%s", mp[i]);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &g[i][j]);
      }
    }
    int t = 1 << (2 * n);
    for (int i = 0; i <= t; ++i)
      dp[i] = 1e18;
    // down 1
    // right 0
    // delete 10 -> 01
    // 111111000000->000000111111
    dp[t - (1 << n)] = 0;
    vector<pair<int, pair<int, int>>> B, W;
    for (int s = t - (1 << n); s; --s) {
      if (__builtin_popcount(s) != n)
        continue;
      int x = 0, y = 0;
      B.clear();
      W.clear();
      for (int i = 0; i < 2 * n - 1; ++i) {
        if (!(s & (1 << i)) && (s & (1 << (i + 1)))) {
          dp[s ^ (3 << i)] = min(dp[s ^ (3 << i)], dp[s] + g[x][y]);
          if (mp[x][y] == 'B')
            B.push_back(make_pair(i, make_pair(x, y)));
          if (mp[x][y] == 'W')
            W.push_back(make_pair(i, make_pair(x, y)));
        }
        if (s >> i & 1)
          x++;
        else
          y++;
      }
      for (auto b : B) {
        for (auto w : W) {
          dp[s ^ (3 << b.first) ^ (3 << w.first)] =
              min(dp[s ^ (3 << b.first) ^ (3 << w.first)],
                  dp[s] + abs(g[b.second.first][b.second.second] -
                              g[w.second.first][w.second.second]));
        }
      }
    }
    printf("%lld\n", dp[(1 << n) - 1]);
  }
  return 0;
}