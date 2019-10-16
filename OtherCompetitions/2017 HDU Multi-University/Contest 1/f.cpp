#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

long long qp(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int n, m, a[N], b[N], vis[N], cas = 0;

int cnta[N], cntb[N], ans;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        ans = 1;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i)
            scanf("%d", &b[i]);
        memset(cnta, 0, sizeof(int) * (n + 8));
        memset(cntb, 0, sizeof(int) * (m + 8));
        memset(vis, 0, sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            if (vis[i])
                continue;
            vis[i] = 1;
            int cnt = 1, p = a[i];
            while (p != i) {
                cnt++;
                vis[p] = 1;
                p = a[p];
            }
            cnta[cnt]++;
        }
        memset(vis, 0, sizeof(int) * m);
        for (int i = 0; i < m; ++i) {
            if (vis[i])
                continue;
            vis[i] = 1;
            int cnt = 1, p = b[i];
            while (p != i) {
                cnt++;
                vis[p] = 1;
                p = b[p];
            }
            cntb[cnt]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (!cnta[i])
                continue;
            int tot = 0;
            for (int j = 1; j <= i; ++j) {
                if (i % j == 0)
                    tot += j * cntb[j];
            }
            ans = 1LL * ans * qp(tot, cnta[i]) % mod;
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}