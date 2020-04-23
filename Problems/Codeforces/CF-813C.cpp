//813C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> edge[N];

int n, x, dep[N], maxdep[N], ans, fa[N];

void dfs(int rt, int pre, int d) {
    dep[rt] = maxdep[rt] = d;
    fa[rt] = pre;
    for (int i = 0; i < edge[rt].size(); ++i) {
        int j = edge[rt][i];
        if (j == pre) continue;
        dfs(j, rt, d + 1);
        maxdep[rt] = max(maxdep[rt], maxdep[j]);
    }
}

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0, 0);
    int p = x;
    while (dep[x] - dep[p] < dep[p]) {
        ans = max(ans, maxdep[p]);
        p = fa[p];
    }
    printf("%d\n", 2 * ans);
    return 0;
}