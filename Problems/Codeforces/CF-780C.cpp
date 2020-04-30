//780C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int c[N], D, n;
vector<int> edge[N];

void dfs(int rt, int fa) {
    int x = c[rt], y = c[fa], k = 1;
    for (int i = 0; i < edge[rt].size(); ++i) {
        int j = edge[rt][i];
        if (j == fa) continue;
        while (k == x || k == y) k++;
        c[j] = k;
        k++;
        dfs(j, rt);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        D = max(D, (int)edge[i].size());
    c[1] = 1;
    dfs(1, 0);
    printf("%d\n", D + 1);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", c[i], " \n"[i == n]);
    return 0;
}