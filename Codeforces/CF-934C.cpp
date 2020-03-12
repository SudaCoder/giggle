//934C
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2010;
 
int cnt[N][2], dp[N][N][2], dp2[N][N][2], ans, n, a[N];
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		cnt[i][0] = cnt[i - 1][0];
		cnt[i][1] = cnt[i - 1][1];
		scanf("%d", &a[i]);
        a[i]--;
		cnt[i][a[i]]++;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			if(a[j] == 0) {
				dp[i][j][0] = dp[i][j - 1][0] + 1;
				dp[i][j][1] = dp[i][j - 1][1];
			}
			else {
				dp[i][j][0] = dp[i][j - 1][0];
				dp[i][j][1] = 1 + max(dp[i][j - 1][0], dp[i][j - 1][1]);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j; --j) {
			if(a[j] == 0) {
				dp2[i][j][0] = dp2[i][j + 1][0] + 1;
				dp2[i][j][1] = dp2[i][j + 1][1];
			}
			else {
				dp2[i][j][0] = dp2[i][j + 1][0];
				dp2[i][j][1] = 1 + max(dp2[i][j + 1][0], dp2[i][j + 1][1]);
			}
		}
	}
	ans = max(dp[1][n][0], dp[1][n][1]);
	for(int l = 1; l <= n; ++l) {
		for(int r = l + 1; r <= n; ++r) {
			ans = max(ans, cnt[r][0] + max(dp[r + 1][n][0], dp[r + 1][n][1]));
			ans = max(ans, cnt[l - 1][0] + max(dp2[r][l][0], dp2[r][l][1]) + cnt[n][1] - cnt[r][1]);
			ans = max(ans, max(dp[1][l][0], dp[1][l][1]) + cnt[n][1] - cnt[l - 1][1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}