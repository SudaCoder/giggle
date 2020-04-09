//1006E
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, q;
int dfn[N], maxson[N], p[N], cnt, pos[N];
vector<int> edge[N];

void dfs(int root, int pre) {
    dfn[root] = ++cnt;
    pos[cnt] = root;
    for (int i = 0; i < edge[root].size(); ++i) {
        dfs(edge[root][i], root);
    }
    maxson[root] = cnt;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i]);
        edge[p[i]].push_back(i);
    }
    dfs(1, 0);
    while (q--) {
        int u, k;
        scanf("%d%d", &u, &k);
        k--;
        printf("%d\n", dfn[u] + k <= maxson[u] ? pos[dfn[u] + k] : -1);
    }
    return 0;
}