//729C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct car {
    int c, v;
    bool operator<(const car &rhs) const {
        return c < rhs.c;
    }
} a[N];

int n, k, s, t;
int g[N];

bool check(int v) {
    int time = 0;
    for (int i = 1; i < k; ++i) {
        int d = g[i + 1] - g[i];
        if (d > v) return 0;
        time += max(d, 2 * d - (v - d));
    }
    return time <= t;
}

int main() {
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].c, &a[i].v);
    }
    for (int i = 1; i <= k; ++i)
        scanf("%d", &g[i]);
    g[++k] = 0;
    g[++k] = s;
    sort(g + 1, g + k + 1);
    int l = 0, r = 1e9, minv = 2e9;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            minv = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    int ans = 2e9;
    for (int i = 1; i <= n; ++i) {
        if (a[i].v >= minv) {
            ans = min(ans, a[i].c);
        }
    }
    if (ans == 2e9) ans = -1;
    printf("%d\n", ans);
    return 0;
}