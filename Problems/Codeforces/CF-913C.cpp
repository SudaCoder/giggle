//913C
#include <bits/stdc++.h>
using namespace std;

int n, L;

int dp[31], c[31];
long long ans = 1e18, tmp;

int main() {
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    dp[0] = c[1];
    for (int i = 1; i < n; ++i) {
        dp[i] = min(2 * dp[i - 1], c[i + 1]);
        if ((1 << i) >= L) ans = min(ans, 1LL * dp[i]);
    }
    dp[n] = 2 * dp[n - 1];
    int cnt = L / (1 << n);
    L %= (1 << n);
    for (int i = 0; i < n; ++i) {
        if (L >> i & 1)
            tmp += dp[i];
        tmp = min(tmp, 1LL * dp[i + 1]);
    }
    tmp += 1LL * dp[n] * cnt;
    ans = min(ans, tmp);
    printf("%lld\n", ans);
    return 0;
}