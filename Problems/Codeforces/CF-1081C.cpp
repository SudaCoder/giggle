//1081C
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 998244353;

int n, m, k, dp[N][N];

int main() {
    cin >> n >> m >> k;
    dp[1][0] = m;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j != 0)
                dp[i][j] = (dp[i][j] + 1LL * (m - 1) * dp[i - 1][j - 1]) % mod;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}