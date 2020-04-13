//467C
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, m, k;
int a[N];
long long dp[N][N], s[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (i >= m && j >= 1)
                dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + s[i] - s[i - m]);
        }
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}