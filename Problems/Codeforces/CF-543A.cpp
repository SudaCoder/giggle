#include <bits/stdc++.h>
using ll = long long;
const int N = 666;
using namespace std;
int n, m, b, mod;
int a[N], dp[N][N];
int main() {
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = a[i]; k <= b; k++) {
                dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= b; i++) {
        ans = (dp[m][i] + ans) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}