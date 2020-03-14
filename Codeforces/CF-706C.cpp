//706C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long dp[N][2];
const long long inf = 0x3f3f3f3f3f3f3f3f;
string s[N][2];
int n, c[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i) { 
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    dp[1][1] = c[1];
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1][0] <= s[i][0]) 
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i - 1][1] <= s[i][0])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (s[i - 1][0] <= s[i][1]) 
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (s[i - 1][1] <= s[i][1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }
    long long ans = min(dp[n][0], dp[n][1]);
    if (ans == inf) 
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}