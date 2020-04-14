// 1200B
#include <bits/stdc++.h>
using namespace std;

int T, n, m, k;

int h[110];

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
      cin >> h[i];
    bool flag = true;
    for (int i = 1; i < n; ++i) {
      int d = max(0, h[i + 1] - k);
      if (d > h[i] + m) {
        flag = false;
        break;
      }
      m += h[i] - d;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}