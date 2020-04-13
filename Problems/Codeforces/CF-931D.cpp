// CF931D
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

vector<int> edge[N];
int cnt[N];

void dfs(int u, int dep) {
    cnt[dep]++;
    for (int i = 0; i < edge[u].size(); ++i) {
        dfs(edge[u][i], dep + 1);
    }
}

int main() {
    int n, t, ans = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &t);
        edge[t].push_back(i);
    }
    dfs(1, 0);
    for (int i = 0; i < n; ++i)
        ans += cnt[i] % 2;
    printf("%d\n", ans);
    return 0;
}