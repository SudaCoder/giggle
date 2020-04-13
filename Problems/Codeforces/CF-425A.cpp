#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int N = 1e3 + 9;
const int K = 11;
int n, k, a[N];
ll dp[N][3][K][K];
bool vis[N][3][K][K];
const ll INF = 1LL << 60;

ll solve(int idx, int st, int up, int dw) {
    if (idx == n) {
        if (up == dw && st) {
            return 0;
        } else
            return -INF;
    }
    if (vis[idx][st][up][dw]) {
        return dp[idx][st][up][dw];
    }
    ll ret = -INF;
    if (st == 0) {
        ret = max(solve(idx + 1, 1, up, dw) + a[idx], solve(idx + 1, 0, up, dw));
        ret = max(ret, solve(idx + 1, 1, up + 1, dw));
        if (dw < k) {
            ret = max(ret, solve(idx + 1, 0, up, dw + 1) + a[idx]);
        }
    } else if (st == 1) {
        ret = max(solve(idx + 1, 1, up, dw) + a[idx], solve(idx + 1, 2, up, dw));
        if (up < k) {
            ret = max(ret, solve(idx + 1, 1, up + 1, dw));
        }
    } else if (st == 2) {
        ret = solve(idx + 1, 2, up, dw);
        if (dw < k) {
            ret = max(ret, solve(idx + 1, 2, up, dw + 1) + a[idx]);
        }
    }
    vis[idx][st][up][dw] = 1;
    return dp[idx][st][up][dw] = ret;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    printf("%lld\n", solve(0, 0, 0, 0));
    return 0;
}