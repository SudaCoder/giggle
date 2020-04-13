#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
using ll = long long;
int Tcase, n, deg[N], dp[N], ans;
vector<int> g[N];
void init() {
    ans = 0;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        deg[i] = 0;
    }
}

void dfs(int u, int fa) {
    dp[u] = deg[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        ans = max(ans, dp[u] + dp[v]);
        dp[u] = max(dp[u], dp[v] + deg[u] - 1);
    }
}

int main() {
    scanf("%d", &Tcase);
    while (Tcase--) {
        init();
        scanf("%d", &n);
        int a, b;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        dfs(1, 0);
        printf("%d\n", ans);
    }
}
