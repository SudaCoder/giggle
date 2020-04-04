//1032C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int dp[N][6], a[N], b[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            for (int j = 1; j <= 5; ++j) {
                if (dp[i - 1][j] == 1) {
                    for (int k = 1; k <= 5; ++k) {
                        if (j == k) continue;
                        dp[i][k] = 1;
                    }
                }
            }
        }
        else if (a[i] > a[i - 1]) {
            for (int j = 1; j <= 5; ++j) {
                if (dp[i - 1][j] == 1)
                    for (int k = j + 1; k <= 5; ++k) {
                        dp[i][k] = 1;
                    }
            }
        }
        else {
            for (int j = 1; j <= 5; ++j) {
                if (dp[i - 1][j] == 1)
                    for (int k = 1; k < j; ++k) {
                        dp[i][k] = 1;
                    }
            }
        }
    }
    int last = 0;
    for (int j = 1; j <= 5; ++j)
        if (dp[n][j] == 1)
            last = j;
    if (last == 0) {
        puts("-1");
        return 0;
    }
    for (int i = n; i > 0; --i) {
        b[i] = last;
        if (i == 1) break;
        if (a[i] == a[i - 1]) {
            for (int j = 1; j <= 5; ++j) {
                if (j != last && dp[i - 1][j] == 1) {
                    last = j;
                    break;
                }
            }
        }
        else if (a[i] > a[i - 1]) {
            for (int j = 1; j < last; ++j) {
                if (dp[i - 1][j] == 1) {
                    last = j;
                    break;
                }
            }
        }
        else {
            for (int j = last + 1; j <= 5; ++j) {
                if (dp[i - 1][j] == 1) {
                    last = j;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", b[i], " \n"[i == n]);
    }
    return 0;
}