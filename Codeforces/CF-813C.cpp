#include <cstdio>
#include <iostream>
#include <vector>

const int N = 2e5+9;
using namespace std;
int n, x, dep[N], lev[N];
vector<int> mp[N];
bool vis[N];

int dfs(int u, int fa) {
    int ans = 0;
    if (u == x) vis[u] = 1;
    for (int i = 0; i < mp[u].size(); i++) {
        int v = mp[u][i];
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        ans = max(dfs(v, u)+1, ans);
        vis[u] |= vis[v];
    }
    return lev[u]=ans;
}

int main() {
    scanf("%d%d", &n, &x);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[i] >= 1+dep[x]/2 && vis[i]) {
            ans = max(ans, lev[i] + dep[i]);
        }
    }
    printf("%d\n", ans<<1);
    return 0;
}